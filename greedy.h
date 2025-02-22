/* greedy.h */

#ifndef GREEDY_H
#define GREEDY_H
#include "tsplib.h"
#include "tspdata.h"


typedef struct {
    int *data; 
    unsigned int n;
} tspdata_t;

/* internal public functions =========================================== */

int dist_short(tspdata_t *tsp, int tab[], int i);
void greedy(tspdata_t *tsp);

#endif