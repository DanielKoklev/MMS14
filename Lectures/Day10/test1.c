#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

double distance(point p1, point p2){
    return sqrt((p1.x-p2.y)*(p1.x-p2.y) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main(){
    //point pts[2] = { {.x=10, .y=20}, {.x=0, .y=29.5} };
    point p1 = {.x = 20, .y = 0};
    point p2 = {.x = 0, .y = 0};
    printf("Distance: %.2lf\n", distance(p1, p2));
    return 0;
}