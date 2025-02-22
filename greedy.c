#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "tspdata.h"
#include "greedy.h"

int dist_short(tspdata_t *tsp, int tab[], int i){
    int c;
    for (int j = 1; j < tsp->n; j++)
    {
        if(tsp->data[ i*tsp->n + j ] < tsp->data[ i*tsp->n + j-1 ] && tab[ j - 1 ] == 0){
            c = j;
        }
    }
    return c;
}

void greedy(tspdata_t *tsp){
    int visit[tsp->n];
    int chemin[tsp->n];
    for(int i=0; i<tsp->n; i++){
        visit[i]=0;
    }
    srand(time(NULL));
    int rd = rand() % tsp->n ;
    visit[rd-1] = 1;
    chemin[0]= rd+1;
    for (int i = 0; i < tsp->n; i++){
        rd = dist_short(tsp, visit, rd);
        visit[rd-1] = 1;
        chemin[i+1]= rd+1;
        for(int i=0; i<tsp->n; i++){
        printf("%d ",visit[i]);
        }

        printf("\n");

        for ( int j = 0; j <= i; j++)
        {
           printf("%d-->",chemin[j]); 
        }
        printf("\n"); 
    }    
    printf("\n");

    for(int i=0; i < tsp->n; i++){
        printf("%d-->", chemin[i]);
    }
}
