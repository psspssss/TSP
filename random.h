/* random.h */

#ifndef RANDOM_H
#define RANDOM_H

#include "tspdata.h"

/* Fonctions internes publiques ======================================== */

// Génère une solution aléatoire pour le TSP
solution_tsp_t* random_algorithm(donnees_probleme_tsp_t *donnees);

#endif

/* eof */