/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Loup.h
But : Définir la classe Loup
*********************************************/
#ifndef cpp_loup_h
#define cpp_loup_h

#include "Animal.h"

class Loup : public Animal{
    public :
    Loup(int maxX, int maxY);
    Loup(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};

#endif