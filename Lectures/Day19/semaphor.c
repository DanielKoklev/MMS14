//////////////////////////////
//      race condition      //
//////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 10

sem_t parkPlaces;

void* parking(void* arg){
    printf("Waiting for free spot.\n");
    sem_wait(&parkPlaces);
    sleep(1);
    printf("Car #%d is in the parking...\n", *(int*)arg);
    sleep(1 + rand() % 3);
    sem_post(&parkPlaces);
    printf("Out of parking...\n");
    free(arg);
}

int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    sem_init(&parkPlaces, 0, 2);
    for(int i = 0; i < COUNT; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(&th[i], NULL, parking, num) != 0){
            perror("Problem with creating threads\n");
            return EXIT_FAILURE;
        }

    }

    for(int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Problem with joining threads\n");
            return EXIT_FAILURE;
        }
    }
    sem_destroy(&parkPlaces);
    return EXIT_SUCCESS;
}