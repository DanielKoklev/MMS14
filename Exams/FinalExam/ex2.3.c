#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <omp.h>

int sum = 0;

void* proccessing(void* arg){
    char* filename = (char*)arg;
    FILE* fd = fopen(filename, "rb");

    int size = 0;
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    
    fseek(fd, 0, SEEK_SET);
    int* array = (int*)malloc(size);

    size = size/8;
    for(int i = 0; i < size; i++){
        fread((array + i), 8, 1, fd);
        sum += *(int*)(array + i);
    }
    
    fclose(fd);

    
}

int main(int argc, char **argv){

    #pragma omp parallel num_threads(argc-1)

    for(int i = 0; i < argc - 1;i++){
        char buffer[20];
        strcpy(buffer, argv[i]);
        proccessing(buffer);
    }
    printf("Sum is: %d", sum);
    return 0;
}