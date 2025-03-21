/* metropolis.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tspdata.h"
#include "metropolis.h"
#include "tsplib.h"
#include "random.h"


int better_tour(tspdata_t *tsp, tsp_a *chemin, int i_rd, int j_rd){
    tsp_a *chemin2 = chemin;
    permut(chemin2, i_rd, j_rd);
    chemin2->total_distance = 0;
    for (int i = 1; i < chemin->size; i++){
        chemin2->total_distance = tsp->data;
    }
    
    return 0;
}

void permut(tsp_a *chemin, int i, int j){
   int temp = chemin->tour[i];
    chemin->tour[i] = chemin->tour[j];
    chemin->tour[j] = temp;
}

tsp_a* metropolis_algorithm(tspdata_t *tsp, int T){
    tsp_a* metropolis = random_algorithm(tsp);
    srand(time(NULL));
    for (int i = 0; i < T; i++)
    {
        int i_rd = rand() % metropolis->size ;
        int j_rd = rand() % metropolis->size ;
        if (better_tour(tsp, metropolis, i_rd, j_rd) == 1)
        {
            permut(metropolis, i_rd, j_rd);
        }
    }
    return metropolis;
}

/* eof */