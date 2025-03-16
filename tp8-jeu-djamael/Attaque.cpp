/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Animal.cpp
But :        Définir les méthodes de la classe Attaque
*********************************************/

#include "Attaque.h"  // Inclusion de la définition de la classe Attaque
#include <cstdlib>    // Inclusion pour l'utilisation de rand()

/**
 * @brief Constructeur par défaut de la classe Attaque.
 *
 * Ce constructeur initialise le type d'attaque de manière aléatoire.
 * Le type est un entier compris entre 0 et 2, où :
 *  - 0 représente "Pierre"
 *  - 1 représente "Feuille"
 *  - 2 représente "Ciseaux"
 */
Attaque::Attaque() {
    // Initialise le type d'attaque de façon aléatoire avec rand() modulo 3
    this->type = rand() % 3;
}

/**
 * @brief Constructeur paramétré de la classe Attaque.
 *
 * Permet d'initialiser l'attaque avec un type spécifique.
 * Le type fourni est pris modulo 3 afin de garantir qu'il reste compris entre 0 et 2.
 *
 * @param a Type d'attaque désiré (sera transformé en a % 3).
 */
Attaque::Attaque(int a) {
    // Initialise le type d'attaque avec la valeur passée en paramètre,
    // réduite modulo 3 pour obtenir une valeur entre 0 et 2.
    this->type = a % 3;
}

/**
 * @brief Retourne le type d'attaque.
 *
 * @return Un entier représentant le type d'attaque (0, 1 ou 2).
 */
int Attaque::getTypeAttaque() const {
    return this->type;
}

/**
 * @brief Résout le combat entre deux attaques.
 *
 * Compare l'attaque courante avec une autre attaque passée en paramètre et
 * détermine le gagnant selon les règles du "pierre-feuille-ciseaux".
 *
 * Règles :
 *  - La pierre (0) bat les ciseaux (2).
 *  - La feuille (1) bat la pierre (0).
 *  - Les ciseaux (2) battent la feuille (1).
 * En cas d'égalité (mêmes types), le gagnant est choisi aléatoirement.
 *
 * @param a L'attaque adverse à comparer.
 * @return true si l'attaque courante gagne, false sinon.
 */
bool Attaque::resoudreAttaque(const Attaque& a) const {
    // Si les deux attaques sont de même type, le résultat est aléatoire.
    if (type == a.type) {
        return rand() % 2;  // Renvoie 0 ou 1 de façon aléatoire.
    }
    // Retourne true si l'attaque courante bat l'attaque adverse selon les règles établies.
    return (type == 0 && a.type == 2) ||  // Pierre bat Ciseaux
           (type == 1 && a.type == 0) ||  // Feuille bat Pierre
           (type == 2 && a.type == 1);    // Ciseaux bat Feuille
}

/**
 * @brief Retourne le nom de l'attaque sous forme de chaîne de caractères.
 *
 * Selon la valeur de type, cette méthode renvoie :
 *  - "Pierre" pour 0,
 *  - "Feuille" pour 1,
 *  - "Ciseaux" pour 2.
 *
 * @return Une chaîne de caractères correspondant au nom de l'attaque.
 */
string Attaque::getNomAttaque() const {
    // Utilise une structure switch pour renvoyer le nom associé au type d'attaque.
    switch (type) {
        case 0: return "Pierre";
        case 1: return "Feuille";
        case 2: return "Ciseaux";
        default: return "Inconnu"; // Cas par défaut, normalement jamais atteint.
    }
}
