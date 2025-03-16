/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Lion.cpp
But :        Définir les méthodes de la classe Lion
*********************************************/

#include "Lion.h"  // Inclusion de la définition de la classe Lion et ses dépendances

/**
 * @brief Constructeur de Lion utilisant une position aléatoire.
 *
 * Appelle le constructeur de la classe de base Animal pour initialiser
 * les coordonnées de manière aléatoire (dans les limites du plateau),
 * puis définit le nom de l'animal à "Lion".
 *
 * @param maxX Largeur maximale du plateau (nombre de colonnes).
 * @param maxY Hauteur maximale du plateau (nombre de lignes).
 */
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->nom = "Lion";   // Définit le nom de l'animal à "Lion"
}

/**
 * @brief Constructeur de Lion avec position spécifiée.
 *
 * Appelle le constructeur de la classe de base Animal avec des coordonnées
 * spécifiques fournies (a, b). Les coordonnées sont ajustées par le constructeur
 * de Animal pour rester dans les limites du plateau. Le nom de l'animal est défini à "Lion".
 *
 * @param maxX Largeur maximale du plateau.
 * @param maxY Hauteur maximale du plateau.
 * @param a Coordonnée x initiale.
 * @param b Coordonnée y initiale.
 */
Lion::Lion(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->nom = "Lion";   // Définit le nom de l'animal à "Lion"
}

/**
 * @brief Définit l'attaque du lion.
 *
 * Les lions attaquent uniquement avec une attaque aléatoire de type Feuille ou Ciseaux.
 * Ici, un nombre aléatoire est généré pour sélectionner entre 1 et 2 :
 *   - 1 correspond à Feuille,
 *   - 2 correspond à Ciseaux.
 *
 * Cette méthode affecte l'objet Attaque correspondant au lion.
 */
void Lion::setAttaque()
{
    int attaqueAleatoire = (rand() % 2) + 1;  // Génère un nombre aléatoire entre 1 et 2
    this->typeAttaque = Attaque(attaqueAleatoire);   // Crée une attaque de type 1 (Feuille) ou 2 (Ciseaux)
}

/**
 * @brief Déplace le lion sur le plateau.
 *
 * Le lion se déplace de manière aléatoire dans l'une des 4 directions diagonales :
 *   - (1, 1)
 *   - (1, -1)
 *   - (-1, -1)
 *   - (-1, 1)
 *
 * Pour gérer le passage au bord du plateau, la position est recalculée avec un modulo.
 *
 * @param maxX Largeur du plateau.
 * @param maxY Hauteur du plateau.
 */
void Lion::deplace(int maxX, int maxY)
{
    int tirage = rand() % 4;  // Sélectionne aléatoirement l'une des 4 directions
    switch (tirage)
    {
    case 0:
        // Déplacement vers le bas-droite
        this->x = (this->x + 1 + maxX) % maxX;
        this->y = (this->y + 1 + maxY) % maxY;
        break;
    case 1:
        // Déplacement vers le haut-droite
        this->x = (this->x + 1 + maxX) % maxX;
        this->y = (this->y - 1 + maxY) % maxY;
        break;
    case 2:
        // Déplacement vers le haut-gauche
        this->x = (this->x - 1 + maxX) % maxX;
        this->y = (this->y - 1 + maxY) % maxY;
        break;
    case 3:
        // Déplacement vers le bas-gauche
        this->x = (this->x - 1 + maxX) % maxX;
        this->y = (this->y + 1 + maxY) % maxY;
        break;
    default:
        // Cas par défaut : ne fait rien (théoriquement jamais atteint)
        break;
    }
}
