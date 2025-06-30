# tsp

Ce projet implémente et compare plusieurs algorithmes pour le problème du voyageur de commerce (TSP) en C, **sans interface graphique**.

## Algorithmes disponibles

- **Glouton (Greedy)** : construit un chemin en choisissant à chaque étape la ville non visitée la plus proche.
- **Random** : génère un chemin aléatoire valide.
- **Random Best of N** : génère N chemins aléatoires et garde le meilleur.
- **Metropolis** : algorithme stochastique inspiré du recuit simulé, accepte parfois des solutions moins bonnes pour éviter les minima locaux.

## Compilation

Le projet utilise CMake. Pour compiler.

## Structure

- `main.c` : point d’entrée, lance les benchmarks
- `greedy.c` : algorithme glouton
- `random.c` : génération de solutions aléatoires
- `random_algo.c` : random best of N
- `metropolis.c` : algorithme de Metropolis
- `tspdata.c`, `tsplib.c` : gestion des données TSP

## Remarques

- Les résultats sont affichés dans le terminal.
- Le projet est conçu pour être simple à compiler et portable.

---