/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Pierre.h
But : Définir la classe Pierre
*********************************************/
#ifndef cpp_pierre_h
#define cpp_pierre_h

#include "Animal.h"

class Pierre : public Animal{
    public :
    Pierre(int maxX, int maxY);
    Pierre(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};

#endif