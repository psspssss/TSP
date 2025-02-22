cmake_minimum_required(VERSION 3.10)
project(test_tsp)
set(CMAKE_C_STANDARD 99)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")

# Math library may be needed:
include(CheckLibraryExists)
CHECK_LIBRARY_EXISTS(m sin "" HAVE_LIB_M)                                                                                                                                                                                                                                         
if (HAVE_LIB_M)                                                                                                                          
    set(EXTRA_LIBS ${EXTRA_LIBS} m)                                                                                                      
endif (HAVE_LIB_M)

# Copy the data file to the binary directory
configure_file("ulysses22.tsp" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Add an executable target
add_executable(test_tsp main.c misc.c tsplib.c tspdata.c greedy.c)
target_link_libraries(test_tsp PUBLIC ${EXTRA_LIBS})
