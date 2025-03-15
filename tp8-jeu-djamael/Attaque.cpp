/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 12 mars 2025
Fichier : Animal.cpp
But : Définir les méthodes de la classe Animal
*********************************************/

#include "Attaque.h"

Attaque::Attaque()
{
    this->type = rand()%3;
}
Attaque::Attaque(int a)
{
    this->type = a%3;
}
int Attaque::getTypeAttaque() const
{
    return this->type;
}
bool Attaque::resoudreAttaque(const Attaque& a) const {
    // Matrice des résultats : 0 = Pierre, 1 = Feuille, 2 = Ciseaux
    // 0 bat 2, 1 bat 0, 2 bat 1
    if (type == a.type) {
        return rand() % 2; // Égalité, gagnant aléatoire
    }
    return (type == 0 && a.type == 2) || 
           (type == 1 && a.type == 0) || 
           (type == 2 && a.type == 1);
}

string Attaque::getNomAttaque() const {
    switch (type) {
        case 0: return "Pierre";
        case 1: return "Feuille";
        case 2: return "Ciseaux";
        default: return "Inconnu";
    }
}