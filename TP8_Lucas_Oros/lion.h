//class lion qui herite de la class animal

//#ifndef LION_H
//#define LION_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "animal.h"

using namespace std;

class Lion : public Animal{ //heritage de la class animal
private:          

public:

    //constructeur sans parametre
    Lion();

    //constructeur a partir de parametres x, y
    Lion(int maxX, int maxY, int x, int y); // Constructeur avec positions spécifiques

    //constructeur sans parametre
    void setAttaque();

    //constructeur a partir de parametres x, y
    void deplace(int maxX, int maxY);
};

//#endif