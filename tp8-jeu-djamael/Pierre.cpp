/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Pierre.cpp
But : Définir les méthodes de la classe Pierre
*********************************************/

#include "Pierre.h"

Pierre::Pierre(int maxX, int maxY):Animal(maxX, maxY)
{
    this->nom = "Pierre";
}
Pierre::Pierre(int maxX, int maxY, int a, int b):Animal(maxX, maxY, a, b)
{
    this->nom = "Pierre";
}
void Pierre::setAttaque()
{
    this->typeAttaque = Attaque(0);   // Faire 0 soit Pierre
}
void Pierre::deplace(int maxX, int maxY)
{
}