/* greedy.h */

#ifndef GREEDY_H
#define GREEDY_H

#include "tspdata.h"

/* structures ========================================================== */

/* Fonctions internes publiques ======================================== */

// Trouve la ville la plus proche non visitée
int trouver_ville_plus_proche(donnees_probleme_tsp_t *donnees, solution_tsp_t *solution, int ville_courante);

// Algorithme glouton pour le TSP
solution_tsp_t* algorithme_glouton(donnees_probleme_tsp_t *donnees);

// Libère la mémoire d'une solution TSP
void solution_tsp_libere(solution_tsp_t *solution);

#endif

/* eof */