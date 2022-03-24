#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.001

typedef struct {
    double width;
    double height;
} rectangle;

int compRects(const void* r1, const void* r2){
    rectangle* rect1 = (rectangle*)r1;
    rectangle* rect2 = (rectangle*)r1;
    double s1 = rect1->width * rect1->height;
    double s2 = rect2->width * rect2->height;
    if(fabs(s1 - s2) < EPS){
        return 0;
    } else if(s1 > s2){
        return 1;
    }
    return -1;
}

int main(){

    return 0;
}
