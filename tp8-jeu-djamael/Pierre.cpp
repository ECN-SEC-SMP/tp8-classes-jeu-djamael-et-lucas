/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Pierre.cpp
But :        Définir les méthodes de la classe Pierre
*********************************************/

#include "Pierre.h"  // Inclusion de la définition de la classe Pierre, qui hérite d'Animal

/**
 * @brief Constructeur de Pierre utilisant une position aléatoire.
 *
 * Ce constructeur appelle le constructeur de la classe de base Animal pour initialiser
 * l'animal à une position aléatoire sur le plateau, puis définit le nom de l'animal à "Pierre".
 *
 * @param maxX Largeur maximale du plateau (nombre de colonnes).
 * @param maxY Hauteur maximale du plateau (nombre de lignes).
 */
Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = "Pierre";  // Définit le nom de l'animal à "Pierre"
}

/**
 * @brief Constructeur de Pierre avec position spécifiée.
 *
 * Ce constructeur permet d'initialiser un Pierre à des coordonnées spécifiques.
 * Il appelle le constructeur de la classe de base Animal avec les coordonnées fournies
 * (a, b), qui sont ajustées pour rester dans les limites du plateau. Le nom est ensuite défini sur "Pierre".
 *
 * @param maxX Largeur maximale du plateau.
 * @param maxY Hauteur maximale du plateau.
 * @param a Coordonnée x initiale.
 * @param b Coordonnée y initiale.
 */
Pierre::Pierre(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = "Pierre";  // Définit le nom de l'animal à "Pierre"
}

/**
 * @brief Définit l'attaque de la pierre.
 *
 * Pour la classe Pierre, l'attaque est toujours de type "Pierre". Le constructeur de Attaque est
 * appelé avec 0 pour forcer le type d'attaque à 0 (ce qui correspond à "Pierre").
 */
void Pierre::setAttaque()
{
    this->typeAttaque = Attaque(0);   // Initialise l'attaque en forçant le type à 0 (Pierre)
}

/**
 * @brief Méthode de déplacement pour Pierre.
 *
 * Les pierres ne se déplacent pas sur le plateau. Cette méthode est donc vide, 
 * ce qui signifie qu'un objet de type Pierre reste toujours à sa position initiale.
 *
 * @param maxX Largeur maximale du plateau (non utilisé ici).
 * @param maxY Hauteur maximale du plateau (non utilisé ici).
 */
void Pierre::deplace(int maxX, int maxY)
{
    // Les pierres sont statiques et ne se déplacent pas, donc cette méthode est volontairement vide.
}
