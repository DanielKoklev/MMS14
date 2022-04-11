#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define ITEMS_COUNT 5

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

struct items {
    int number;
    char description[250];
    double weight;
    double price;
};

struct node {
    struct items product;
    struct node* next;
};

void push(struct items product, struct node_t** head){
    struct node* current = malloc(sizeof(struct node));
    current->product = product;
    current->next = *head;
    *head = current;
}

void printArray(struct node* head){
    struct node* current = head;
    while(current != NULL){
        printf("Product: %s", current->product);
        current = current->next;
    }
    putchar('\n');
}

int main(int argc, char **argv){
    srand(time(NULL));
    int randNumber = randInt(0, 200);
    double randPrice = (1500 - 1.00) * ((double)rand() / RAND_MAX) + 1.00;
    double randWeight = (100 - 0.100) * ((double)rand() / RAND_MAX) + 0.100;
    char buff[250];
    for(int i = 0; i<((rand() % 10) - (rand() % 5)); i++){
        buff[i] = 'a' + rand()%25;
    }
    
    struct items sa;
    //sa.description = strcpy(sa.description, buff);
    sa.price = randPrice;
    sa.weight = randPrice;
    sa.number = randNumber;




    return EXIT_SUCCESS;
}