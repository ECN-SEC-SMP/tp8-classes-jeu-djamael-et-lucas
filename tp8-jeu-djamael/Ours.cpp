/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Ours.cpp
But :        Définir les méthodes de la classe Ours
*********************************************/

#include "Ours.h"  // Inclusion de la définition de la classe Ours et de ses dépendances

/**
 * @brief Constructeur de Ours utilisant une position aléatoire.
 *
 * Ce constructeur appelle le constructeur de la classe de base Animal afin d'initialiser
 * l'animal avec des coordonnées aléatoires (dans les limites du plateau), puis définit le nom de l'animal à "Ours".
 *
 * @param maxX La largeur maximale du plateau (nombre de colonnes).
 * @param maxY La hauteur maximale du plateau (nombre de lignes).
 */
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = "Ours";  // Affecte le nom "Ours" à l'animal
}

/**
 * @brief Constructeur paramétré de Ours.
 *
 * Initialise un ours à des coordonnées spécifiques (a, b). Le constructeur de la classe de base Animal
 * s'assure que les coordonnées restent dans les limites du plateau. Le nom est défini sur "Ours".
 *
 * @param maxX La largeur maximale du plateau.
 * @param maxY La hauteur maximale du plateau.
 * @param a Coordonnée x initiale.
 * @param b Coordonnée y initiale.
 */
Ours::Ours(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = "Ours";  // Définit le nom de l'animal à "Ours"
}

/**
 * @brief Définit l'attaque de l'ours.
 *
 * Pour les ours, l'attaque est toujours de type Feuille (représenté par le nombre 1).
 * Cette méthode initialise l'attribut typeAttaque avec un objet Attaque de type 1.
 */
void Ours::setAttaque()
{
    this->typeAttaque = Attaque(1);  // Initialise l'attaque en forçant le type à 1 (Feuille)
}

/**
 * @brief Déplace l'ours sur le plateau.
 *
 * L'ours se déplace de manière aléatoire selon des mouvements prédéfinis inspirés des mouvements
 * en "L" (semblable aux déplacements du cavalier aux échecs). Il y a 8 directions possibles.
 * Chaque cas du switch correspond à un déplacement particulier, et l'utilisation du modulo permet
 * de gérer le débordement (lorsque l'ours atteint le bord du plateau, il réapparaît de l'autre côté).
 *
 * @param maxX La largeur maximale du plateau.
 * @param maxY La hauteur maximale du plateau.
 */
void Ours::deplace(int maxX, int maxY)
{
    int tirage = rand() % 8;  // Génère un nombre aléatoire entre 0 et 7 pour sélectionner la direction de déplacement

    switch (tirage)
    {
    case 0:
        // Déplacement : 2 pas à droite, 1 pas vers le bas
        this->x = (this->x + 2 + maxX) % maxX;
        this->y = (this->y + 1 + maxY) % maxY;
        break;
    case 1:
        // Déplacement : 1 pas à droite, 2 pas vers le bas
        this->x = (this->x + 1 + maxX) % maxX;
        this->y = (this->y + 2 + maxY) % maxY;
        break;
    case 2:
        // Déplacement : 1 pas à gauche, 2 pas vers le bas
        this->x = (this->x - 1 + maxX) % maxX;
        this->y = (this->y + 2 + maxY) % maxY;
        break;
    case 3:
        // Déplacement : 2 pas à gauche, 1 pas vers le bas
        this->x = (this->x - 2 + maxX) % maxX;
        this->y = (this->y + 1 + maxY) % maxY;
        break;
    case 4:
        // Déplacement : 2 pas à gauche, 1 pas vers le haut
        this->x = (this->x - 2 + maxX) % maxX;
        this->y = (this->y - 1 + maxY) % maxY;
        break;
    case 5:
        // Déplacement : 1 pas à gauche, 2 pas vers le haut
        this->x = (this->x - 1 + maxX) % maxX;
        this->y = (this->y - 2 + maxY) % maxY;
        break;
    case 6:
        // Déplacement : 1 pas à droite, 2 pas vers le haut
        this->x = (this->x + 1 + maxX) % maxX;
        this->y = (this->y - 2 + maxY) % maxY;
        break;
    case 7:
        // Déplacement : 2 pas à droite, 1 pas vers le haut
        this->x = (this->x + 2 + maxX) % maxX;
        this->y = (this->y - 1 + maxY) % maxY;
        break;
    default:
        // Cas par défaut (normalement jamais atteint)
        break;
    }
}
