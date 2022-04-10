#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int comparator(const void* a, const void* b){
   return (*(int*)a - *(int*)b);
}

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
    }
    
    fclose(fd);

    qsort(&array, sizeof(array), sizeof(int), comparator);

    FILE *fw = fopen(filename, "wb");
    
    for(int i = 0; i < size; i++){
        fwrite((array + i), sizeof(int), 1, fw);
    }
    fclose(fw);
    free(array);
}

int main(int argc, char **argv){  

    pthread_t threads[argc-1];
    
    for(int i = 0; i < argc - 1; i++){
        if(pthread_create(&threads[i], NULL, proccessing, argv[i + 1])) {
            perror("Problem with creating threads!\n");
            exit(-1);
        }
    }   

    for(int i = 0; i < argc; i++){
        if(pthread_join(threads[i], NULL)){
            perror("Problem with joining threads!\n");
            exit(-1);
        }
    }




    return 0;
}