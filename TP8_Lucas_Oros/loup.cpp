//Class Loup

#include "animal.h"
#include "loup.h"
#include "attaque.h"
#include <iostream>
#include <ctime>    // Pour srand()
//les loups : ils se déplacent (au hasard sur n’importe quelle cellule du plateau) et attaquent avec l’une des trois attaques possibles au hasard à chaque tour.


using namespace std;

//constructeur sans parametre
Loup::Loup(){
    nom = "Loup";
    x = 0;
    y = 0;
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y
Loup::Loup(int maxX, int maxY, int x, int y){
    nom = "Loup";
    this->x = x;
    this->y = y;
    vivant = true; //l'animal est vivant
}

//setAttaque affecte l’attaque avant le combat dans attaque => modifie l'atribut type attaque de type attaque de la classe animal
void Loup::setAttaque(){
    TypeAttaque = Attaque(rand()%3); //l'attaque du loup est aleatoire entre 0 et 2
    cout << "Le loup attaque avec une attaque de type " << TypeAttaque.getNomAttaque() << "!" << endl;
}

//constructeur a partir de parametres x, y
void Loup::deplace(int maxX, int maxY){
    x = rand()%maxX; //le loup se deplace aleatoirement sur l'axe x
    y = rand()%maxY; //le loup se deplace aleatoirement sur l'axe y
    //cout << "Le loup se deplace en " << x << ", " << y << endl;
}

