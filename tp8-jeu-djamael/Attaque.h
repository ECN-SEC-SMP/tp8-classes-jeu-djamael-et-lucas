/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Attaque.h
But : Définir la classe Attaque
*********************************************/
#include <iostream>
using namespace std;
#ifndef cpp_attaque_h
#define cpp_attaque_h

class Attaque {
private:
    int type;   // 0 :pierre, 1: Feuille, 2:Ciseaux
public :
    Attaque();      // crée une attaque random
    Attaque(int a); // crée une attaque spécifique de type a
    int getTypeAttaque() const;
    bool resoudreAttaque(const Attaque &a) const;
    string getNomAttaque() const;
};

#endif