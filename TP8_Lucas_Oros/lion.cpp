//Class Lion

#include "animal.h"
#include "lion.h"
#include "attaque.h"
//les lions :  ils se déplacent de manière aléatoire à chaque tour dans une des 4 directions (1,1), (1,-1), (-1,-1) ou (-1,1) (Fig. 1). Ils attaquent de manière aléatoire avec feuille ou ciseaux.

using namespace std;

//constructeur sans parametre
Lion::Lion(){
    nom = "Lion";
    x = 0;
    y = 0;
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y
Lion::Lion(int maxX, int maxY, int x, int y){
    nom = "Lion";
    this->x = x;
    this->y = y;
    vivant = true; //l'animal est vivant
}

//setAttaque affecte l’attaque avant le combat dans attaque => modifie l'atribut type attaque de type attaque de la classe animal
void Lion::setAttaque(){
    TypeAttaque = Attaque(rand()%2 + 1); //l'attaque du lion est aleatoire entre 1 et 2 (feuille ou ciseaux)
    cout << "Le lion attaque avec une attaque de type " << TypeAttaque.getNomAttaque() << "!" << endl;
}

//constructeur a partir de parametres x, y
void Lion::deplace(int maxX, int maxY){
    //ils se déplacent de manière aléatoire à chaque tour dans une des 4 directions (1,1), (1,-1), (-1,-1) ou (-1,1)
    //si le lien sort du plateau, il revient de l'autre cote
    int direction = rand()%4 + 1;
    switch (direction){
        case 1:
            x++;
            y++;
            if (x >= maxX) this->x = 0;
            if (y >= maxY) this->y = 0;
            break;
        case 2:
            x++;
            y--;

            if (x >= maxX) this->x = 0;
            if (y < 0) this->y = maxY - 1;
            break;
        case 3:
            x--;
            y--;

            if (x < 0) this->x = maxX - 1;
            if (y < 0) this->y = maxY - 1;
            break;
        case 4:
            x--;
            y++;

            if (x < 0) this->x = maxX - 1;
            if (y >= maxY) this->y = 0;
            break;
    }
    //cout << "Le lion se deplace en " << x << ", " << y << endl;
}

