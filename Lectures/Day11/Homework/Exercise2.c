#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}


int main(void){
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    double* arr = malloc(n * sizeof(double));
    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    for(int i = 0; i<n; i++){
        *(arr + i) = randomReal(0,1);
    }
    int m;
    scanf("%d", &m);
    arr = realloc(arr, (n + m) * sizeof(double));
    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for(int i = n; i < n + m; i++){
        *(arr + i) = randomReal(1,2);
    }
    int p;
    scanf("%d", &p);
    arr = realloc(arr, (n + m + p) * sizeof(double));

    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for(int i = n + m; i < n + m + p; i++){
        *(arr + i) = randomReal(2,3);
    }

    for(int i = 0; i < n + m + p; i++){
        printf("%.2lf ", arr[i]);
    }
    putchar('\n');
    free(arr);
    return EXIT_SUCCESS;
}