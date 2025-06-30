/* metropolis.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "tspdata.h"
#include "metropolis.h"
#include "random.h"

// Permute deux villes dans le chemin
void permuter_villes(solution_tsp_t *solution, int i, int j) {
    int temp = solution->chemin[i];
    solution->chemin[i] = solution->chemin[j];
    solution->chemin[j] = temp;
}

// Algorithme de Metropolis pour le TSP avec critère probabiliste
solution_tsp_t* algorithme_metropolis(donnees_probleme_tsp_t *donnees, int T) {
    // On génère une solution initiale aléatoire
    solution_tsp_t* metropolis = random_algorithm(donnees);
    if (!metropolis) return NULL;

    srand(time(NULL));
    for (int t = 0; t < T; t++) {
        // Sélectionne deux positions aléatoires à permuter dans le chemin
        int i_rd = rand() % metropolis->taille;
        int j_rd = rand() % metropolis->taille;
        if (i_rd == j_rd) continue; // On évite de permuter une ville avec elle-même

        // On effectue la permutation temporairement
        permuter_villes(metropolis, i_rd, j_rd);

        // Calcule la nouvelle distance totale après permutation
        unsigned int nouvelle_distance = 0;
        for (int k = 1; k <= metropolis->taille; k++) {
            nouvelle_distance += donnees->matrice_distances[
                metropolis->chemin[k-1] * donnees->nb_villes + metropolis->chemin[k]
            ];
        }

        // Calcul de la différence de distance (delta)
        int delta = (int)metropolis->distance_totale - (int)nouvelle_distance;

        // Calcul de la probabilité d'acceptation selon Metropolis : proba_expo = exp((d(C) - d(C')) / T)
        double proba_expo = exp((double)delta / T);

        // Tirage aléatoire pour décider si on garde la permutation
        double p = (double)rand() / RAND_MAX;
        if (delta > 0) {
            // On garde la permutation : elle améliore la solution
            metropolis->distance_totale = nouvelle_distance;
        } else if (p < proba_expo) {
            // On garde la permutation : elle est acceptée avec une probabilité proba_expo
            metropolis->distance_totale = nouvelle_distance;
        } else {
            // On annule la permutation car non acceptée
            permuter_villes(metropolis, i_rd, j_rd);
        }
    }
    // Retourne la meilleure solution trouvée après T itérations
    return metropolis;
}

/* eof */