#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define cnt 10

sem_t sem;

void* printer(void* arg){
    printf("%d Waiting for printer...\n", *(int*)arg);
    sem_wait(&sem);
    printf("%d is printing....\n", *(int*)arg);
    sleep(1 + rand() % 4);
    printf("%d finished!\n", *(int*)arg);
    sem_post(&sem);
    // printing

    free(arg);
}

int main(){
    srand(time(NULL));
    pthread_t th[cnt];
    sem_init(&sem, 0, 2);
    for(int i = 0; i < cnt; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(&th[i], NULL, printer, num)){
            perror("Error with creating the thread.\n");
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < cnt; i++){

        if(pthread_join(th[i],NULL)) {
            perror("Error joining the thread.\n");
            return EXIT_FAILURE;
        }
    }
    sem_destroy(&sem);
    return EXIT_SUCCESS;
}