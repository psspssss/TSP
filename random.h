/* random.h */

#ifndef RANDOM_H
#define RANDOM_H
#include "tsplib.h"
#include "tspdata.h"

/* internal public functions =========================================== */

int dist_short(tspdata_t *tsp, int tab[], int i);
void random(tspdata_t *tsp);

#endif