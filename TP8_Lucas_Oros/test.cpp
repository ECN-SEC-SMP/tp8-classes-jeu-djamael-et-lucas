//#include <stdio.h>
#include <iostream>
#include "test.h"
#include <math.h>  
#include <fstream> 
#include <map>
#include <sstream>
#include "animal.h"
#include "loup.h"
#include "pierre.h"
#include <ctime>    // Pour srand()

using namespace std;


void partie1(void) {
    srand(time(0));  // Initialisation du générateur aléatoire

    //création plateau
    int maxX = 5;
    int maxY = 5;
    int plateau[maxX][maxY];

    //création pierre
    Pierre Pierre1;
    //création loup
    Loup Loup1;
    
    while(Pierre1.getVivant() && Loup1.getVivant()){
        //déplacement aléatoire loup 
        Loup1.deplace(maxX, maxY);
        //afficher le nom de l'animal
        cout << "Le loup est en " << Loup1.getX() << ", " << Loup1.getY() << endl;
        //quand loup est sur pierre combat
        // Vérifier si le loup est sur la pierre (combat)
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

