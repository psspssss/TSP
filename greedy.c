#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tspdata.h"
#include "greedy.h"

// Function to find the closest unvisited city
int find_closest_city(tspdata_t *tsp, int visited[], int current_city) {
    int closest_city = -1;
    int min_distance = __INT_MAX__;

    for (int city = 0; city < tsp->n; city++) {
        if (visited[city] == 0 && tsp->data[current_city * tsp->n + city] < min_distance) {
            min_distance = tsp->data[current_city * tsp->n + city];
            closest_city = city;
        }
    }
    return closest_city;
}

void greedy_algorithm(tspdata_t *tsp) {
    int visited[tsp->n];
    int tour[tsp->n + 1];
    int total_distance = 0; 

    for(int i = 0; i < tsp->n; i++) {
        visited[i] = 0;
    }

    srand(time(NULL));
    int next_city = rand() % tsp->n;
    visited[next_city] = 1;
    tour[0] = next_city + 1;

    for (int i = 1; i < tsp->n; i++) {
        int previous_city = next_city; 
        next_city = find_closest_city(tsp, visited, next_city);  
        if (next_city == -1) break;  
        visited[next_city] = 1; 
        tour[i] = next_city + 1; 
        total_distance += tsp->data[previous_city * tsp->n + next_city];
    }
    
    total_distance += tsp->data[(tsp->n-1) * tsp->n + (tour[0] - 1)];
    // Closing the loop by repeating the first city at the end
    tour[tsp->n] = tour[0];  // Add the starting city at the end to complete the loop

    // Print the closing of the loop
    printf("\nGreedy\n");
    for (int i = 0; i <= tsp->n; i++) {
        if (i==tsp->n)
        {
            printf("%d", tour[i]);
            break;
        }
        printf("%d-->", tour[i]);  // Print the full tour  
    }

    // Print the total distance of the tour
    printf("\nTotal distance: %d\n", total_distance);
}