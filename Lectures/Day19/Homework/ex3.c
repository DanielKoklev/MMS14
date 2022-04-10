#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


void* printing(void* arg){
    char* pointer = arg;
    int processNum = getpid();
    int threadNum = pthread_self();
    printf("Message: %s, from thread %d in process %d\n", pointer, threadNum, processNum);
    sleep(2);
}

int main(int argc, char **argv){

    if(argc < 4){
        perror("You need to enter N processes, N threads and a string");
        return EXIT_FAILURE;
    }

    int countProc = atoi(argv[1]);
    int countThreads = atoi(argv[2]);
    char buffer[50];
    strcpy(buffer, argv[3]);

    pthread_t th[countThreads];

    for(int i = 0; i < countProc; i++){

        pid_t pid = fork();

        if(0 == pid){
            for(int i = 0; i < countThreads; i++){
                if(pthread_create(&th[i], NULL, printing(buffer), NULL) != 0){
                    perror("Problem with creating threads\n");
                    return EXIT_FAILURE;
                }

            }
            
            for(int i = 0; i < countThreads; i++){
                if(pthread_join(th[i], NULL) != 0){
                perror("Problem with joining threads\n");
                return EXIT_FAILURE;
                }
            }
        }
    }
    

    for(int i = 0; i < countProc; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}