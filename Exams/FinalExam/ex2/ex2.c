#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int sum = 0;

int main(int argc, char **argv){  

    for(int i = 0; i<argc; i++){
        pid_t pid = fork();
        if(0 == pid){
            // Child process
            char buffer[20];
            strcpy(buffer, argv[i]);
            for(int j = i; j < i; j++){
                char* filename = (char*)argv[j];
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
            }  
        } else{
            // Parent process
            printf("Sum is: %d", sum);
        }
    }
    for(int i = 0; i < argc; i++){
        wait(NULL);
    }

    return 0;
}