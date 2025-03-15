/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Loup.cpp
But : Définir les méthodes de la classe Loup
*********************************************/

#include "Loup.h"

Loup::Loup(int maxX, int maxY):Animal(maxX, maxY)
{
    this->nom = "Loup";
}
Loup::Loup(int maxX, int maxY, int a, int b):Animal(maxX, maxY, a, b)
{
    this->nom = "Loup";
}
void Loup::setAttaque()
{
    this->typeAttaque = Attaque();   // Faire toutes les attaques possibles
}
void Loup::deplace(int maxX, int maxY)
{
    this->x = rand()%maxX;
    this->y = rand()%maxY;
}