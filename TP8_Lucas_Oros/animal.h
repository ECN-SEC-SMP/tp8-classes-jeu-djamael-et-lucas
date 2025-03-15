//#ifndef ANIMAL_H
//#define ANIMAL_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "attaque.h"

using namespace std;

class Animal{
protected:          //attributs sont accessibles par les classes filles (heritage)
    string nom;
    int x; //abscisse de l'animal
    int y; //ordonnee de l'animal
    bool vivant;
    Attaque TypeAttaque;

public:
    //constructeur sans parametre
    Animal();
    
    //constructeur a partir de parametres limites du plateau
    Animal(int maxX, int maxY);

    //constructeur a partir de parametres x, y, a et b
    Animal(int maxX, int maxY, int a, int b);
    
    //accesseurs nom
    string getNom() const; //const dire que les attributs ne sont pas modifies

    //accesseurs x
    int getX() const; //const dire que les attributs ne sont pas modifies

    //accesseurs y
    int getY() const; //const dire que les attributs ne sont pas modifies

    //accesseurs vivant
    bool getVivant() const; //const dire que les attributs ne sont pas modifies
    
    //mutateurs vivant
    void setVivant(bool v);

    //methode qui permet d attaquer un autre animal
    bool attaque(Animal &a);

    //methode qui permet d'affecter l'attaque avant le combat dans attaque //virtuelle pure
    virtual void setAttaque() = 0;

    //methode qui permet de deplacer l'animal //virtuelle pure
    virtual void deplace(int maxX, int maxY) = 0;
};

//#endif