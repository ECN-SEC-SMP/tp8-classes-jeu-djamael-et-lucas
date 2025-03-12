// Class Pierre

#include "animal.h"
#include "pierre.h"
#include "attaque.h"
//les pierres : elles ne se déplacent pas. Elles attaquent uniquement avec des pierres!


using namespace std;

//constructeur sans parametre
Pierre::Pierre(){
    nom = "Pierre";
    x = rand() % 5; //position aleatoire entre 0 et 5
    y = rand() % 5; //position aleatoire entre 0 et 5
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y
Pierre::Pierre(int maxX, int maxY, int x, int y){
    nom = "Pierre";
    this->x = x;
    this->y = y;
    vivant = true; //l'animal est vivant
}

//setAttaque affecte l’attaque avant le combat dans attaque => modifie l'atribut type attaque de type attaque de la classe animal
void Pierre::setAttaque(){
    TypeAttaque = Attaque(0); //l'attaque de la pierre est de 0
    cout << "La pierre attaque avec une pierre!" << endl;
}

//constructeur a partir de parametres x, y
void Pierre::deplace(int maxX, int maxY){
    cout << "La pierre ne se deplace pas!" << endl;
}  

