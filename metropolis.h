/* metropolis.h */

#ifndef GREEDY_H
#define GREEDY_H

/* internal public functions =========================================== */

void permut(tsp_a *chemin, int i, int j);
int better_tour(tspdata_t *tsp, tsp_a *chemin, int i, int j);
tsp_a* metropolis_algorithm(tspdata_t *tsp, int T);


#endif

/* eof */