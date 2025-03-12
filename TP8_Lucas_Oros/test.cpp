//#include <stdio.h>
#include <iostream>
#include "test.h"
#include <math.h>  
#include <fstream> 
#include <map>
#include <sstream>
#include "animal.h"
#include "pierre.h"
#include "loup.h"
#include <ctime>    // Pour srand()
#include <random>   // Pour random_shuffle()
#include <vector>
#include <algorithm>


using namespace std;

#include <iostream>

using namespace std;



// Fonction pour vérifier si une position est libre
bool estPositionLibre(int x, int y, const vector<Pierre>& pierres, const vector<Loup>& loups) {
    for (const auto& pierre : pierres) {
        if (pierre.getX() == x && pierre.getY() == y) return false;
    }
    for (const auto& loup : loups) {
        if (loup.getX() == x && loup.getY() == y) return false;
    }
    return true;
}

// Fonction pour initialiser les animaux
void initialiserAnimaux(vector<Pierre>& pierres, vector<Loup>& loups, int maxX, int maxY) {
    // Initialisation des pierres
    for (auto& pierre : pierres) {
        int x, y;
        do {
            x = rand() % maxX;
            y = rand() % maxY;
        } while (!estPositionLibre(x, y, pierres, loups));
        pierre = Pierre(maxX, maxY, x, y); // Utilisation du nouveau constructeur
    }

    // Initialisation des loups
    for (auto& loup : loups) {
        int x, y;
        do {
            x = rand() % maxX;
            y = rand() % maxY;
        } while (!estPositionLibre(x, y, pierres, loups));
        loup = Loup(maxX, maxY, x, y); // Utilisation du nouveau constructeur
    }
}




void afficher_grille(const vector<Pierre>& pierres, const vector<Loup>& loups, int maxX, int maxY) {
    cout << endl;

    // Bordure supérieure
    for (int j = 0; j < maxY; j++) cout << "+---";
    cout << "+" << endl;

    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            cout << "| ";  // Bordure verticale

            bool pierreTrouvee = false;
            bool loupTrouve = false;

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

            if (!pierreTrouvee && !loupTrouve) {
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






int partie2(void) {
    srand(time(0));  // Initialisation du générateur aléatoire

    // Création plateau
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

    // Initialisation des animaux => position aléatoire sur le plateau sans superposition
    initialiserAnimaux(pierre_vec, loup_vec, maxX, maxY);

    // Générateur aléatoire pour shuffle
    random_device rd;
    default_random_engine rng(rd());
    

    // Si l'utilisateur veut continuer (il appuie sur entrée) 
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

        


        afficher_grille(pierre_vec, loup_vec, maxX, maxY);

        // Affichage du nombre d'animaux restants
        cout << "Nombre de loups restants : " << compterAnimauxVivants(loup_vec) << endl;
        cout << "Nombre de pierres restantes : " << compterAnimauxVivants(pierre_vec) << endl;
        

        //demander a l'utilisateur d'appuyer sur entrée pour continuer
        //"end" to finish the game
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
