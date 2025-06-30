/* greedy.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "tspdata.h"
#include "greedy.h"

/* 
 * Trouve la ville non visitée la plus proche depuis ville_courante.
 * Parcourt toutes les villes et sélectionne celle qui n'a pas encore été visitée
 * et qui a la distance minimale depuis la ville courante.
 */
int trouver_ville_plus_proche(donnees_probleme_tsp_t *donnees, solution_tsp_t *solution, int ville_courante) {
    int ville_plus_proche = -1;
    int distance_min = INT_MAX;
    for (int ville = 0; ville < donnees->nb_villes; ville++) {
        // Vérifie si la ville n'a pas encore été visitée
        // et si la distance depuis la ville courante est plus petite que la distance minimale trouvée jusqu'ici
        if (!solution->deja_visite[ville] &&
            donnees->matrice_distances[ville_courante * donnees->nb_villes + ville] < distance_min) {
            // Met à jour la distance minimale et retient la ville la plus proche
            distance_min = donnees->matrice_distances[ville_courante * donnees->nb_villes + ville];
            ville_plus_proche = ville;
        }
    }
    // À la fin de la boucle, ville_plus_proche contient l'indice de la ville non visitée la plus proche
    return ville_plus_proche;
}

/* 
 * Algorithme glouton pour le TSP :
 * - Commence par une ville de départ choisie aléatoirement.
 * - À chaque étape, ajoute la ville non visitée la plus proche.
 * - Termine en revenant à la ville de départ pour fermer le cycle.
 */
solution_tsp_t* algorithme_glouton(donnees_probleme_tsp_t *donnees) {
    solution_tsp_t *solution = malloc(sizeof(solution_tsp_t));
    if (!solution) return NULL;

    // Alloue le tableau pour stocker le chemin (+1 pour revenir à la ville de départ)
    solution->chemin = malloc((donnees->nb_villes + 1) * sizeof(int));
    if (!solution->chemin) {
        free(solution);
        return NULL;
    }
    // Alloue et initialise le tableau des villes déjà visitées à 0
    solution->deja_visite = calloc(donnees->nb_villes, sizeof(int));
    if (!solution->deja_visite) {
        free(solution->chemin);
        free(solution);
        return NULL;
    }
    solution->distance_totale = 0;
    solution->taille = 0;

    // Ville de départ choisie aléatoirement
    int ville_depart = rand() % donnees->nb_villes;
    solution->chemin[0] = ville_depart;
    solution->deja_visite[ville_depart] = 1;
    solution->taille = 1;

    int ville_courante = ville_depart;
    // Ajoute les villes les plus proches successivement jusqu'à visiter toutes les villes
    while (solution->taille < (int)donnees->nb_villes) {
        int prochaine_ville = trouver_ville_plus_proche(donnees, solution, ville_courante);
        solution->chemin[solution->taille] = prochaine_ville;
        solution->deja_visite[prochaine_ville] = 1;
        solution->distance_totale += donnees->matrice_distances[ville_courante * donnees->nb_villes + prochaine_ville];
        ville_courante = prochaine_ville;
        solution->taille++;
    }

    // Retour à la ville de départ pour fermer le cycle
    solution->chemin[solution->taille] = ville_depart;
    solution->distance_totale += donnees->matrice_distances[ville_courante * donnees->nb_villes + ville_depart];

    return solution;
}

/*
 * Libère la mémoire d'une solution TSP.
 */
void solution_tsp_libere(solution_tsp_t *solution) {
    if (solution) {
        free(solution->chemin);
        free(solution->deja_visite);
        free(solution);
    }
}

/* eof */