#include "Jeu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int tailleX, tailleY;
    cout<<"Entrez les dimensions du plateau"<<endl;
    cout<<"\nX = ";
    cin>>tailleX;
    cout<<"\nY = ";
    cin>>tailleY;

    Jeu* lejeu = new Jeu(tailleX,tailleY);
    lejeu->lancerPartie();

    return 0;
}
