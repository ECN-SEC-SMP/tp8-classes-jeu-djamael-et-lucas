/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Lion.h
But : Définir la classe Lion
*********************************************/
#ifndef cpp_lion_h
#define cpp_lion_h

#include "Animal.h"

class Lion : public Animal{
    public :
    Lion(int maxX, int maxY);
    Lion(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};

#endif