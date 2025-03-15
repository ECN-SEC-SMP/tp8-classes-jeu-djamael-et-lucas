/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Animal.cpp
But : Définir les méthodes de la classe Animal
*********************************************/

#include "Animal.h"
#include "stdlib.h"

Animal::Animal(int maxX, int maxY)
{
    this->vivant = true;
    this->x = rand()%maxX;
    this->y = rand()%maxY;
}

Animal::Animal(int maxX, int maxY, int a, int b)
{
    this->vivant = true;
    this->x = a%maxX;
    this->y = b%maxY;
}

string Animal::getNom() const
{
    return this->nom;
}
int Animal::getX() const
{
    return this->x;
}
int Animal::getY() const
{
    return this->y;
}
bool Animal::getVivant() const
{
    return this->vivant;
}
Attaque Animal::getAttaque() const
{
    return this->typeAttaque;
}
void Animal::setVivant(bool v)
{
    this->vivant = v;
}
bool Animal::attaque(Animal &a)
{
   return this->typeAttaque.resoudreAttaque(a.typeAttaque);
}