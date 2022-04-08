#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define cnt 5



void* dice(void* arg){
    int* val = malloc(sizeof(int));
    *val = 1 + rand() % 6;
    return val;
}

int main(){
    srand(time(NULL));
    pthread_t th[cnt];
    
    for(int i = 0; i < cnt; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(&th[i], NULL, dice, NULL)){
            perror("Error with creating the thread.\n");
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < cnt; i++){
        int* value;
        if(pthread_join(th[i], (void**)&value)) {
            perror("Error joining the thread.\n");
            return EXIT_FAILURE;
        }
        printf("Dice value: %d\n", *value);
        free(value);
    }
    
    return EXIT_SUCCESS;
}