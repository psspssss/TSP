# TSP

Ce projet implémente différentes approches pour résoudre le problème du voyageur de commerce (TSP - Travelling Salesman Problem). L'objectif est de trouver un chemin passant par un ensemble de points (villes), en revenant au point de départ, tout en minimisant la distance totale parcourue.

Algorithmes implémentés:

Random : génère un seul chemin en prenant un ordre aléatoire des villes. Il ne garantit pas un bon résultat, mais sert de point de comparaison simple.
Greedy : part d'une ville aléatoire et sélectionne à chaque étape la ville la plus proche non encore visitée.
Metropolis : une version simplifiée de l'algorithme de recuit simulé. Il accepte parfois des solutions moins bonnes pour éviter les minima locaux.

Visualisation:

Les points (villes) sont affichés dans une fenêtre.