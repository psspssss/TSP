cmake_minimum_required(VERSION 3.10)
project(test_tsp)
set(CMAKE_C_STANDARD 99)

# Copier le fichier de données dans le dossier binaire
configure_file("ulysses22.tsp" "${CMAKE_BINARY_DIR}")

# Ajouter l'exécutable
add_executable(test_tsp main.c misc.c tsplib.c tspdata.c greedy.c random.c random_algo.c metropolis.c)

# Lier la bibliothèque mathématique (libm) si nécessaire
target_link_libraries(test_tsp m)

