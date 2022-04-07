#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* routine1(void* arg){
    for(int i = 0; i<10; i++){
        printf("Hello from thread 01\n");
        sleep(1);
    }
}

void* routine2(void* arg){
    for(int i = 0; i<10; i++){
        printf("Hello from thread 02\n");
        sleep(1);
    }
}

int main(){
    pthread_t th1, th2;
    pthread_create(&th1, NULL, routine1, NULL);
    pthread_create(&th2, NULL, routine2, NULL);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return EXIT_SUCCESS;
}