#include <stdio.h>
#include <string.h>


typedef struct point point;

struct point {
    double x; //elements of the struct
    double y;
} pointC; // we can define variables here too

typedef struct{
    char name[100];
    double grade;
    int number;
}  student ;


int main(){
    point pointA, pointB; //objects of the struct
    pointA.x = 20.4;
    pointA.y = 18.2;
    pointB.x = 10;
    pointB.y = 0;
    printf("Point A(%.1lf, %.1lf)\n", pointA.x, pointA.y);
    printf("Point B(%.1lf, %.1lf)\n", pointB.x, pointB.y);
    //printf("Size of structs: %lu\n", sizeof(struct point));

    student st1;
    strcpy(st1.name, "Pesho");
    st1.grade = 5.50;
    st1.number = 30;
    
    return 0;
}