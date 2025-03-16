/*********************************************
Auteurs :    Djamaël LAHAMION
Date :       12 mars 2025
Fichier :    Animal.cpp
But :        Définir les méthodes de la classe Animal
*********************************************/

#include "Animal.h"      // Inclusion de la définition de la classe Animal et ses dépendances (ex: Attaque)
#include "stdlib.h"      // Pour utiliser la fonction rand() pour la génération de nombres aléatoires

/**
 * @brief Constructeur qui initialise l'animal avec une position aléatoire.
 *
 * Ce constructeur est utilisé pour placer l'animal sur le plateau de manière aléatoire.
 * Il initialise également l'état de l'animal à "vivant".
 *
 * @param maxX La largeur maximale du plateau (nombre de colonnes).
 * @param maxY La hauteur maximale du plateau (nombre de lignes).
 */
Animal::Animal(int maxX, int maxY)
{
    this->vivant = true;              // Marque l'animal comme vivant
    this->x = rand() % maxX;          // Affecte une position x aléatoire entre 0 et maxX-1
    this->y = rand() % maxY;          // Affecte une position y aléatoire entre 0 et maxY-1
}

/**
 * @brief Constructeur qui initialise l'animal à une position donnée.
 *
 * Ce constructeur permet d'initialiser l'animal à des coordonnées spécifiques,
 * en utilisant le modulo pour s'assurer que les coordonnées restent dans les bornes du plateau.
 * L'animal est aussi initialisé comme vivant.
 *
 * @param maxX La largeur maximale du plateau.
 * @param maxY La hauteur maximale du plateau.
 * @param a La valeur initiale de la coordonnée x.
 * @param b La valeur initiale de la coordonnée y.
 */
Animal::Animal(int maxX, int maxY, int a, int b)
{
    this->vivant = true;              // L'animal est marqué comme vivant
    this->x = a % maxX;               // La coordonnée x est calculée modulo maxX
    this->y = b % maxY;               // La coordonnée y est calculée modulo maxY
}

/**
 * @brief Retourne le nom de l'animal.
 *
 * @return Une chaîne de caractères représentant le nom de l'animal.
 */
string Animal::getNom() const
{
    return this->nom;
}

/**
 * @brief Retourne la coordonnée x de l'animal.
 *
 * @return La valeur de x.
 */
int Animal::getX() const
{
    return this->x;
}

/**
 * @brief Retourne la coordonnée y de l'animal.
 *
 * @return La valeur de y.
 */
int Animal::getY() const
{
    return this->y;
}

/**
 * @brief Vérifie si l'animal est vivant.
 *
 * @return true si l'animal est vivant, false sinon.
 */
bool Animal::getVivant() const
{
    return this->vivant;
}

/**
 * @brief Retourne l'objet Attaque associé à l'animal.
 *
 * Cette méthode permet d'obtenir le type d'attaque que l'animal utilisera lors d'un combat.
 *
 * @return Un objet Attaque représentant le type d'attaque.
 */
Attaque Animal::getAttaque() const
{
    return this->typeAttaque;
}

/**
 * @brief Définit l'état de vie de l'animal.
 *
 * Cette méthode permet de modifier l'attribut 'vivant'. On l'utilise pour marquer
 * un animal comme mort (en passant false) ou pour le réinitialiser à vivant.
 *
 * @param v true si l'animal doit être marqué comme vivant, false sinon.
 */
void Animal::setVivant(bool v)
{
    this->vivant = v;
}

/**
 * @brief Effectue une attaque contre un autre animal.
 *
 * Cette méthode compare l'attaque de l'animal courant avec celle d'un autre animal.
 * Elle utilise la méthode resoudreAttaque() de l'objet Attaque pour déterminer l'issue du combat.
 *
 * @param a Référence vers l'autre animal contre lequel l'attaque est réalisée.
 * @return true si l'attaque de l'animal courant gagne, false sinon.
 */
bool Animal::attaque(Animal &a)
{
    // Appelle la méthode resoudreAttaque() de l'attaque de l'animal courant,
    // en comparant avec l'attaque de l'autre animal (a.typeAttaque).
   return this->typeAttaque.resoudreAttaque(a.typeAttaque);
}
