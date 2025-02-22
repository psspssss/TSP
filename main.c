#include <stdio.h>
#include <stdlib.h>
#include "tsplib.h"
#include "tspdata.h"
#include "greedy.h"

int main()
{
    unsigned int i, j, n;
    TSP *data = tsp_read_data("ulysses22.tsp");
    if(! data){
        fprintf(stderr, "Aborting...\n");
        return -1;
    }
    /*
    n=data->dimension;
    // The indices are 1-based!
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            printf("%d -> %d: %d\n", i, j, tsp_distance(data, i, j));
        }
    }
    */
    tspdata_t *prob = tspdata_init(data);
    greedy_algorithm(prob);  
    free(data); 
    return 0;
}
