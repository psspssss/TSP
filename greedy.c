/* greedy.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "tsplib.h"
#include "tspdata.h"
#include "greedy.h"

/* Trouve la ville non visitée la plus proche depuis current_city */
int find_closest_city(tspdata_t *tsp, tsp_a *greedy, int current_city) {
    int closest_city = -1;
    int min_distance = __INT_MAX__;
    for (int city = 0; city < tsp->n; city++) {
        if (!greedy->visited[city] && tsp->data[current_city * tsp->n + city] < min_distance) {
            min_distance = tsp->data[current_city * tsp->n + city];
            closest_city = city;
        }
    }
    return closest_city;
}

/* Algorithme glouton pour le TSP */
tsp_a* greedy_algorithm(tspdata_t *tsp) {
    srand(time(NULL));

    tsp_a *greedy = malloc(sizeof(tsp_a));
    if (!greedy) return NULL;

    greedy->tour = malloc((tsp->n + 1) * sizeof(int));
    greedy->visited = malloc(tsp->n * sizeof(int));
    if (!greedy->tour || !greedy->visited) return NULL;

    greedy->total_distance = 0;
    greedy->size = tsp->n;

    for (int i = 0; i < tsp->n; i++) {
        greedy->visited[i] = 0;
    }

    int next_city = rand() % tsp->n;
    greedy->visited[next_city] = 1;
    greedy->tour[0] = next_city;

    for (int i = 1; i < tsp->n; i++) {
        int previous_city = next_city;
        next_city = find_closest_city(tsp, greedy, previous_city);
        greedy->visited[next_city] = 1;
        greedy->tour[i] = next_city;
        greedy->total_distance += tsp->data[previous_city * tsp->n + next_city];
    }

    // Retour à la ville de départ
    int last_city = greedy->tour[tsp->n - 1];
    int first_city = greedy->tour[0];
    greedy->total_distance += tsp->data[last_city * tsp->n + first_city];
    greedy->tour[tsp->n] = first_city;

    return greedy;
}

/* eof */