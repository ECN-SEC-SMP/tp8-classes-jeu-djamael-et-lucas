/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Loup.cpp
But :        Définir les méthodes de la classe Loup
*********************************************/

#include "Loup.h"  // Inclusion de la définition de la classe Loup et de ses dépendances

/**
 * @brief Constructeur de Loup utilisant une position aléatoire.
 *
 * Appelle le constructeur de la classe de base Animal afin d'initialiser
 * la position (x, y) de manière aléatoire dans les limites du plateau, puis
 * définit le nom de l'animal comme "Loup".
 *
 * @param maxX Largeur maximale du plateau (nombre de colonnes).
 * @param maxY Hauteur maximale du plateau (nombre de lignes).
 */
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = "Loup";  // Définit le nom de l'animal à "Loup"
}

/**
 * @brief Constructeur de Loup avec position spécifiée.
 *
 * Appelle le constructeur de la classe de base Animal avec des coordonnées
 * spécifiques (a, b). Les coordonnées sont ajustées par le constructeur de Animal
 * pour rester dans les bornes du plateau. Le nom de l'animal est défini sur "Loup".
 *
 * @param maxX Largeur maximale du plateau.
 * @param maxY Hauteur maximale du plateau.
 * @param a Coordonnée x initiale.
 * @param b Coordonnée y initiale.
 */
Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = "Loup";  // Définit le nom de l'animal à "Loup"
}

/**
 * @brief Définit l'attaque du loup.
 *
 * Pour le loup, l'attaque est choisie aléatoirement parmi toutes les attaques possibles.
 * En appelant le constructeur par défaut de la classe Attaque, on obtient une attaque
 * dont le type est déterminé de façon aléatoire (0, 1 ou 2, correspondant respectivement à Pierre, Feuille ou Ciseaux).
 */
void Loup::setAttaque()
{
    this->typeAttaque = Attaque();  // Crée une attaque aléatoire (possibilité pour toutes les attaques)
}

/**
 * @brief Déplace le loup sur le plateau.
 *
 * Le loup se déplace de manière complètement aléatoire sur le plateau.
 * La nouvelle position (x, y) est obtenue en générant des nombres aléatoires
 * dans l'intervalle [0, maxX-1] pour x et [0, maxY-1] pour y.
 *
 * @param maxX Largeur maximale du plateau.
 * @param maxY Hauteur maximale du plateau.
 */
void Loup::deplace(int maxX, int maxY)
{
    // La nouvelle position est déterminée aléatoirement sans tenir compte de la position précédente
    this->x = rand() % maxX;
    this->y = rand() % maxY;
}
