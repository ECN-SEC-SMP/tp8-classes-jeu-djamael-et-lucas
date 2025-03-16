#include "Plateau.h"  // Inclusion de la définition de la classe Plateau ainsi que des dépendances (classes Animal, Pierre, Lion, Loup, Ours)

/**
 * @brief Constructeur par défaut de la classe Plateau.
 *
 * Initialise le plateau avec les dimensions par défaut (MAXX_DEFAULT et MAXY_DEFAULT),
 * définit le nombre d'animaux à MAX_ANIMAUX_DEFAULT et alloue la grille avec des pointeurs null.
 */
Plateau::Plateau()
    : maxX(MAXX_DEFAULT), maxY(MAXY_DEFAULT), nombredAnimaux(MAX_ANIMAUX_DEFAULT),
      grille(MAXX_DEFAULT, vector<Animal *>(MAXY_DEFAULT, nullptr)) {}

/**
 * @brief Constructeur paramétré de la classe Plateau.
 *
 * Permet d'initialiser le plateau avec des dimensions spécifiques.
 * Le nombre d'animaux est initialisé à 25% du nombre total de cases.
 * La grille est allouée en fonction de _maxX et _maxY avec tous les pointeurs initialisés à nullptr.
 *
 * @param _maxX Nombre de colonnes du plateau.
 * @param _maxY Nombre de lignes du plateau.
 */
Plateau::Plateau(int _maxX, int _maxY)
    : maxX(_maxX), maxY(_maxY), nombredAnimaux((_maxX * _maxY) * 25 / 100),
      grille(_maxX, vector<Animal *>(_maxY, nullptr)) {}

/**
 * @brief Destructeur de la classe Plateau.
 *
 * Parcourt la grille et libère la mémoire de chaque animal alloué.
 * Ceci permet d'éviter les fuites mémoire lors de la destruction du plateau.
 */
Plateau::~Plateau() {
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            delete grille[i][j];  // Libération de la mémoire allouée pour chaque animal
        }
    }
}

// ============================
// MÉTHODES GETTERS
// ============================

/**
 * @brief Retourne le nombre de colonnes du plateau.
 *
 * @return La valeur de maxX.
 */
int Plateau::getMaxX() const { 
    return maxX; 
}

/**
 * @brief Retourne le nombre de lignes du plateau.
 *
 * @return La valeur de maxY.
 */
int Plateau::getMaxY() const { 
    return maxY; 
}

/**
 * @brief Retourne le nombre d'animaux initialement présents sur le plateau.
 *
 * @return La valeur de nombredAnimaux.
 */
int Plateau::getNombreAnimaux() const { 
    return nombredAnimaux; 
}

/**
 * @brief Retourne la grille du plateau.
 *
 * La méthode retourne une copie de la grille (tableau 2D de pointeurs vers Animal)
 * afin de préserver l'encapsulation de la classe.
 *
 * @return La grille actuelle du plateau.
 */
vector<vector<Animal *>> Plateau::getGrille() const { 
    return grille; 
}

// ============================
// MÉTHODES SETTERS
// ============================

/**
 * @brief Met à jour la grille du plateau.
 *
 * Remplace l'ancienne grille par la nouvelle grille passée en paramètre.
 *
 * @param nouvelleGrille Nouvelle grille à affecter.
 */
void Plateau::setGrille(const vector<vector<Animal *>>& nouvelleGrille) {
    grille = nouvelleGrille;
}

/**
 * @brief Modifie la largeur du plateau.
 *
 * Redimensionne la grille en fonction de la nouvelle largeur (_maxX) tout en
 * préservant la hauteur existante et en initialisant les nouvelles cases avec nullptr.
 *
 * @param _maxX Nouvelle valeur pour le nombre de colonnes.
 */
void Plateau::setMaxX(int _maxX) {
    maxX = _maxX;
    grille.resize(maxX, vector<Animal *>(maxY, nullptr));
}

/**
 * @brief Modifie la hauteur du plateau.
 *
 * Redimensionne chaque ligne de la grille pour qu'elle contienne _maxY cases.
 * Les nouvelles cases sont initialisées avec nullptr.
 *
 * @param _maxY Nouvelle valeur pour le nombre de lignes.
 */
void Plateau::setMaxY(int _maxY) {
    maxY = _maxY;
    for (auto &row : grille) {
        row.resize(maxY, nullptr);
    }
}

/**
 * @brief Met à jour le nombre d'animaux du plateau.
 *
 * @param _nombre Nouvelle valeur pour le nombre d'animaux.
 */
void Plateau::setNombreAnimaux(int _nombre) {
    nombredAnimaux = _nombre;
}

// ============================
// MÉTHODES D'UTILITÉ
// ============================

/**
 * @brief Insère un animal sur le plateau.
 *
 * La méthode place l'animal dans une position libre de la grille.
 * Si la case est déjà occupée, l'animal est déplacé jusqu'à trouver une case libre.
 * Si aucune position libre n'est trouvée après avoir testé toutes les cases, un message
 * d'erreur est affiché.
 *
 * @param LAnimal Pointeur vers l'animal à insérer.
 */
void Plateau::insererAnimal(Animal *LAnimal) {
    int x = LAnimal->getX();
    int y = LAnimal->getY();
    // Ensemble pour stocker les positions déjà testées afin d'éviter des boucles infinies
    set<pair<int, int>> positionsTestees;

    // Tant que la case est occupée et qu'on n'a pas testé toutes les cases du plateau
    while (grille[x][y] != nullptr && positionsTestees.size() < (maxX * maxY)) {
        positionsTestees.insert({x, y});  // Marque la case actuelle comme testée
        LAnimal->deplace(maxX, maxY);       // Déplace l'animal pour obtenir une nouvelle position
        x = LAnimal->getX();
        y = LAnimal->getY();
    }

    // Si une case libre est trouvée, l'animal y est inséré
    if (grille[x][y] == nullptr) {
        grille[x][y] = LAnimal;
    } else {
        // Sinon, aucun emplacement libre n'a été trouvé pour cet animal
        cout << "Aucune position libre pour " << LAnimal->getNom() << endl;
    }
}

/**
 * @brief Remplit le plateau avec des animaux.
 *
 * La méthode crée une répartition égale d'animaux (Loup, Lion, Ours, Pierre) en
 * fonction du nombre total d'animaux (calculé à partir du pourcentage du plateau).
 * Chaque animal est ensuite inséré dans la grille via la méthode insererAnimal().
 */
void Plateau::remplir() {
    int repartition = nombredAnimaux / 4;  // Nombre d'animaux de chaque type
    vector<Animal *> Animaux;
    
    // Création d'animaux de chaque type et ajout dans le vecteur
    for (int i = 0; i < repartition; ++i) {
        Animaux.push_back(new Loup(maxX, maxY));
        Animaux.push_back(new Lion(maxX, maxY));
        Animaux.push_back(new Ours(maxX, maxY));
        Animaux.push_back(new Pierre(maxX, maxY));
    }

    // Insertion de chaque animal dans la grille
    for (Animal *animal : Animaux) {
        animal->setAttaque();
        insererAnimal(animal);
    }
}

/**
 * @brief Affiche le plateau.
 *
 * Affiche graphiquement le plateau sous forme de grille.
 * Chaque cellule affiche un identifiant (les 2 premières lettres du nom de l'animal)
 * si un animal vivant s'y trouve, sinon la cellule reste vide.
 */
void Plateau::afficher() {
    // Affiche la bordure supérieure du plateau
    for (int i = 0; i < maxX; i++) {
        cout << "|----";
    }
    cout << "|" << endl;

    // Affiche le contenu de chaque ligne
    for (int i = 0; i < maxY; i++) {
        // Parcours de chaque colonne pour afficher le contenu des cellules
        for (int j = 0; j < maxX; j++) {
            // Si la cellule contient un animal vivant, on affiche les 2 premières lettres de son nom
            if (grille[j][i] != nullptr && grille[j][i]->getVivant() == true) {
                cout << "| " << grille[j][i]->getNom().substr(0, 2) << " ";
            } else {
                // Sinon, la cellule est vide
                cout << "|    ";
            }
        }
        cout << "|" << endl;

        // Affiche la bordure inférieure de la ligne
        for (int j = 0; j < maxX; j++) {
            cout << "|----";
        }
        cout << "|" << endl;
    }
}

/**
 * @brief Affiche les positions des animaux sur le plateau.
 *
 * Parcourt la grille et, pour chaque animal vivant, affiche son nom ainsi que ses coordonnées (x, y).
 */
void Plateau::afficherPositions() {
    int totalAnimaux = 0;

    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            Animal* animal = grille[i][j];
            if (animal != nullptr && animal->getVivant())
            {
                cout << animal->getNom() << ": (" << animal->getX() << "; " << animal->getY() << ")" << endl;
            }
        }
    }
}
