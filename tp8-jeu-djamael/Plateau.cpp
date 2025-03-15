#include "Plateau.h"

Plateau::Plateau()
    : maxX(MAXX_DEFAULT), maxY(MAXY_DEFAULT), nombredAnimaux(MAX_ANIMAUX_DEFAULT),
      grille(MAXX_DEFAULT, vector<Animal *>(MAXY_DEFAULT, nullptr)) {}

Plateau::Plateau(int _maxX, int _maxY)
    : maxX(_maxX), maxY(_maxY), nombredAnimaux((_maxX * _maxY) * 25 / 100),
      grille(_maxX, vector<Animal *>(_maxY, nullptr)) {}

Plateau::~Plateau() {
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            delete grille[i][j];  // Libération de la mémoire
        }
    }
}

// Getters
int Plateau::getMaxX() const { return maxX; }
int Plateau::getMaxY() const { return maxY; }
int Plateau::getNombreAnimaux() const { return nombredAnimaux; }
vector<vector<Animal *>> Plateau::getGrille() const{ return grille; }

// Setters
void Plateau::setMaxX(int _maxX) {
    maxX = _maxX;
    grille.resize(maxX, vector<Animal *>(maxY, nullptr));
}
void Plateau::setGrille(const vector<vector<Animal *>>& nouvelleGrille) {
    grille = nouvelleGrille;
}
void Plateau::setMaxY(int _maxY) {
    maxY = _maxY;
    for (auto &row : grille) {
        row.resize(maxY, nullptr);
    }
}
void Plateau::setNombreAnimaux(int _nombre) {
    nombredAnimaux = _nombre;
}

// Insérer un animal sur la grille
void Plateau::insererAnimal(Animal *LAnimal) {
    int x = LAnimal->getX();
    int y = LAnimal->getY();
    set<pair<int, int>> positionsTestees;

    while (grille[x][y] != nullptr && positionsTestees.size() < (maxX * maxY)) {
        positionsTestees.insert({x, y});
        LAnimal->deplace(maxX, maxY);
        x = LAnimal->getX();
        y = LAnimal->getY();
    }

    if (grille[x][y] == nullptr) {
        grille[x][y] = LAnimal;
    } else {
        cout << "Aucune position libre pour " << LAnimal->getNom() << endl;
    }
}

// Remplir le plateau avec des animaux
void Plateau::remplir() {
    int repartition = nombredAnimaux / 4;
    vector<Animal *> Animaux;
    
    for (int i = 0; i < repartition; ++i) {
        Animaux.push_back(new Loup(maxX, maxY));
        Animaux.push_back(new Lion(maxX, maxY));
        Animaux.push_back(new Ours(maxX, maxY));
        Animaux.push_back(new Pierre(maxX, maxY));
    }

    for (Animal *animal : Animaux) {
        insererAnimal(animal);
    }
}

// Affichage du plateau
void Plateau::afficher() {
    for (int i = 0; i < maxX; i++) {
        cout << "+----";
    }
    cout << "+" << endl;

    for (int i = 0; i < maxY; i++) {
        for (int j = 0; j < maxX; j++) {
            if (grille[j][i] != nullptr && grille[j][i]->getVivant()==true) {
                cout << "| " << grille[j][i]->getNom().substr(0, 2) << " ";
            } else {
                cout << "|    ";
            }
        }
        cout << "|" << endl;

        for (int j = 0; j < maxX; j++) {
            cout << "+----";
        }
        cout << "+" << endl;
    }
}

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