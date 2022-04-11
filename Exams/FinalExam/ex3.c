#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int N, M, rowNum;
int arr[100];
char row[50];

int comparator(const void* a, const void* b){
   return (*(int*)a - *(int*)b);
}

void* processing(void* arg){
    char* filename = (char*)arg;
    FILE* fd = fopen(filename, "r");

    qsort(&arr, sizeof(arr), sizeof(int), comparator);
}

int main(int argc, char **argv){
    
    scanf("%d %d", &N, &M);

    pthread_t threads[N];

    for(int i = 0; i < argc - 1; i++){
        scanf("%s %d", &row, &rowNum);                
        if(pthread_create(&threads[i], NULL, processing, argv[i + 1])){
            perro("Error creating the thread!\n");
            return EXIT_FAILURE;
        }

        for(int j = 0; j < M; j++){
            scanf("%d", &arr[j]);
        }
    }

    for(int i = 0; i < argc - 1; i++){
        if(pthread_join(threads[i], NULL)){
            perror("Problem with joining threads!\n");
            exit(-1);
        }
    }

    char buffer[20];
    scanf("%s", &buffer);

    







    return 0;
}