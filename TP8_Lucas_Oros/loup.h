//class loup qui herite de la class animal

//#ifndef LOUP_H
//#define LOUP_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "animal.h"

using namespace std;

class Loup : public Animal{ //heritage de la class animal
private:          

public:

    //constructeur sans parametre
    Loup();

    //constructeur sans parametre
    void setAttaque();

    //constructeur a partir de parametres x, y
    void deplace(int maxX, int maxY);
};

//#endif