/* visual.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "Visual.h"
#include "tspdata.h"


//Fenêtre Visuel des points TSP
void visual_test(tspdata_t *tsp ,tsp_a *greedy){
    srand(time(NULL));

    //CREATION DE LA FENETRE
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("TSP RENDERING", //nom 
                                        SDL_WINDOWPOS_CENTERED, //pos x
                                        SDL_WINDOWPOS_CENTERED, // pos y
                                        WIDTH, HEIGHT, //taille
                                        SDL_WINDOW_FULLSCREEN_DESKTOP ); //pour aficher en grand
    //CREATION DU RENDU CEAD DE REMPLIR LA FENETRE PAR CE QUE JE VEUX
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(renderer, rand()%256, rand()%256, rand()%256, 255);

    Point* points = (Point*)malloc((tsp->n+1) * sizeof(Point));
    for (int i = 0; i < tsp->n; i++) {
        points[i].num = greedy->tour[i];
        points[i].x = rand() % WIDTH;
        points[i].y = rand() % HEIGHT;
    }
    points[tsp->n].num = greedy->tour[tsp->n];
    points[tsp->n].x = points[0].x;
    points[tsp->n].y = points[0].x;

    for (int i = 0; i <= tsp->n; i++) {
        int a = greedy->tour[i];
        int b = greedy->tour[i + 1];
        SDL_RenderDrawLine(renderer, points[a].x, points[a].y, points[b].x, points[b].y);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/* eof */