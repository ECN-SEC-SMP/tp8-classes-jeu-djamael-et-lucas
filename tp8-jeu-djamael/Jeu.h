#ifndef CPP_JEU_H
#define CPP_JEU_H

#include "Plateau.h"
#include <vector>
#include <string>

class Jeu {
private:
    Plateau plateau;
    bool jeuEnCours;
    int tour;
public:
    // Constructeur avec dimensions par défaut
    Jeu(int maxX = MAXX_DEFAULT, int maxY = MAXY_DEFAULT);
    
    // Méthode qui déplace tous les animaux et retourne un vecteur 3D indexé par [x][y]
    std::vector<std::vector<std::vector<Animal*>>> deplacerAnimaux();
    
    // Méthode qui gère les conflits à partir du vecteur 3D d'animaux
    void gererConflits(std::vector<std::vector<std::vector<Animal*>>>& dAnimaux);
    
    // Méthode qui lance un tour complet : déplacement, conflits, affichage, vérification de fin
    void lancerTour();
    
    // Méthode qui lance une partie complète (tour après tour) jusqu'à la condition d'arrêt
    void lancerPartieComplete();
    
    // Méthode d'affichage du plateau et du nombre d'animaux
    void afficherNombreAnimaux();
    void lancerPartie();
};

#endif
