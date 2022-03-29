#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
}node_t;

node_t *createNode(int val){
    node_t* node = malloc(sizeof(node_t));
    node->next = NULL;
    node->val = val;
}

void push(node_t** head, int val){
    node_t* newnode = createNode(val);
    newnode->next = *head;
    *head = newnode;
}

int main(){
    node_t* list = NULL;
    push(&list, 10);
    push(&list, 20);
    push(&list, 30);
    return 0;
}