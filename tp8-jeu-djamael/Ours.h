/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Ours.h
But : Définir la classe Ours
*********************************************/
#ifndef cpp_ours_h
#define cpp_ours_h

#include "Animal.h"

class Ours : public Animal{
    public :
    Ours(int maxX, int maxY);
    Ours(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};

#endif