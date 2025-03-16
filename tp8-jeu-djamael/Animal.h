/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Animal.h
But : Définir la classe Animal
*********************************************/
#include <iostream>
#include "Attaque.h"
using namespace std;
#ifndef cpp_animal_h
#define cpp_animal_h

class Animal {
protected:
    string nom;
    int x;  // abscisse de l'animal
    int y;  // ordonnée de l'animal
    bool vivant;
    Attaque typeAttaque;
public :
    Animal();
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);
    string getNom() const;
    int getX() const;
    int getY() const;
    bool getVivant() const;
    Attaque getAttaque() const;
    void setVivant(bool v);
    bool attaque(Animal &a);
    virtual void setAttaque() =0;
    virtual void deplace(int maxX, int maxY)= 0;
};

#endif