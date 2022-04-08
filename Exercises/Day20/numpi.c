#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>


int N, T;
pthread_mutex_t lock;


void* sumSkip(void* argp){
    int startI = *((int*)argp);
    pthread_mutex_lock(&lock);

    double sum = 0;
    int divisor = 1, sign = 0;
    for(int i = startI; i < N; i+=T){
        
        sign = !(i&1) * 2 - 1;
        divisor = i*2 + 1;
        sum += sign*(1./divisor);
        
    }
    pthread_mutex_unlock(&lock);
    printf("%f\n", sum);
    return NULL;
}

int main(){
    scanf("%d", &N);
    double sum = 0;
    scanf("%d", &T);
    if(pthread_mutex_init(&lock, NULL) != 0){
        perror("Error creating mutex!\n");
        exit(-1);
    }
    pthread_t threadsID[T]; 
    
    for(int i = 0; i < T; i++){
        int* threadNum = (int*)malloc(sizeof(int));
        *threadNum = i;
        pthread_create(&threadsID[i], NULL, sumSkip, threadNum);
    }

    for(int i = 0; i < T; i++){
        pthread_join(threadsID[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    printf("\n%f\n", sum*4);
    return 0;
}