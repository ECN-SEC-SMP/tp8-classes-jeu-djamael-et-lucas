/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Lion.cpp
But : Définir les méthodes de la classe Lion
*********************************************/

#include "Lion.h"

Lion::Lion(int maxX, int maxY):Animal(maxX, maxY)
{
    this->nom = "Lion";
}
Lion::Lion(int maxX, int maxY, int a, int b):Animal(maxX, maxY, a, b)
{
    this->nom = "Lion";
}
void Lion::setAttaque()
{
    int attaqueAleatoire = (rand()%2)+1;
    this->typeAttaque = Attaque(attaqueAleatoire);   // Faire 1 ou 2 soit Feuille ou Ciseaux
}
void Lion::deplace(int maxX, int maxY)
{
    int tirage = rand()%4;
    switch (tirage)
    {
    case 0:
        this->x = (this->x +1 + maxX)%maxX;
        this->y = (this->y +1 + maxY)%maxY;
        break;
    case 1:
        this->x = (this->x +1 + maxX)%maxX;
        this->y = (this->y -1 + maxY)%maxY;
        break;
    case 2:
        this->x = (this->x -1 + maxX)%maxX;
        this->y = (this->y -1 + maxY)%maxY;
        break;
    case 3:
        this->x = (this->x -1 + maxX)%maxX;
        this->y = (this->y +1 + maxY)%maxY;
        break;
    
    default:
        break;
    }
}