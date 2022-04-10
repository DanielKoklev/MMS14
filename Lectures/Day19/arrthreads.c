#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define COUNT 5

void* routine(void* arg){
    printf("Hello there!\n");
    
}

int main(){
    pthread_t th[COUNT];
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
    return EXIT_SUCCESS;
}