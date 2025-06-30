/* tspdata.h */

#ifndef DONNEES_TSP_H
#define DONNEES_TSP_H

#include "tsplib.h"

/* structures ========================================================== */

// Représente les données du problème TSP (matrice des distances, nombre de villes)
typedef struct {
    int *matrice_distances; 
    unsigned int nb_villes;
} donnees_probleme_tsp_t;

// Représente une solution au TSP (chemin parcouru, distance totale, villes visitées)
typedef struct {
    int *chemin;                  // Chemin parcouru
    unsigned int distance_totale; // Distance totale du chemin
    int taille;                   // Nombre de villes dans le chemin
    int *deja_visite;             // Tableau indicateur des villes déjà visitées (1 = visitée, 0 = non visitée)
} solution_tsp_t;

/* Fonctions internes publiques ======================================== */

donnees_probleme_tsp_t* donnees_tsp_init(TSP *t);
void donnees_tsp_libere(donnees_probleme_tsp_t *donnees);
int donnees_tsp_get_distance(donnees_probleme_tsp_t *donnees, unsigned i, unsigned j);

#endif

/* eof */