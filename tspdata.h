/* tspdata.h */

#ifndef DATA_H
#define DATA_H


/* structures ========================================================== */

typedef struct {
    int *data; 
    unsigned int n;
} tspdata_t;

typedef struct {
    int *visited;
    int *tour;  
    unsigned int total_distance;
    int size;
} tsp_a;

/* internal public functions =========================================== */

tspdata_t* tspdata_init(TSP *t);  // Initialiser et Remplir
void tspdata_free(tspdata_t *t); // Vide
int tspdata_get(tspdata_t *t , unsigned i, unsigned j); //Recupére une distance dans le tableau 


#endif

/* eof */