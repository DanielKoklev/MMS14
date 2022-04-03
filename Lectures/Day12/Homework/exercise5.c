#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek();
bool isEmpty();
bool isFull();
int size(); 
void push(int);
int pop();

int main() {
   /* push 5 items */
   push(35);
   push(56);
   push(92);
   push(15);
   push(10);
   push(15);
	
   if(isFull()) {
      printf("Queue is full!\n");   
   }

   // remove item 
   int num = pop();
	
   printf("Element removed: %d\n",num);

   printf("Element at front: %d\n",peek());

   printf("----------------------\n");
   printf("Queue:  ");
	
   while(!isEmpty()) {
      int n = pop();           
      printf("%d ",n);
   }
   printf("\n----------------------\n");
   return 0;   
}

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void push(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int pop() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}