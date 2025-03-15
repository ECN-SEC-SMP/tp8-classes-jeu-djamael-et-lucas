//class ours qui herite de la class animal

//#ifndef OURS_H
//#define OURS_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "animal.h"

using namespace std;

class Ours : public Animal{ //heritage de la class animal
private:          

public:

    //constructeur sans parametre
    Ours();

    //constructeur a partir de parametres x, y
    Ours(int maxX, int maxY, int x, int y); // Constructeur avec positions spécifiques

    //constructeur sans parametre
    void setAttaque();

    //constructeur a partir de parametres x, y
    void deplace(int maxX, int maxY);
};

//#endif