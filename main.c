#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "tsplib.h"
#include "tspdata.h"
#include "greedy.h"
#include "Visual.h"


int main()
{
    unsigned int i, j, n;
    TSP *data = tsp_read_data("ulysses22.tsp");
    if(! data){
        fprintf(stderr, "Aborting...\n");
        return -1;
    }

    tspdata_t *tsp = tspdata_init(data);
    tsp_a *greedy = greedy_algorithm(tsp);  
    visual_test(tsp, greedy);

    //tsp_free_data(tsp);
    //tsp_g_free(greedy);
    return 0;
}
