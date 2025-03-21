/* random.c */

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tsplib.h"
#include "tspdata.h"
#include "random.h"


tsp_a* random_algorithm(tspdata_t *tsp){
    srand(time(NULL));
    
    tsp_a* random = (tsp_a*)malloc(sizeof(tsp_a));
    random->tour = (int*)malloc((tsp->n + 1) * sizeof(int));
    random->total_distance = 0;
    random->size = tsp->n;
    
    int i = 0;
    while (i < tsp->n) {
        int next_city = rand() % tsp->n;
        int already_visited = 0;

        for (int j = 0; j < i; j++) {
            if (random->tour[j] == next_city) {
                already_visited = 1;
                break;
            }
        }

        if (already_visited == 0) {
            random->tour[i] = next_city;
            i++;
            if (i>1 && i<random->size){
                random->total_distance += tspdata_get(tsp, random->tour[i] , random->tour[i-1]);
            }
        }
    }
    random->tour[random->size] = random->tour[0];
    random->total_distance += tspdata_get(tsp, random->tour[random->size - 1], random->tour[random->size]);
    return random;
}

/* eof */