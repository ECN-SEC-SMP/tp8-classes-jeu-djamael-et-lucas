//#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>   
#include <map>
#include <ctime>    // Pour srand()
#include <random>   // Pour random_shuffle()
#include <vector>
#include <algorithm>
#include "test.h"
#include "animal.h"
#include "pierre.h"
#include "loup.h"
#include "lion.h"
#include "ours.h"

using namespace std;


// Fonction pour vérifier si une position est libre (pour tous les types d'animaux)
bool estPositionLibre(int x, int y, const vector<Pierre>& pierres, const vector<Loup>& loups, const vector<Lion>& lions, const vector<Ours>& ours) {
    for (const auto& pierre : pierres) { // Parcours de tous les objets de type Pierre et vérification de la position
        if (pierre.getX() == x && pierre.getY() == y)
        return false;
    }
    for (const auto& loup : loups) {
        if (loup.getX() == x && loup.getY() == y) // Parcours de tous les objets de type Loup et vérification de la position
        return false;
    }
    for (const auto& lion : lions) {
        if (lion.getX() == x && lion.getY() == y) // Parcours de tous les objets de type Lion et vérification de la position
        return false; 
    }
    for (const auto& our : ours) {
    if (our.getX() == x && our.getY() == y) // Parcours de tous les objets de type Ours et vérification de la position
    return false;
    }
    return true; // Si renvoie true alors la position est libre
}

// Fonction pour initialiser les animaux avec des positions aléatoires sans superposition
void initialiserAnimaux(vector<Pierre>& pierres, vector<Loup>& loups, vector<Lion>& lions, vector<Ours>& ours, int maxX, int maxY) {
    // Initialisation des pierres
    for (auto& pierre : pierres) {
    int x, y;
    do {
    x = rand() % maxX;
    y = rand() % maxY;
    } while (!estPositionLibre(x, y, pierres, loups, lions, ours));
    pierre = Pierre(maxX, maxY, x, y); // Utilisation du constructeur lorsque la position est libre
    }

    // Initialisation des loups
    for (auto& loup : loups) {
    int x, y;
    do {
    x = rand() % maxX;
    y = rand() % maxY;
    } while (!estPositionLibre(x, y, pierres, loups, lions, ours));
    loup = Loup(maxX, maxY, x, y); // Utilisation du constructeur lorsque la position est libre
    }

    // Initialisation des lions
    for (auto& lion : lions) {
    int x, y;
    do {
    x = rand() % maxX;
    y = rand() % maxY;
    } while (!estPositionLibre(x, y, pierres, loups, lions, ours));
    lion = Lion(maxX, maxY, x, y); // Utilisation du constructeur lorsque la position est libre
    }

    // Initialisation des ours
    for (auto& our : ours) {
    int x, y;
    do {
    x = rand() % maxX;
    y = rand() % maxY;
    } while (!estPositionLibre(x, y, pierres, loups, lions, ours));
    our = Ours(maxX, maxY, x, y); // Utilisation du constructeur lorsque la position est libre
    }
}

// Fonction pour afficher la grille avec les animaux
void afficher_grille(const vector<Pierre>& pierres, const vector<Loup>& loups, const vector<Lion>& lions, const vector<Ours>& ours, int maxX, int maxY) {
    cout << endl;

    // Bordure supérieure
    for (int j = 0; j < maxY; j++) cout << "+---";
    cout << "+" << endl;

    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            cout << "| ";  // Bordure verticale

            bool pierreTrouvee = false;
            bool loupTrouve = false;
            bool lionTrouve = false;
            bool ourTrouve = false;

            // Vérification de la présence de la pierre
            for (const auto& pierre : pierres) {
                if (pierre.getX() == i && pierre.getY() == j && pierre.getVivant()) {
                    cout << "P ";
                    pierreTrouvee = true;
                    break;
                }
            }

            // Vérification de la présence du loup
            if (!pierreTrouvee) {
                for (const auto& loup : loups) {
                    if (loup.getX() == i && loup.getY() == j && loup.getVivant()) {
                        cout << "W ";
                        loupTrouve = true;
                        break;
                    }
                }
            }

            // Vérification de la présence du lion
            if (!pierreTrouvee && !loupTrouve) {
                for (const auto& lion : lions) {
                    if (lion.getX() == i && lion.getY() == j && lion.getVivant()) {
                        cout << "L ";
                        lionTrouve = true;
                        break;
                    }
                }
            }

            // Vérification de la présence de l'ours
            if (!pierreTrouvee && !loupTrouve && !lionTrouve) {
                for (const auto& our : ours) {
                    if (our.getX() == i && our.getY() == j && our.getVivant()) {
                        cout << "O ";
                        ourTrouve = true;
                        break;
                    }
                }
            }

            if (!pierreTrouvee && !loupTrouve && !lionTrouve && !ourTrouve) {
                cout << "  ";  // Case vide
            }
        }

        cout << "|" << endl;  // Fin de ligne avec bordure droite

        // Bordure intermédiaire
        for (int j = 0; j < maxY; j++) cout << "+---";
        cout << "+" << endl;
    }
}


// Fonction pour compter les animaux vivants
int compterAnimauxVivants(const vector<Loup>& loups) {
    int count = 0;
    for (const auto& loup : loups) {
        if (loup.getVivant()) count++;
    }
    return count;
}

int compterAnimauxVivants(const vector<Pierre>& pierres) {
    int count = 0;
    for (const auto& pierre : pierres) {
        if (pierre.getVivant()) count++;
    }
    return count;
}

int compterAnimauxVivants(const vector<Lion>& lions) {
    int count = 0;
    for (const auto& lion : lions) {
        if (lion.getVivant()) count++;
    }
    return count;
}

int compterAnimauxVivants(const vector<Ours>& ours) {
    int count = 0;
    for (const auto& our : ours) {
        if (our.getVivant()) count++;
    }
    return count;
}





void partie1(void) {
    srand(time(0));  // Initialisation du générateur aléatoire

    // Création plateau
    int maxX = 5;
    int maxY = 5;
    int plateau[maxX][maxY];

    // Création pierre
    Pierre Pierre1;
    // Création loup
    Loup Loup1;
    
    // Parcourir le plateau tant que le loup et la pierre sont vivants
    while(Pierre1.getVivant() && Loup1.getVivant()){
        // Déplacement aléatoire du loup 
        Loup1.deplace(maxX, maxY);
        // Afficher le nom de l'animal
        cout << "Le loup est en " << Loup1.getX() << ", " << Loup1.getY() << endl;
        // Quand loup est sur pierre => combat
        if (Loup1.getX() == Pierre1.getX() && Loup1.getY() == Pierre1.getY()) {
            cout << "Le loup rencontre la pierre !" << endl;
            // Le comportement du combat
            Loup1.setAttaque();
            Pierre1.setAttaque();
            // Vérifier qui gagne
            if (Loup1.attaque(Pierre1)) {
                cout << "Le loup gagne !" << endl;
            } else {
                cout << "La pierre gagne !" << endl;
            }
        }
    }
}


int partie2(void) {
    srand(time(0));  // Initialisation du générateur aléatoire

    // Création plateau
    int maxX = 10;
    int maxY = 10;

    // Création de 10 pierres
    vector<Pierre> pierre_vec;
    for (int i = 0; i < 10; i++) {
        pierre_vec.push_back(Pierre());
    }
    
   // Création de 10 loups
   vector<Loup> loup_vec;
   for (int i = 0; i < 10; i++) {
       loup_vec.push_back(Loup());
   }

   // Création de 0 lions (Class par encore créée)
    vector<Lion> lion_vec;
    for (int i = 0; i < 0; i++) {
        lion_vec.push_back(Lion());
    }

    // Création de 0 ours (Class par encore créée)
    vector<Ours> ours_vec;
    for (int i = 0; i < 0; i++) {
        ours_vec.push_back(Ours());
    }

    // Initialisation des animaux => position aléatoire sur le plateau sans superposition
    initialiserAnimaux(pierre_vec, loup_vec, lion_vec, ours_vec, maxX, maxY);

    // Générateur aléatoire pour shuffle
    random_device rd;
    default_random_engine rng(rd());
    

    // Si l'utilisateur veut continuer (il appuie sur la touche entrée) 
    while (true) {

        // Deplacement de tous les loups
        for(int i = 0; i < loup_vec.size(); i++){
            loup_vec[i].deplace(maxX, maxY);
            cout << "Le loup " << i << " est en " << loup_vec[i].getX() << ", " << loup_vec[i].getY() << endl;
        } 


        // Vérifier les combats sur chaque position du plateau
        // c.a.d. verifier en parcourant tout le plateau si un animal est sur un autre animal (combat) (ex loup sur loup ou loup sur pierre)

        for (int x = 0; x < maxX; x++) {
            for (int y = 0; y < maxY; y++) {
                vector<Animal*> animauxSurCase; // Vecteur pour stocker les animaux sur la case (x, y)

                // Recherche des indices des loups sur la case (x, y)
                for (auto& loup : loup_vec) {
                    if (loup.getX() == x && loup.getY() == y && loup.getVivant()) {
                        animauxSurCase.push_back(&loup);
                    }
                }
        
                // Recherche des indices des pierres sur la case (x, y)
                for (auto& pierre : pierre_vec) {
                    if (pierre.getX() == x && pierre.getY() == y && pierre.getVivant()) {
                        animauxSurCase.push_back(&pierre);
                    }
                }
        
                // Tant qu'il y a plus d'un animal sur la case (x, y)
                while (animauxSurCase.size() > 1) {
                    shuffle(animauxSurCase.begin(), animauxSurCase.end(), rng);
                    Animal* animal1 = animauxSurCase[0];
                    Animal* animal2 = animauxSurCase[1];

        
                    // Affichage du combat
                    cout << "Combat entre " << animal1->getNom() << " et " << animal2->getNom() 
                     << " en position (" << x << ", " << y << ")" << endl;

                    // Choix des attaques
                    animal1->setAttaque();
                    animal2->setAttaque();
    
                    // Résolution du combat
                    if (animal1->attaque(*animal2)) {
                        cout << animal2->getNom() << " a perdu et est mort." << endl;
                        animal2->setVivant(false);
                        // Suppression de l'animal perdant de la case
                        animauxSurCase.erase(animauxSurCase.begin() + 1);
                    } else {
                        cout << animal1->getNom() << " a perdu et est mort." << endl;
                        animal1->setVivant(false);
                        animauxSurCase.erase(animauxSurCase.begin());
                    }
                    
                }
            }
        }

        


        afficher_grille(pierre_vec, loup_vec, lion_vec, ours_vec, maxX, maxY);

        // Affichage du nombre d'animaux restants
        cout << "Nombre de loups restants : " << compterAnimauxVivants(loup_vec) << endl;
        cout << "Nombre de pierres restantes : " << compterAnimauxVivants(pierre_vec) << endl;
        

        // Demander a l'utilisateur d'appuyer sur entrée pour continuer
        // "end" to finish the game
        // Attendre une entrée utilisateur pour continuer ou arrêter
        while (true) {
            cout << "Appuyez sur entrée pour continuer ou tapez 'end' pour finir le jeu" << endl;
            string input;
            getline(cin, input);
            if (input == "end") return 0;
            if (input.empty()) break;
        }
    }
}


// Ajout de lion et ours + modification des fonctions pour prendre en compte les lions et les ours
int partie3(void) {
    srand(time(0));  // Initialisation du générateur aléatoire

    // Création plateau de 10x10
    int maxX = 10;
    int maxY = 10;

    // Création de 6 pierres
    vector<Pierre> pierre_vec;
    for (int i = 0; i < 6; i++) {
        pierre_vec.push_back(Pierre());
    }
    
   // Création de 6 loups
   vector<Loup> loup_vec;
   for (int i = 0; i < 6; i++) {
       loup_vec.push_back(Loup());
   }

   // Création de 6 lions
    vector<Lion> lion_vec;
    for (int i = 0; i < 6; i++) {
        lion_vec.push_back(Lion());
    }

    // Création de 6 ours
    vector<Ours> ours_vec;
    for (int i = 0; i < 6; i++) {
        ours_vec.push_back(Ours());
    }

    // Initialisation des animaux => position aléatoire sur le plateau sans superposition
    initialiserAnimaux(pierre_vec, loup_vec, lion_vec, ours_vec, maxX, maxY);

    // Générateur aléatoire pour shuffle
    random_device rd;
    default_random_engine rng(rd());
    

    // Si l'utilisateur veut continuer (il appuie sur la touche entrée) 
    while (true) {

        // Deplacement de tous les loups
        for(int i = 0; i < loup_vec.size(); i++){
            loup_vec[i].deplace(maxX, maxY);
            cout << "Le loup " << i << " est en " << loup_vec[i].getX() << ", " << loup_vec[i].getY() << endl;
        } 
        // Deplacement de tous les lions
        for(int i = 0; i < lion_vec.size(); i++){
            lion_vec[i].deplace(maxX, maxY);
            cout << "Le lion " << i << " est en " << lion_vec[i].getX() << ", " << lion_vec[i].getY() << endl;
        }
        // Deplacement de tous les ours
        for(int i = 0; i < ours_vec.size(); i++){
            ours_vec[i].deplace(maxX, maxY);
            cout << "L'ours " << i << " est en " << ours_vec[i].getX() << ", " << ours_vec[i].getY() << endl;
        }


        // Vérifier les combats sur chaque position du plateau
        // c.a.d. verifier en parcourant tout le plateau si un animal est sur un autre animal (combat) (ex loup sur loup ou loup sur pierre)

        for (int x = 0; x < maxX; x++) {
            for (int y = 0; y < maxY; y++) {
                vector<Animal*> animauxSurCase; // Vecteur pour stocker les animaux sur la case (x, y)

                // Recherche des indices des loups sur la case (x, y)
                for (auto& loup : loup_vec) {
                    if (loup.getX() == x && loup.getY() == y && loup.getVivant()) {
                        animauxSurCase.push_back(&loup);
                    }
                }
        
                // Recherche des indices des pierres sur la case (x, y)
                for (auto& pierre : pierre_vec) {
                    if (pierre.getX() == x && pierre.getY() == y && pierre.getVivant()) {
                        animauxSurCase.push_back(&pierre);
                    }
                }

                // Recherche des indices des lions sur la case (x, y)
                for (auto& lion : lion_vec) {
                    if (lion.getX() == x && lion.getY() == y && lion.getVivant()) {
                        animauxSurCase.push_back(&lion);
                    }
                }

                // Recherche des indices des ours sur la case (x, y)
                for (auto& ours : ours_vec) {
                    if (ours.getX() == x && ours.getY() == y && ours.getVivant()) {
                        animauxSurCase.push_back(&ours);
                    }
                }
        
                // Tant qu'il y a plus d'un animal sur la case (x, y)
                while (animauxSurCase.size() > 1) {
                    shuffle(animauxSurCase.begin(), animauxSurCase.end(), rng);
                    Animal* animal1 = animauxSurCase[0];
                    Animal* animal2 = animauxSurCase[1];

        
                    // Affichage du combat
                    cout << "Combat entre " << animal1->getNom() << " et " << animal2->getNom() 
                     << " en position (" << x << ", " << y << ")" << endl;

                    // Choix des attaques
                    animal1->setAttaque();
                    animal2->setAttaque();
    
                    // Résolution du combat
                    if (animal1->attaque(*animal2)) {
                        cout << animal2->getNom() << " a perdu et est mort." << endl;
                        animal2->setVivant(false);
                        // Suppression de l'animal perdant de la case
                        animauxSurCase.erase(animauxSurCase.begin() + 1);
                    } else {
                        cout << animal1->getNom() << " a perdu et est mort." << endl;
                        animal1->setVivant(false);
                        animauxSurCase.erase(animauxSurCase.begin());
                    }
                    
                }
            }
        }

        


        afficher_grille(pierre_vec, loup_vec, lion_vec, ours_vec, maxX, maxY);

        // Affichage du nombre d'animaux restants
        cout << "Nombre de loups restants : " << compterAnimauxVivants(loup_vec) << endl;
        cout << "Nombre de pierres restantes : " << compterAnimauxVivants(pierre_vec) << endl;
        cout << "Nombre de lions restants : " << compterAnimauxVivants(lion_vec) << endl;
        cout << "Nombre d'ours restants : " << compterAnimauxVivants(ours_vec) << endl;
        cout << "Nombre total d'animaux restants : " << compterAnimauxVivants(loup_vec) + compterAnimauxVivants(pierre_vec) + compterAnimauxVivants(lion_vec) + compterAnimauxVivants(ours_vec) << endl;
        

        // Demander a l'utilisateur d'appuyer sur entrée pour continuer
        // "end" to finish the game
        // Attendre une entrée utilisateur pour continuer ou arrêter
        while (true) {
            cout << "Appuyez sur entrée pour continuer ou tapez 'end' pour finir le jeu" << endl;
            string input;
            getline(cin, input);
            if (input == "end") return 0;
            if (input.empty()) break;
        }
    }
}