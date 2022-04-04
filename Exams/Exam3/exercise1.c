#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COUNT 5
#define EPS 0.001

typedef struct point{
    double x;
    double y;
} point_t;

typedef struct rectangle{
    point_t A;
    point_t B;
} rectangle_t;

typedef struct node{
    int val;
    struct node* next;
}node_t;

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

/*int compRects(const void* r1, const void* r2){
    rectangle_t* rect1 = (rectangle_t*)r1;
    rectangle_t* rect2 = (rectangle_t*)r1;
    double s1 = rect1->x * rect1->y;
    double s2 = rect2->x * rect2->y;
    if(fabs(s1 - s2) < EPS){
        return 0;
    } else if(s1 > s2){
        return 1;
    }
    return -1;
}*/

int main(){
    srand(time(NULL));
    rectangle_t point_t[COUNT];
    for(int i = 0; i < COUNT; i++){
        //point_t->A  = randDouble(-10., 10.0);
        //point[i].y = randDouble(-10.0, 10.0);


    return 0;
}
