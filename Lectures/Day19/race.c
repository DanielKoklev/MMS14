//////////////////////////////
//      race condition      //
//////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define COUNT 1000

pthread_mutex_t incrementMux;

int num = 0;

void* routine(void* arg){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&incrementMux);
        num++; // critical section
        pthread_mutex_unlock(&incrementMux);
    }
}

int main(){
    pthread_t th[COUNT];
    pthread_mutex_init(&incrementMux, NULL);
    for(int i = 0; i < COUNT; i++){
        if(pthread_create(&th[i], NULL, routine, NULL) != 0){
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
    pthread_mutex_destroy(&incrementMux);
    printf("Num = %d\n", num);
    return EXIT_SUCCESS;
}