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

int sum(node_t* head){
    node_t* current = head;
    int sum = 0;
    while(current != NULL){
        sum += current->val;
        current = current->next;
    }
    printf("Sum of the linked list is: %d\n", sum);
}

node_t* listCreate(int* arr, size_t n){
    node_t* head = NULL;
    for(int i = n-1; i >= 0; i--){
        push(&head, arr[i]);
    }
    return head;
}

int getMid(node_t* head){
    node_t *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow->val;
}

int main(){
    //int arr[] = {10, 20, 30, 40, 50};

    node_t* head = NULL;

    push(&head, 45);
    push(&head, 23);
    push(&head, 26);
    push(&head, 285);
    push(&head, 535);
    push(&head, 745);
    push(&head, 985);
    printf("%d\n", getMid(head));
    //sum(&head);

    //printNums(head);
    return 0;
}