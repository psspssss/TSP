#include <stdlib.h>
#include "random_algo.h"
#include "random.h"

// Génère N solutions aléatoires et retourne la meilleure trouvée
solution_tsp_t* random_best_of_n(donnees_probleme_tsp_t *donnees, int n) {
    if (n <= 0) return NULL;

    solution_tsp_t* best = NULL;
    for (int i = 0; i < n; i++) {
        // Génère une solution aléatoire
        solution_tsp_t* candidate = random_algorithm(donnees);
        if (!candidate) continue;

        // Si c'est la première solution ou si elle est meilleure que la précédente, on la garde
        if (!best || candidate->distance_totale < best->distance_totale) {
            if (best) {
                // Libère la mémoire de l'ancienne meilleure solution
                free(best->chemin);
                free(best->deja_visite);
                free(best);
            }
            best = candidate;
        } else {
            // Sinon, on libère la mémoire de la solution courante
            free(candidate->chemin);
            free(candidate->deja_visite);
            free(candidate);
        }
    }
    // Retourne la meilleure solution trouvée parmi les n générées
    return best;
}