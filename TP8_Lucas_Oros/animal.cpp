// Class Animal

#include "animal.h"
#include <iostream>
#include <ctime>    // Pour srand()

using namespace std;

//constructeur sans parametre
Animal::Animal(){
    nom = "Animal";
    x = 0;
    y = 0;
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y
Animal::Animal(int maxX, int maxY){
    nom = "Animal";
    x = rand() % maxX; //position aleatoire entre 0 et maxX
    y = rand() % maxY; //position aleatoire entre 0 et maxY
    vivant = true; //l'animal est vivant
}

//constructeur a partir de parametres x, y, a et b
Animal::Animal(int maxX, int maxY, int a, int b){
    nom = "Animal";
    //verifier si les coordonnees sont dans les limites du plateau
    if(a < 0 || a > maxX){
        cout << "Erreur: x doit etre entre 0 et " << maxX << endl;
        a = 0;
    }
    if(b < 0 || b > maxY){
        cout << "Erreur: y doit etre entre 0 et " << maxY << endl;
        b = 0;
    }
    x = a;
    y = b;
    vivant = true; //l'animal est vivant
}

//accesseurs nom
string Animal::getNom() const{
    return nom;
}

//accesseurs x
int Animal::getX() const{
    return x;
}

//accesseurs y
int Animal::getY() const{
    return y;
}

//accesseurs vivant
bool Animal::getVivant() const{
    return vivant;
}

//mutateurs vivant
void Animal::setVivant(bool v){
    vivant = v;
}

//methode qui permet d attaquer un autre animal : renvoie true si l'attaque courante gagne
bool Animal::attaque(Animal &a){
    //verifier si l'animal est vivant
    if(vivant){
        //verifier si l'animal a est vivant
        if(a.getVivant()){
            //verifier si les animaux sont sur la meme case
            if(x == a.getX() && y == a.getY()){
                cout << "Les animaux sont sur la meme case et attaquent" << endl;
                //verifier si les animaux ont la meme attaque : Un match nul est réglé par l’utilisation du générateur aléatoire (A FAIRE)
                if(TypeAttaque.resoudreAttaque(a.TypeAttaque) == true){ //si l'attaque courante gagne
                    cout << a.getNom() << " a perdu le combat et meurt." << endl;
                    a.setVivant(false);
                    return true;
                }
                else{
                    cout << nom << " a perdu le combat et meurt." << endl;
                    setVivant(false);
                    return false;
                }
            }
            else{
                cout << "Les animaux ne sont pas sur la meme case" << endl;
                //l'animal attaque est vivant
                return false;
            }
        }
        else{
            cout << "L'animal attaque est mort" << endl;
            //l'animal attaque est mort
            return false;
        }
    }
    else{
        cout << "L'animal est mort" << endl;
        //l'animal est mort
        return false;
    }
}


