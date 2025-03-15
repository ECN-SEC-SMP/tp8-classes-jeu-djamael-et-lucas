#include "Jeu.h"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

Jeu::Jeu(int maxX, int maxY) : plateau(maxX, maxY) {
    plateau.remplir();
    jeuEnCours = true;
    tour = 0;
}

std::vector<std::vector<std::vector<Animal*>>> Jeu::deplacerAnimaux() {
    // Récupération de la grille actuelle du plateau
    vector<vector<Animal*>> grille = plateau.getGrille();
    // Création d'un vecteur 3D pour stocker les animaux par case après déplacement
    vector<vector<vector<Animal*>>> dAnimaux(plateau.getMaxX(), vector<vector<Animal*>>(plateau.getMaxY()));

    // Parcours de la grille
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            if (animal != nullptr && animal->getVivant()) {
                int oldX = animal->getX();
                int oldY = animal->getY();
                // Déplacement de l'animal (la méthode interne ajuste ses coordonnées)
                animal->deplace(plateau.getMaxX(), plateau.getMaxY());
                int newX = animal->getX();
                int newY = animal->getY();
                cout << animal->getNom() << ": (" << oldX << ", " << oldY << ") -> (" 
                     << newX << ", " << newY << ")" << endl;
                // Stockage de l'animal dans le vecteur 3D selon ses nouvelles coordonnées
                dAnimaux[newX][newY].push_back(animal);
            }
        }
    }
    return dAnimaux;
}

void Jeu::gererConflits(vector<vector<vector<Animal*>>>& dAnimaux) {
    // Parcours du vecteur 3D pour chaque case du plateau
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            vector<Animal*>& cellAnimaux = dAnimaux[i][j];
            // S'il y a plus d'un animal sur la même case, on résout le conflit
            if (cellAnimaux.size() > 1) {
                cout << "Conflit en (" << i << ", " << j << ") : " 
                     << cellAnimaux.size() << " animaux s'affrontent." << endl;
                Animal* survivant = cellAnimaux[0];
                for (size_t k = 1; k < cellAnimaux.size(); k++) {
                    cout << survivant->getNom() << " vs " << cellAnimaux[k]->getNom() << " :" << endl;
                    cout << "> " << survivant->getNom() << " attaque avec " 
                         << survivant->getAttaque().getNomAttaque() << endl;
                    cout << "> " << cellAnimaux[k]->getNom() << " attaque avec " 
                         << cellAnimaux[k]->getAttaque().getNomAttaque() << endl;
                    if (!survivant->attaque(*cellAnimaux[k])) {
                        cout << cellAnimaux[k]->getNom() << " gagne !" << endl;
                        survivant->setVivant(false);
                        survivant = cellAnimaux[k];
                    } else {
                        cout << survivant->getNom() << " gagne !" << endl;
                        cellAnimaux[k]->setVivant(false);
                    }
                }
                // On ne garde que le survivant dans la case
                cellAnimaux.clear();
                cellAnimaux.push_back(survivant);
            }
        }
    }
    // Reconstruction de la grille à partir du vecteur 3D
    vector<vector<Animal*>> nouvelleGrille(plateau.getMaxX(), vector<Animal*>(plateau.getMaxY(), nullptr));
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            if (!dAnimaux[i][j].empty()) {
                nouvelleGrille[i][j] = dAnimaux[i][j][0];
            }
        }
    }
    plateau.setGrille(nouvelleGrille);
}

void Jeu::afficherNombreAnimaux() {
    int totalAnimaux = 0;
    vector<vector<Animal*>> grille = plateau.getGrille();
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            if (animal != nullptr && animal->getVivant()) {
                totalAnimaux++;
            }
        }
    }
    if (tour == 0) {
        cout << "\nÉtat initial du plateau : " << totalAnimaux << " animaux." << endl;
    } else {
        cout << "\nAprès le tour " << tour << " : " << totalAnimaux << " animaux restants." << endl;
    }
}

void Jeu::lancerTour() {
    tour++;
    cout << "Début du tour " << tour << "..." << endl;
    
    // Déplacement de tous les animaux et stockage dans le vecteur 3D
    vector<vector<vector<Animal*>>> dAnimaux = deplacerAnimaux();
    
    // Gestion des conflits dans chaque case
    gererConflits(dAnimaux);
    
    // Affichage du plateau et du nombre d'animaux
    plateau.afficher();
    afficherNombreAnimaux();

    // Vérification de fin de partie
    vector<Animal*> animauxVivants;
    set<string> typesAnimaux;
    vector<vector<Animal*>> grille = plateau.getGrille();
    for (int i = 0; i < plateau.getMaxX(); i++) {
        for (int j = 0; j < plateau.getMaxY(); j++) {
            Animal* animal = grille[i][j];
            if (animal != nullptr && animal->getVivant()) {
                animauxVivants.push_back(animal);
                typesAnimaux.insert(animal->getNom());
            }
        }
    }
    // Conditions d'arrêt : s'il reste un seul animal ou si tous sont des "Pierre"
    if (animauxVivants.size() <= 1 || 
       (!animauxVivants.empty() && typesAnimaux.size() == 1 && *typesAnimaux.begin() == "Pierre")) {
        jeuEnCours = false;
        if (!animauxVivants.empty()) {
            cout << "La partie est terminée ! Vainqueur : " << animauxVivants[0]->getNom() << endl;
        } else {
            cout << "Tous les animaux sont morts, aucun vainqueur !" << endl;
        }
    }
}

void Jeu::lancerPartieComplete() {
    cout << "Lancement de la partie complète..." << endl;
    while (jeuEnCours == true)
    {
        lancerTour();
    }

}

void Jeu::lancerPartie() {
    srand(time(NULL));
    cout << "Début de la partie !" << endl;
    plateau.afficherPositions();
    plateau.afficher();
    afficherNombreAnimaux();

    while (jeuEnCours) {
        cout << "\nOptions :" << endl;
        cout << "1 - Lancer un tour" << endl;
        cout << "2 - Lancer une partie complète" << endl;
        cout << "3 - Quitter la partie" << endl;
        cout << "Choix : ";

        int choix;
        if (!(cin >> choix)) {
            // La saisie a échoué (par exemple, une lettre a été saisie)
            cin.clear(); // Réinitialise l'état d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore la ligne incorrecte
            cout << "Entrée invalide. Veuillez saisir un nombre." << endl;
            continue; // Retourne au début de la boucle
        }

        // Si la saisie a réussi, on traite le choix
        if (choix == 1) {
            lancerTour();
        } else if (choix == 2) {
            lancerPartieComplete();
        } else if (choix == 3) {
            cout << "Fin de la partie." << endl;
            jeuEnCours = false;
            return;
        } else {
            cout << "Choix invalide." << endl;
        }
    }
}