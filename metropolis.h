/* metropolis.h */

#ifndef METROPOLIS_H
#define METROPOLIS_H

#include "tspdata.h"

/* Fonctions internes publiques ======================================== */

// Permute deux villes dans le chemin
void permuter_villes(solution_tsp_t *solution, int i, int j);

// Algorithme de Metropolis pour le TSP
solution_tsp_t* algorithme_metropolis(donnees_probleme_tsp_t *donnees, int T);

#endif

/* eof */