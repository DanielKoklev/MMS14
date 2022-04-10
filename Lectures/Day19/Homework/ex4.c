#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>

#define SIZE 10

sem_t emptyPos;
sem_t fullPos;
pthread_mutex_t addMux;

int buffer[SIZE];
int i = 0;

typedef enum { MILK, ORANGES, TOMATOES, CUCUMBERS, YOGHURT } productsName;

typedef struct {
    int barcode;
    productsName product;
    double price;
} product_info;

typedef struct node{
    product_info* ptr;
    struct node* next;
}node_t;

void push(node_t** head, int val){
    node_t* element = malloc(sizeof(node_t));
    element->ptr = val;
    element->next = *head;
    *head = element;
}



void funcHandler(){
    while(pthread_kill(pthread_self(), SIGKILL) != 0){
        FILE* fd = open("products.data", "w");
            if(fd == NULL){
            perror("error");
            return EXIT_FAILURE;
        }
        char buff[BUFSIZ];
        size_t n;
        while((n = read(STDIN_FILENO, buff, BUFSIZ)) > 0){
            if(write(fd, buff, n) == -1){
                perror("error");
                return EXIT_FAILURE;
            }
        }
    close(fd);
    }
    return EXIT_SUCCESS;
}

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


int main(int argc, char **argv){
    struct sigaction sa;
    sa.sa_handler = funcHandler;
    sigaction(SIGINT, &sa, NULL);
    int count = atoi(argv[1]);
    
    srand(time(NULL));
    pthread_t th[count];

    sem_init(&emptyPos, 0, SIZE);
    sem_init(&fullPos, 0, 0);
    pthread_mutex_init(&addMux, NULL);
    for(int i = 0; i < count; i++){
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
    for(int i = 0; i < count; i++){
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