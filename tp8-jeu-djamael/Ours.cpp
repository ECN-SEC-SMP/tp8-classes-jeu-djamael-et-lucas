/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Ours.cpp
But : Définir les méthodes de la classe Ours
*********************************************/

#include "Ours.h"
Ours::Ours(int maxX, int maxY):Animal(maxX, maxY)
{
    this->nom = "Ours";
}
Ours::Ours(int maxX, int maxY, int a, int b):Animal(maxX, maxY, a, b)
{
    this->nom = "Ours";
}
void Ours::setAttaque()
{
    this->typeAttaque = Attaque(1);
}
void Ours::deplace(int maxX, int maxY)
{
    int tirage = rand()%8;
    switch (tirage)
    {
    case 0:
        this->x = (this->x +2 + maxX)%maxX;
        this->y = (this->y +1 + maxY)%maxY;
        break;
    case 1:
        this->x = (this->x +1 + maxX)%maxX;
        this->y = (this->y +2 + maxY)%maxY;
        break;
    case 2:
        this->x = (this->x -1 + maxX)%maxX;
        this->y = (this->y +2 + maxY)%maxY;
        break;
    case 3:
        this->x = (this->x -2 + maxX)%maxX;
        this->y = (this->y +1 + maxY)%maxY;
        break;
    case 4:
        this->x = (this->x -2 + maxX)%maxX;
        this->y = (this->y -1 + maxY)%maxY;
        break;
    case 5:
        this->x = (this->x -1 + maxX)%maxX;
        this->y = (this->y -2 + maxY)%maxY;
        break;
    case 6:
        this->x = (this->x +1 + maxX)%maxX;
        this->y = (this->y -2 + maxY)%maxY;
        break;
    case 7:
        this->x = (this->x +2 + maxX)%maxX;
        this->y = (this->y -1 + maxY)%maxY;
        break;
    default:
        break;
    }
}