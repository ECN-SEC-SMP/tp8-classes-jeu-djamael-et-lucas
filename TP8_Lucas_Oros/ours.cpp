//Class Ours

#include "animal.h"
#include "ours.h"
#include "attaque.h"
//les ours : ils se déplacent au hasard à chaque tour selon une des 8 directions suivantes (2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2, -1) (Fig. 1). Ils attaquent uniquement avec feuille.

using namespace std;

//constructeur sans parametre
Ours::Ours(){
    nom = "Ours";
    x = 0;
    y = 0;
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y
Ours::Ours(int maxX, int maxY, int x, int y){
    nom = "Ours";
    this->x = x;
    this->y = y;
    vivant = true; //l'animal est vivant
}

//setAttaque affecte l’attaque avant le combat dans attaque => modifie l'atribut type attaque de type attaque de la classe animal
void Ours::setAttaque(){
    TypeAttaque = Attaque(1); //l'attaque du Ours est la feuille
    cout << "Le Ours attaque avec une attaque de type " << TypeAttaque.getNomAttaque() << "!" << endl; // toujours feuille
}

//constructeur a partir de parametres x, y
void Ours::deplace(int maxX, int maxY){
    // ils se déplacent au hasard à chaque tour selon une des 8 directions suivantes (2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2, -1)
    //si le lien sort du plateau, il revient de l'autre cote
    int deplacement = rand() % 8; //deplacement aleatoire

    switch (deplacement){
        case 0:
            x += 2;
            y += 1;
            if (x >= maxX) this->x = 0;
            if (y >= maxY) this->y = 0;
            break;
        case 1:
            x += 1;
            y += 2;
            if (x >= maxX) this->x = 0;
            if (y >= maxY) this->y = 0;
            break;
        case 2:
            x -= 1;
            y += 2;
            if (x < 0) this->x = maxX - 1;
            if (y >= maxY) this->y = 0;
            break;
        case 3:
            x -= 2;
            y += 1;
            if (x < 0) this->x = maxX - 1;
            if (y >= maxY) this->y = 0;
            break;
        case 4:
            x -= 2;
            y -= 1;
            if (x < 0) this->x = maxX - 1;
            if (y < 0) this->y = maxY - 1;
            break;
        case 5:
            x -= 1;
            y -= 2;
            if (x < 0) this->x = maxX - 1;
            if (y < 0) this->y = maxY - 1;
            break;
        case 6:
            x += 1;
            y -= 2;
            if (x >= maxX) this->x = 0;
            if (y < 0) this->y = maxY - 1;
            break;
        case 7:
            x += 2;
            y -= 1;
            if (x >= maxX) this->x = 0;
            if (y < 0) this->y = maxY - 1;
            break;
    }
    

    //cout << "Le Ours se deplace en " << x << ", " << y << endl;
}

