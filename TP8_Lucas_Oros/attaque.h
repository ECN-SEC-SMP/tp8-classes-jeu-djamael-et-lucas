//class attaque qui est utilisée dans la class animal

//#ifndef ATTAQUE_H
//#define ATTAQUE_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class Attaque{
private:          
    int type; //type d'attaque - 0:pierre, 1:Feuille, 2:Ciseaux

public:
    //constructeur permet de creer une attaque random
    Attaque();
    
    //constructeur permet de creer une attaque specifique
    Attaque(int a);
    
    //accesseurs type d'attaque
    int getTypeAttaque() const; //const dire que les attributs ne sont pas modifies

    //methode qui permet de resoudre une attaque
    bool resoudreAttaque(Attaque &a) const;

    //methode qui permet de retourner le nom de l attaque
    string getNomAttaque() const;
};

//#endif