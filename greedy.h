/* greedy.h */

#ifndef GREEDY_H
#define GREEDY_H
#include "tsplib.h"
#include "tspdata.h"

/* internal public functions =========================================== */

int find_closest_city(tspdata_t *tsp, int visited[], int current_city);
void greedy_algorithm(tspdata_t *tsp);

#endif