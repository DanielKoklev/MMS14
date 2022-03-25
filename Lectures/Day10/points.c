#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define COUNT 10

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

typedef struct {
    double x;
    double y;
} point;

double distance(point,point);

int main(){
    srand(time(NULL));
    printf("%d", randInt(1, 5));
    point points[COUNT];
    for(int i = 0; i < COUNT; i++){
        points[i].x = randDouble(0, 5);
        points[i].y = randDouble(0, 5);
    }

    for(int i = 0; i < COUNT; i++){
        printf("points[%d] (%.1lf, %.1lf)\n", i, points[i].x, points[i].y);
    }
}

double distance(point p1, point p2){
    return sqrt((p1.x-p2.y)*(p1.x-p2.y) + (p1.y-p2.y)*(p1.y-p2.y));
}