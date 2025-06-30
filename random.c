/* random.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tspdata.h"
#include "random.h"

// Génère une solution aléatoire pour le TSP
solution_tsp_t* random_algorithm(donnees_probleme_tsp_t *donnees) {
    solution_tsp_t* solution = malloc(sizeof(solution_tsp_t));
    if (!solution) return NULL;

    // Alloue le tableau pour le chemin (+1 pour revenir à la ville de départ)
    solution->chemin = malloc((donnees->nb_villes + 1) * sizeof(int));
    if (!solution->chemin) {
        free(solution);
        return NULL;
    }
    // Alloue et initialise le tableau des villes déjà visitées à 0
    // Utilisation de calloc pour s'assurer que toutes les cases sont à 0 (aucune ville visitée au départ)
    solution->deja_visite = calloc(donnees->nb_villes, sizeof(int));
    if (!solution->deja_visite) {
        free(solution->chemin);
        free(solution);
        return NULL;
    }
    solution->distance_totale = 0;
    solution->taille = donnees->nb_villes;

    int i = 0;
    while (i < (int)donnees->nb_villes) {
        int prochaine_ville = rand() % donnees->nb_villes;
        if (!solution->deja_visite[prochaine_ville]) {
            solution->chemin[i] = prochaine_ville;
            solution->deja_visite[prochaine_ville] = 1;
            // On ne calcule la distance qu'à partir de la deuxième ville (i > 0)
            // car il n'y a pas de segment avant la première ville
            if (i > 0) {
                solution->distance_totale += donnees->matrice_distances[
                    solution->chemin[i-1] * donnees->nb_villes + solution->chemin[i]
                ];
            }
            i++;
        }
    }
    // Ferme le cycle en revenant à la ville de départ
    solution->chemin[solution->taille] = solution->chemin[0];
    solution->distance_totale += donnees->matrice_distances[
        solution->chemin[solution->taille - 1] * donnees->nb_villes + solution->chemin[solution->taille]
    ];
    return solution;
}

/* eof */