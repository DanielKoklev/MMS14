#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int** dynarr = malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        *(dynarr + i) = malloc(m * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            *(*(dynarr + i) + j) = 10;
            printf("%d ", *(*(dynarr + i) + j));
        }
        putchar('\n');
    }
    for(int i = 0; i < n; i++){ // how to free the second arrays to prevent memory leaks
        free(*(dynarr + i));
    }
    free(dynarr);

    return 0;
}