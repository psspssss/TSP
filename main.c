#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tsplib.h"
#include "tspdata.h"
#include "greedy.h"
#include "random.h"
#include "random_algo.h"
#include "metropolis.h"


int main()
{
    TSP *data = tsp_read_data("ulysses22.tsp");
    if(!data){
        fprintf(stderr, "Aborting...\n");
        return -1;
    }

    donnees_probleme_tsp_t *donnees = donnees_tsp_init(data);

    // Benchmark Greedy
    clock_t start_greedy = clock();
    solution_tsp_t *greedy = algorithme_glouton(donnees);
    clock_t end_greedy = clock();
    double time_greedy = (double)(end_greedy - start_greedy) / CLOCKS_PER_SEC;
    printf("Greedy: distance = %u, temps = %.6f s\n", greedy->distance_totale, time_greedy);

    // Benchmark Random
    clock_t start_random = clock();
    solution_tsp_t *random = random_algorithm(donnees);
    clock_t end_random = clock();
    double time_random = (double)(end_random - start_random) / CLOCKS_PER_SEC;
    printf("Random: distance = %u, temps = %.6f s\n", random->distance_totale, time_random);

    // Benchmark Random Best of N
    int N = 1000;
    clock_t start_randn = clock();
    solution_tsp_t *randn = random_best_of_n(donnees, N);
    clock_t end_randn = clock();
    double time_randn = (double)(end_randn - start_randn) / CLOCKS_PER_SEC;
    printf("Random Best of %d: distance = %u, temps = %.6f s\n", N, randn->distance_totale, time_randn);

    // Benchmark Metropolis
    int T = 100000;
    clock_t start_metro = clock();
    solution_tsp_t *metro = algorithme_metropolis(donnees, T);
    clock_t end_metro = clock();
    double time_metro = (double)(end_metro - start_metro) / CLOCKS_PER_SEC;
    printf("Metropolis: distance = %u, temps = %.6f s\n", metro->distance_totale, time_metro);

    // Libération mémoire
    free(greedy->chemin); free(greedy->deja_visite); free(greedy);
    free(random->chemin); free(random->deja_visite); free(random);
    free(randn->chemin); free(randn->deja_visite); free(randn);
    free(metro->chemin); free(metro->deja_visite); free(metro);
    donnees_tsp_libere(donnees);

    return 0;
}
