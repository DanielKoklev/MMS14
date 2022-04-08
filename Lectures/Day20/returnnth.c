#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define cnt 50

int num = 0;
pthread_mutex_t mutex;
void* inc(void* arg){
    for(int i = 0; i < 1000; i++){
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }
}

int main(){
    srand(time(NULL));
    pthread_t th[cnt];
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < cnt; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(&th[i], NULL, inc, NULL)){
            perror("Error with creating the thread.\n");
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < cnt; i++){

        if(pthread_join(th[i], NULL)){
            perror("Error joining the thread.\n");
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mutex);
    printf("Num = %d\n", num);
    
    return EXIT_SUCCESS;
}