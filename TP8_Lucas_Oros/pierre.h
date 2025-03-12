//class pierre qui herite de la class animal

//#ifndef PIERRE_H
//#define PIERRE_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "animal.h"

using namespace std;

class Pierre : public Animal{ //heritage de la class animal
private:          

public:

    //constructeur sans parametre
    Pierre();

    //setAttaque affecte l’attaqueavant le combat dans attaque
    void setAttaque();

    //constructeur a partir de parametres x, y
    void deplace(int maxX, int maxY);
};

//#endif