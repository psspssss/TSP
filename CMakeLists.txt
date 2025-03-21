cmake_minimum_required(VERSION 3.10)
project(test_tsp)
set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")

# Math library (si nécessaire)
include(CheckLibraryExists)
CHECK_LIBRARY_EXISTS(m sin "" HAVE_LIB_M)
if (HAVE_LIB_M)
    set(EXTRA_LIBS ${EXTRA_LIBS} m)
endif (HAVE_LIB_M)

# Copier le fichier de données dans le dossier binaire
configure_file("ulysses22.tsp" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Ajouter l'exécutable
add_executable(test_tsp main.c misc.c tsplib.c tspdata.c greedy.c Visual.c)

# Ajoute manuellement le chemin d'inclusion et de liaison de SDL2
include_directories(/opt/homebrew/Cellar/sdl2/2.32.0/include)
link_directories(/opt/homebrew/Cellar/sdl2/2.32.0/lib)

# Lier SDL2 et autres bibliothèques nécessaires
target_link_libraries(test_tsp PUBLIC ${EXTRA_LIBS} /opt/homebrew/Cellar/sdl2/2.32.0/lib/libSDL2.dylib)
