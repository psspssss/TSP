#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tspdata.h"
#include "metropolis.h"



void permut(tspdata_m *chemin, int i, int j){
   int temp = chemin->data[i];
    chemin->data[i] = chemin->data[j];
    chemin->data[j] = temp;
}

void metropolis(tspdata_m *chemin){
    srand(time(NULL));
    for (int i = 0; i < chemin->size; i++){
        int i_rd = rand() % chemin->size ;
        int j_rd = rand() % chemin->size ;
        if (i_rd<j_rd)
        {
            permut(chemin, i_rd, j_rd);
        }
    }
}
