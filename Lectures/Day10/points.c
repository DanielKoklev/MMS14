#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define NAMELEN 3
#define COUNT 10

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}



typedef struct {
    char name[NAMELEN];
    double x;
    double y;
} point;

double distance(point,point);

int main(){
    srand(time(NULL));
    point points[COUNT];
    for (int i = 0; i < COUNT; i++){
        points[i].x = randDouble(0, 5);
        points[i].y = randDouble(0, 5);
        points[i].name[0] = randInt('A', 'Z');
        for (int j = 1; j < NAMELEN; j++){
            points[i].name[j] = randInt('a', 'z');
        }
        points[i].name[NAMELEN] = '\0';
    }

    for (int i = 0; i < COUNT; i++){
        printf("%s (%.1lf, %.1lf)\n", points[i].name, points[i].x, points[i].y);
    }

    double max = 0;
    point *point1, *point2;

    for(int i = 0; i<COUNT; i++){
        for(int j = i + 1; j<COUNT; j++){
            if(distance(points[i], points[j]) > max){
                double currDist = distance(points[i], points[j]);
                if(max < currDist){
                    max = currDist;
                    point1 = points + i;
                    point2 = points + j;
                }
            }
        }
    }
    printf("Max distance: %.2lf\n", max);
    printf("Point %s x = %.2lf. Y = %.2lf\n", point1->name, point1->x, point1->y);
    printf("Point %s x = %.2lf. Y = %.2lf\n", point2->name, point2->x, point2->y);

    return 0;
}

double distance(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}