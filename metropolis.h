/* greedy.h */

#ifndef GREEDY_H
#define GREEDY_H
#include "tsplib.h"
#include "tspdata.h"


/* structures ========================================================== */

typedef struct {
    int *data; 
    unsigned int size;
} tspdata_m;


/* internal public functions =========================================== */

void permut(tspdata_m *chemin, int i, int j);
void metropolis(tspdata_m *chemin);

#endif