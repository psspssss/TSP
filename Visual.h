/* visual.h */

#ifndef VISUAL_H
#define VISUAL_H


#define WIDTH 800
#define HEIGHT 600
#define NUM_POINTS 5

/* structures ========================================================== */

typedef struct {
    int num;  
    int x, y; 
} Point;

/* internal public functions =========================================== */

void visual_test(tspdata_t *tsp, tsp_a *greedy);

#endif

/* eof */