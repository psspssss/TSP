/* greedy.h */

#ifndef GREEDY_H
#define GREEDY_H

/* structures ========================================================== */

/* internal public functions =========================================== */

int find_closest_city(tspdata_t *tsp, tsp_a *greedy, int current_city);
tsp_a* greedy_algorithm(tspdata_t *tsp);
void tsp_a_free(tsp_a *greedy);

#endif

/* eof */