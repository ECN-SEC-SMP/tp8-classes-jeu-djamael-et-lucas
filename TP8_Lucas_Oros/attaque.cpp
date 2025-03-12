// Class attaque

#include "attaque.h"
#include "animal.h"
#include <iostream>

using namespace std;

//constructeur permet de creer une attaque random
Attaque::Attaque(){
    type = rand() % 3; //type d'attaque aleatoire entre 0 et 2
}

//constructeur permet de creer une att
Attaque::Attaque(int a){
    //verifier si le type d'attaque est dans les limites
    if(a < 0 || a > 2){
        cout << "Erreur: type d'attaque doit etre entre 0 et 2" << endl;
        //modulo 3 pour avoir un type d'attaque entre 0 et 2
        type = a % 3;
    }
    else{
        type = a;
    }
}

//accesseurs type d'attaque
int Attaque::getTypeAttaque() const{
    return type;
}

//methode qui permet de resoudre une attaque retourne true si l'attaque courante gagne
bool Attaque::resoudreAttaque(Attaque &a) const{

    //si l'attaque courante est pierre
    if(type == 0){
        //si l'attaque a est feuille
        if(a.getTypeAttaque() == 1){
            return false; //pierre perd contre feuille
        }
        //si l'attaque a est ciseaux
        else if(a.getTypeAttaque() == 2){
            return true; //pierre gagne contre ciseaux
        }
        else if(a.getTypeAttaque() == 0){ // si les deux attaques sont les memes :  on utilise le générateur aléatoire
            cout << "Egalite ! Un tirage au sort decide du gagnant..." << endl;
            bool victoire = (rand() % 2 == 0);  // 50% de chance de gagner
            
            if (victoire == true) {
                    cout << "L'attaque courante gagne apres tirage au sort !" << endl;
                    return true;
                } else {
                    cout << "L'attaque courante perd apres tirage au sort !" << endl;
                    return false;
                }
        }
    }

    //si l attaque courante est feuille
    else if(type == 1){
        //si l'attaque a est ciseaux
        if(a.getTypeAttaque() == 2){
            return false; //feuille perd contre ciseaux
        }
        //si l'attaque a est pierre
        else if(a.getTypeAttaque() == 0){
            return true; //feuille gagne contre pierre
        }
        else if(a.getTypeAttaque() == 1){ // si les deux attaques sont les memes :  on utilise le générateur aléatoire
            cout << "Égalite ! Un tirage au sort décide du gagnant..." << endl;
            bool victoire = (rand() % 2 == 0);  // 50% de chance de gagner
        
        if (victoire == true) {
                cout << "L'attaque courante gagne après tirage au sort !" << endl;
                return true;
            } else {
                cout << "L'attaque courante perd après tirage au sort !" << endl;
                return false;
            }
        }
    }

    //si l attaque courante est ciseaux
    else if(type == 2){
        //si l'attaque a est pierre
        if(a.getTypeAttaque() == 0){
            return false; //ciseaux perd contre pierre
        }
        //si l'attaque a est feuille
        else if(a.getTypeAttaque() == 1){
            return true; //ciseaux gagne contre feuille
        }   
        else if(a.getTypeAttaque() == 2){ // si les deux attaques sont les memes :  on utilise le générateur aléatoire
            cout << "Égalité ! Un tirage au sort décide du gagnant..." << endl;
            bool victoire = (rand() % 2 == 0);  // 50% de chance de gagner
            
            if (victoire == true) {
                    cout << "L'attaque courante gagne après tirage au sort !" << endl;
                    return true;
            } else {
                    cout << "L'attaque courante perd après tirage au sort !" << endl;
                    return false;
            }
        }
    }
    //return false; impossible
}

//methode qui permet de retourner le nom de l attaque
string Attaque::getNomAttaque() const{
    //si l'attaque est pierre
    if(type == 0){
        return "Pierre";
    }
    //si l'attaque est feuille
    else if(type == 1){
        return "Feuille";
    }
    //si l'attaque est ciseaux
    else if(type == 2){
        return "Ciseaux";
    }
    return "Erreur";
}
