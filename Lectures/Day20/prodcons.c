#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define cnt 10
#define SIZE 20

sem_t emptyPos;
sem_t fullPos;
pthread_mutex_t addMux;

int buffer[SIZE];
int i = 0;

void* producer(void* arg){
    while(1){
        sleep(1);
        int x = rand() % 10;
        sem_wait(&emptyPos);
        pthread_mutex_lock(&addMux);

        buffer[i++] = x;
        
        pthread_mutex_unlock(&addMux);
        sem_post(&fullPos);
    }
}

void* consumer(void* arg){
    while(1){
        int x;
        sem_wait(&fullPos);
        pthread_mutex_lock(&addMux);

        x = buffer[--i];
        
        pthread_mutex_unlock(&addMux);
        sem_post(&emptyPos);
        printf("Get value: %d\n", x);
    }
}


int main(){
    srand(time(NULL));
    pthread_t th[cnt];

    sem_init(&emptyPos, 0, SIZE);
    sem_init(&fullPos, 0, 0);
    pthread_mutex_init(&addMux, NULL);

    for(int i = 0; i < cnt; i++){
        if(i == 0){
            if(pthread_create(&th[i], NULL, producer, NULL)){
                perror("Error with creating the thread.\n");
                return EXIT_FAILURE;
            }
        }else {
            if(pthread_create(&th[i], NULL, consumer, NULL)){
                perror("Error with creating the thread.\n");
                return EXIT_FAILURE;
            }
        }
        
    }

    for(int i = 0; i < cnt; i++){

        if(pthread_join(th[i],NULL)) {
            perror("Error joining the thread.\n");
            return EXIT_FAILURE;
        }
    }
    sem_destroy(&emptyPos);
    sem_destroy(&fullPos);
    pthread_mutex_destroy(&addMux);
    return EXIT_SUCCESS;
}