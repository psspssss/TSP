#ifndef RANDOM_ALGO_H
#define RANDOM_ALGO_H

#include "tspdata.h"

// Génère N solutions aléatoires et retourne la meilleure trouvée
solution_tsp_t* random_best_of_n(donnees_probleme_tsp_t *donnees, int n);

#endif

/* eof */