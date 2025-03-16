#include "Jeu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int tailleX, tailleY;

    // Demande à l'utilisateur les dimensions du plateau
    cout << "Entrez les dimensions du plateau" << endl;
    cout << "\nX = ";
    cin >> tailleX;
    cout << "\nY = ";
    cin >> tailleY;

    // Création d'un objet Jeu avec les dimensions choisies
    Jeu* lejeu = new Jeu(tailleX, tailleY);

    // Lancement du jeu
    lejeu->lancerPartie();

    return 0;
}
