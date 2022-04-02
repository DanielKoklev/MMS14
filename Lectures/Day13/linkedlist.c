#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node_t;

void printNums(node_t* head){
    node_t* current = head;
    while(current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    putchar('\n');
}

void push(node_t** head, int val){
    node_t* element = malloc(sizeof(node_t));
    element->val = val;
    element->next = *head;
    *head = element;
}

void pop(node_t** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    node_t* temp = *head;
    *head = (*head)->next;
    free(temp);
    
}

void freeList(node_t** head){
    node_t* current = *head;
    while(current != NULL){
        node_t* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main(){
    node_t* head = NULL;
    push(&head, 45);
    push(&head, 23);
    push(&head, 245);
    pop(&head);
    printNums(head);
    return 0;
}