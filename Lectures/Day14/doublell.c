#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node_dll;

void push(node_dll** head, int data){
    node_dll* node = malloc(sizeof(node_dll));
    node->data = data;
    node->next = *head;
    node->prev = NULL;
    if(*head != NULL){
        (*head)->prev = node;
    }
    *head = node;
}

void printElements(node_dll* head){
    node_dll* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void freeList(node_dll** head){
    node_dll* current = *head;
    while(current != NULL){
        if(current->prev != NULL){
            free(current->prev);
        }
        current = current->next;
    }
    free(current);
    *head = NULL;
}

int main(){
    node_dll* dll = NULL;
    push(&dll, 10);
    push(&dll, 20);
    push(&dll, 50);
    push(&dll, 100);
    printElements(dll);
    return 0;
}