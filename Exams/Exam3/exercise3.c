#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
struct node* last = NULL;
 
void push(){
    int data;
 
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    printf("\nEnter data to be "
           "inserted: \n");
    scanf("%d", &data);
 
    if (last == NULL) {
        temp->data = data;
        temp->next = temp;
        last = temp;
    }
 
    else {
        temp->data = data;
        temp->next = last->next;
        last->next = temp;
    }
}
 
void printList(){

    if (last == NULL)
        printf("\nList is empty\n");
 
    else {
        struct node* temp;
        temp = last->next;
 
        do {
            printf("\nData = %d", temp->data);
            temp = temp->next;
        } while (temp != last->next);
    }
}
 

int main(int argc, char **argv){
    push();
    push();
    push();
 
    printList();
 
    return 0;
}