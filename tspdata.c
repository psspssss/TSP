#include <stdio.h>
#include <stdlib.h>
#include "tsplib.h"
#include "tspdata.h"


/* Fonction pour initialiser et remplir la structure tspdata_t */
tspdata_t* tspdata_init(TSP *t) {
    tspdata_t *problem = (tspdata_t*)malloc(sizeof(tspdata_t)); //initialise problem
    if (!problem) return NULL; //erreur

    problem->n = t->dimension;

    problem->data = (int*)malloc(problem->n * problem->n * sizeof(int)); //initialise problem->data
    if (!problem->data) return NULL; // erreur

    for(int i=0; i<problem->n; i++){    //ecrit data
        for(int j=0; j<problem->n; j++){
           problem->data[i * problem->n + j] = tsp_distance(t, i+1, j+1);
        }
    }
    return problem;
}

/* Fonction pour libérer la mémoire de la structure tspdata_t */
void tspdata_free(tspdata_t *t) {
    free(t->data);  
    free(t);        
}

/* Fonction pour récupérer une distance dans le tableau */
int tspdata_get(tspdata_t *t, unsigned i, unsigned j) {
    return t->data[i * t->n + j];
}

/* Fonction pour afficher le tableau */
void tspdata_print(tspdata_t *t){
    for(int i=0; i<t->n; i++){
        for(int j=0; j<t->n; j++){
            printf("%d -> %d: %d\n", i+1, j+1, tspdata_get(t, i, j));
        }
    }
    tspdata_free(t);
}