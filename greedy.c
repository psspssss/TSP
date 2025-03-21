/* greedy.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "tsplib.h"
#include "tspdata.h"
#include "greedy.h"

// Trouve la ville non visitée la plus proche depuis current_city
int find_closest_city(tspdata_t *tsp, tsp_a *greedy, int current_city) {
    int closest_city = -1;
    int min_distance = __INT_MAX__;
    // Vérifie que la ville n’a pas été visitée et que la distance est minimale
    for (int city = 0; city < tsp->n; city++) {
        if (greedy->visited[city] == 0 && tsp->data[current_city * tsp->n + city] < min_distance) {
            min_distance = tsp->data[current_city * tsp->n + city];
            closest_city = city;
        }
    }
    return closest_city;
}

// Algorithme glouton pour le TSP
tsp_a* greedy_algorithm(tspdata_t *tsp) {
    srand(time(NULL));

    tsp_a *greedy = (tsp_a*)malloc(sizeof(tsp_a)); 
    greedy->tour = (int*)malloc((tsp->n + 1) * sizeof(int));
    greedy->visited = (int*)malloc(tsp->n * sizeof(int));
    greedy->total_distance = 0;
    greedy->size = tsp->n;
    
    for(int i = 0; i < tsp->n; i++) {
        greedy->visited[i] = 0;
    }

    int next_city = rand() % tsp->n;
    greedy->visited[next_city] = 1;
    greedy->tour[0] = next_city + 1;

    for (int i = 1; i < tsp->n; i++) {
        int previous_city = next_city; 
        next_city = find_closest_city(tsp, greedy, next_city);  
        if (next_city == -1) break;  
        greedy->visited[next_city] = 1; 
        greedy->tour[i] = next_city + 1; 
        greedy->total_distance += tsp->data[previous_city * tsp->n + next_city];
    }
    
    greedy->total_distance += tsp->data[(tsp->n-1) * tsp->n + (greedy->tour[0] - 1)];
    greedy->tour[tsp->n] = greedy->tour[0];
    return greedy;
}

// Libération de la mémoire allouée
void tsp_a_free(tsp_a *greedy) {
    free(greedy->tour);
    free(greedy->visited);    
    free(greedy);        
}

/* eof */