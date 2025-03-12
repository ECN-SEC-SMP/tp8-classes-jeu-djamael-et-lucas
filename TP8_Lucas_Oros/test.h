//#ifndef TEST_H
//#define TEST_H
#pragma once

#include <iostream>
#include <vector>
#include "animal.h"
#include "loup.h"
#include "pierre.h"

void partie1(void);
int partie2(void);
void afficher_grille(const std::vector<Pierre>& pierres, const std::vector<Loup>& loups, int maxX, int maxY);
int compterAnimauxVivants(const std::vector<Loup>& loups);
int compterAnimauxVivants(const std::vector<Pierre>& pierres);



//#endif