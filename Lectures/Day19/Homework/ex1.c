#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void* printing(void* arg){
    char buff[10];
    for(int i = 0; i<10; i++){
        buff[i] = 'a' + rand()%25;
    }
    printf("%s\n", buff);
}


int main(int argc, char **argv){
    srand(time(NULL));
    int num = atoi(argv[1]);
    pthread_t th[num];

    for(int i = 0; i < num; i++){
        pthread_create(&th[i], NULL, printing, NULL);
    }
    
    for(int i = 0; i < num; i++){
        pthread_join(th[i], NULL);
    }
    
    return EXIT_SUCCESS;
}