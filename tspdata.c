/* tspdata.c */

#include <stdio.h>
#include <stdlib.h>

#include "tsplib.h"
#include "misc.h"
#include "tspdata.h"

/*
 * Initialise et remplit la structure donnees_probleme_tsp_t à partir d'une instance TSP.
 * Alloue la matrice des distances et la remplit à partir des données du problème.
 */
donnees_probleme_tsp_t* donnees_tsp_init(TSP *t) {
    // Allocation de la structure du problème
    donnees_probleme_tsp_t *donnees = (donnees_probleme_tsp_t*)malloc(sizeof(donnees_probleme_tsp_t));
    if (!donnees) return NULL; // Erreur d'allocation

    donnees->nb_villes = t->dimension;

    // Allocation de la matrice des distances (tableau 1D de taille n*n)
    donnees->matrice_distances = (int*)malloc(donnees->nb_villes * donnees->nb_villes * sizeof(int));
    if (!donnees->matrice_distances) {
        free(donnees);
        return NULL; // Erreur d'allocation
    }

    // Remplissage de la matrice des distances à partir des coordonnées du problème
    for (unsigned int i = 0; i < donnees->nb_villes; i++) {
        for (unsigned int j = 0; j < donnees->nb_villes; j++) {
            donnees->matrice_distances[i * donnees->nb_villes + j] = tsp_distance(t, i + 1, j + 1);
        }
    }
    return donnees;
}

/*
 * Libère la mémoire associée à la structure donnees_probleme_tsp_t.
 */
void donnees_tsp_libere(donnees_probleme_tsp_t *donnees) {
    if (donnees) {
        free(donnees->matrice_distances);
        free(donnees);
    }
}

/*
 * Récupère la distance entre deux villes (i, j) à partir de la matrice des distances.
 */
int donnees_tsp_get_distance(donnees_probleme_tsp_t *donnees, unsigned i, unsigned j) {
    return donnees->matrice_distances[i * donnees->nb_villes + j];
}

/* eof */