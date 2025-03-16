/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Plateau.h
But : Définir la classe Plateau
*********************************************/
#ifndef cpp_plateau_h
#define cpp_plateau_h

#include "Pierre.h"
#include "Lion.h"
#include "Loup.h"
#include "Ours.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

#define MAXX_DEFAULT 10
#define MAXY_DEFAULT 10
#define MAX_ANIMAUX_DEFAULT MAXX_DEFAULT * MAXY_DEFAULT * 25 / 100

using namespace std;

class Plateau {
private:
    int maxX;
    int maxY;
    vector<vector<Animal *>> grille;
    int nombredAnimaux;

public:
    Plateau();
    Plateau(int _maxX, int _maxY);
    ~Plateau();  // Destructeur ajouté

    // Getters
    int getMaxX() const;
    int getMaxY() const;
    int getNombreAnimaux() const;
    vector<vector<Animal *>> getGrille() const;  // Retourne une copie ou une référence constante
    

    // Setters
    void setGrille(const vector<vector<Animal *>>& nouvelleGrille);
    void setMaxX(int _maxX);
    void setMaxY(int _maxY);
    void setNombreAnimaux(int _nombre);

    void insererAnimal(Animal *LAnimal);
    void remplir();
    void afficher();
    void afficherPositions();
};

#endif
