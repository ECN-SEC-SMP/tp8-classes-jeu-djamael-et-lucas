#include "Jeu.h"          // Inclusion de la définition de la classe Jeu et de ses dépendances (notamment Plateau et Animal)
#include <iostream>       // Pour l'affichage via cout
#include <set>            // Pour utiliser std::set dans la vérification des types d'animaux
#include <cstdlib>        // Pour les fonctions rand() et srand()
#include <ctime>          // Pour initialiser le générateur de nombres aléatoires (time(NULL))
#include <limits>         // Pour std::numeric_limits

using namespace std;

/**
 * @brief Constructeur de la classe Jeu.
 *
 * Initialise le plateau avec les dimensions spécifiées, remplit le plateau d'animaux,
 * et initialise l'état de la partie (jeuEnCours=true et tour=0).
 *
 * @param maxX Largeur du plateau.
 * @param maxY Hauteur du plateau.
 */
Jeu::Jeu(int maxX, int maxY) : plateau(maxX, maxY) {
    plateau.remplir();    // Remplit le plateau avec les animaux (répartition égale entre les types)
    jeuEnCours = true;    // La partie commence en cours
    tour = 0;             // Le compteur de tour est initialisé à 0
}

/**
 * @brief Déplace tous les animaux du plateau.
 *
 * Parcourt la grille actuelle du plateau, fait se déplacer chaque animal vivant,
 * et stocke l'animal dans un vecteur 3D (dAnimaux) indexé par ses nouvelles coordonnées.
 * Chaque cellule (dAnimaux[newX][newY]) contiendra un vecteur d'animaux présents à cette position.
 *
 * @return Le vecteur 3D contenant les animaux par case après déplacement.
 */
std::vector<std::vector<std::vector<Animal*>>> Jeu::deplacerAnimaux() {
    // Récupération de la grille actuelle du plateau
    vector<vector<Animal*>> grille = plateau.getGrille();
    // Création d'un vecteur 3D pour stocker les animaux par case après déplacement.
    // La taille de la grille est définie par le nombre de colonnes (maxX) et de lignes (maxY)
    vector<vector<vector<Animal*>>> dAnimaux(plateau.getMaxX(), vector<vector<Animal*>>(plateau.getMaxY()));

    // Parcours de la grille actuelle
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            // Si une case contient un animal vivant, on le déplace
            if (animal != nullptr && animal->getVivant()) {
                int oldX = animal->getX(); // Sauvegarde de la position avant déplacement
                int oldY = animal->getY();
                // Appel de la méthode de déplacement propre à l'animal
                animal->deplace(plateau.getMaxX(), plateau.getMaxY());
                int newX = animal->getX(); // Récupération des nouvelles coordonnées
                int newY = animal->getY();
                // Affichage du déplacement effectué par l'animal
                cout << animal->getNom() << ": (" << oldX << ", " << oldY << ") -> (" 
                     << newX << ", " << newY << ")" << endl;
                // Stockage de l'animal dans le vecteur 3D à la nouvelle position
                dAnimaux[newX][newY].push_back(animal);
            }
        }
    }
    return dAnimaux;
}

/**
 * @brief Gère les conflits sur le plateau après déplacement.
 *
 * Parcourt le vecteur 3D d'animaux (dAnimaux)(Ce vecteur 3D permet de stocker plusieurs animaux dans une même case)
 *  et, pour chaque case contenant plus d'un animal,
 * fait se battre ces animaux pour ne conserver que le survivant. Après résolution, reconstruit la
 * grille du plateau afin qu'elle contienne au maximum un animal par case.
 *
 * @param dAnimaux Référence au vecteur 3D contenant les animaux par case après déplacement.
 */
void Jeu::gererConflits(vector<vector<vector<Animal*>>>& dAnimaux) {
    // Parcours de chaque cellule du vecteur 3D
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            // Récupération du vecteur d'animaux se trouvant en (i, j)
            vector<Animal*>& cellAnimaux = dAnimaux[i][j];
            // Si plus d'un animal se trouve sur la même case, on résout le conflit
            if (cellAnimaux.size() > 1) {
                cout << "Conflit en (" << i << ", " << j << ") : " 
                     << cellAnimaux.size() << " animaux s'affrontent." << endl;
                Animal* survivant = cellAnimaux[0];  // On considère le premier animal comme initialement le survivant
                // Chaque animal de la cellule affronte le survivant un par un
                for (size_t k = 1; k < cellAnimaux.size(); k++) {
                    cout << survivant->getNom() << " vs " << cellAnimaux[k]->getNom() << " :" << endl;
                    cout << "> " << survivant->getNom() << " attaque avec " 
                         << survivant->getAttaque().getNomAttaque() << endl;
                    cout << "> " << cellAnimaux[k]->getNom() << " attaque avec " 
                         << cellAnimaux[k]->getAttaque().getNomAttaque() << endl;
                    // Si le survivant perd contre l'adversaire
                    if (!survivant->attaque(*cellAnimaux[k])) {
                        cout << cellAnimaux[k]->getNom() << " gagne !" << endl;
                        survivant->setVivant(false);  // Marque le survivant comme mort
                        survivant = cellAnimaux[k];   // Le nouvel animal devient le survivant
                    } else {
                        cout << survivant->getNom() << " gagne !" << endl;
                        cellAnimaux[k]->setVivant(false);  // Marque l'adversaire comme mort
                    }
                }
                // Après le combat, on conserve uniquement le survivant dans la case
                cellAnimaux.clear();
                cellAnimaux.push_back(survivant);
            }
        }
    }
    // Reconstruction de la grille du plateau à partir du vecteur 3D
    vector<vector<Animal*>> nouvelleGrille(plateau.getMaxX(), vector<Animal*>(plateau.getMaxY(), nullptr));
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            if (!dAnimaux[i][j].empty()) {
                nouvelleGrille[i][j] = dAnimaux[i][j][0];  // Place le survivant dans la nouvelle grille
            }
        }
    }
    // Mise à jour de la grille du plateau avec la nouvelle grille
    plateau.setGrille(nouvelleGrille);
}

/**
 * @brief Affiche le nombre d'animaux vivants sur le plateau.
 *
 * Parcourt la grille du plateau et compte le nombre d'animaux vivants. Affiche un message
 * différent selon que c'est l'état initial du plateau ou après un tour.
 */
void Jeu::afficherNombreAnimaux() {
    int totalAnimaux = 0;
    // Récupère la grille actuelle
    vector<vector<Animal*>> grille = plateau.getGrille();
    // Parcours de chaque cellule de la grille
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            // Compte l'animal s'il existe et s'il est vivant
            if (animal != nullptr && animal->getVivant()) {
                totalAnimaux++;
            }
        }
    }
    // Affichage selon que c'est le tour initial ou non
    if (tour == 0) {
        cout << "\nÉtat initial du plateau : " << totalAnimaux << " animaux." << endl;
    } else {
        cout << "\nAprès le tour " << tour << " : " << totalAnimaux << " animaux restants." << endl;
    }
}

/**
 * @brief Lance un tour complet de la partie.
 *
 * Un tour inclut les étapes suivantes :
 * - Incrémenter le compteur de tour.
 * - Déplacer tous les animaux et stocker leurs nouvelles positions dans un vecteur 3D.
 * - Gérer les conflits (combats) sur chaque case.
 * - Afficher le plateau et le nombre d'animaux vivants.
 * - Vérifier les conditions d'arrêt de la partie (si un seul animal reste ou si tous sont de type "Pierre").
 */

void Jeu::lancerTour() {
    tour++;
    cout << "Début du tour " << tour << "..." << endl;
    
    // Déplacement de tous les animaux et stockage dans le vecteur 3D
    vector<vector<vector<Animal*>>> dAnimaux = deplacerAnimaux();
    
    // Mise à jour des attaques de tous les animaux vivants avant de gérer les conflits
    vector<vector<Animal*>> grille = plateau.getGrille();
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            if (grille[i][j] != nullptr && grille[i][j]->getVivant()) {
                grille[i][j]->setAttaque();
            }
        }
    }
    
    // Gestion des conflits dans chaque case où plusieurs animaux se rencontrent
    gererConflits(dAnimaux);
    
    // Affichage du plateau et du nombre d'animaux vivants
    plateau.afficher();
    afficherNombreAnimaux();

    // Vérification de fin de partie : on parcourt la grille pour compter les animaux vivants et leurs types
    vector<Animal*> animauxVivants;
    set<string> typesAnimaux;
    grille = plateau.getGrille();
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            if (animal != nullptr && animal->getVivant()) {
                animauxVivants.push_back(animal);
                typesAnimaux.insert(animal->getNom()); // On insère le nom pour savoir quels types sont présents
            }
        }
    }
    // Conditions d'arrêt : la partie se termine s'il ne reste qu'un seul animal
    // ou si tous les animaux vivants sont du type "Pierre" (cette deuxième condition est dû au fait que les pierres ne se déplacent pas)

    if (animauxVivants.size() <= 1 || 
       (!animauxVivants.empty() && typesAnimaux.size() == 1 && *typesAnimaux.begin() == "Pierre")) {
        jeuEnCours = false;
        if (!animauxVivants.empty()) {
            cout << "La partie est terminée ! Vainqueur : " << animauxVivants[0]->getNom() << endl;
        } else {
            cout << "Tous les animaux sont morts, aucun vainqueur !" << endl;
        }
    }
}


/**
 * @brief Lance la partie complète.
 *
 * Exécute en boucle des tours de jeu jusqu'à ce que la condition d'arrêt soit satisfaite.
 */
void Jeu::lancerPartieComplete() {
    cout << "Lancement de la partie complète..." << endl;
    // Tant que la partie est en cours, on continue à lancer des tours
    while (jeuEnCours == true) {
        lancerTour();
        // Une attente doit être ajoutée (je ne sais pas pourquoi!!!!)
        for ( int i = 0; i < 100000; i++)
        {
        }
        
    }
}

/**
 * @brief Gère l'interaction utilisateur pour lancer la partie.
 *
 * Affiche un menu interactif permettant de lancer un tour, une partie complète ou de quitter.
 * Gère également les erreurs de saisie (par exemple, si l'utilisateur entre une lettre).
 */
void Jeu::lancerPartie() {
    srand(time(NULL));  // Initialise le générateur de nombres aléatoires
    cout << "Début de la partie !" << endl;
    // Affiche les positions initiales des animaux et le plateau avant le début du jeu
    plateau.afficherPositions();
    plateau.afficher();
    afficherNombreAnimaux();

    while (jeuEnCours) {
        cout << "\nOptions :" << endl;
        cout << "1 - Lancer un tour" << endl;
        cout << "2 - Lancer une partie complète" << endl;
        cout << "3 - Quitter la partie" << endl;
        cout << "Choix : ";

        int choix;
        // Gestion des erreurs de saisie
        if (!(cin >> choix)) {
            // En cas d'entrée invalide (par exemple, une lettre), réinitialiser le flux et ignorer la ligne erronée
            cin.clear(); // Réinitialise l'état d'erreur du flux
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore la ligne incorrecte
            cout << "Entrée invalide. Veuillez saisir un nombre." << endl;
            continue; // Retourne au début de la boucle
        }

        // Traitement du choix de l'utilisateur
        if (choix == 1) {
            lancerTour();
        } else if (choix == 2) {
            lancerPartieComplete();
        } else if (choix == 3) {
            cout << "Fin de la partie." << endl;
            jeuEnCours = false;
            return;
        } else {
            cout << "Choix invalide." << endl;
        }
    }
}
