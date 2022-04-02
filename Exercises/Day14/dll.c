#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev, *next;

}node_t;

void print(node_t* head){
    node_t* current = head;
    while(current != NULL){
        printf("DATA: %d\n", current->data);
        current = current->next;
    }
}

node_t* createNode(int data){
    node_t* newNode = malloc(sizeof(node_t));
    if(!newNode){
        printf("Malloc failed to create new node!\n");
        exit(-1);

    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

int main(){
    node_t *n1 = createNode(4), *n2 = createNode(2), *n3 = createNode(6);
    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;

    
    
    print(&n1);

    return 0;
}