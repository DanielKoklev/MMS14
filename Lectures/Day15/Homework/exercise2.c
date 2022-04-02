#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/////////////////////////////////////////////
//              UNFINISHED                 //
/////////////////////////////////////////////


#define COUNT 10
#define EPS 0.001

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} book;

typedef struct node{
    int val;
    struct node* next;
}node_t;

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int compTitle(const void* a, const void* b){
    return strcmp(((book*)a)->title, ((book*)b)->title);
}


void swapg(void* a, void* b, size_t size){
    char temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < (n-i-1) * size; j+= size){
            if (comp(arr + j, arr + j + size) > 0){
                swapg(arr + j, arr + j + size, size);
            }
        }
    }
}

void printLinkedList(node_t* head){
    node_t* temp = head->next;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void add_tail(node_t* head, int val){
    node_t* temp = head;
    node_t* temp2 = malloc(sizeof(node_t));

    temp2->val = val;
    temp2->next = NULL;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = temp2;

}

void saveList(node_t* head, char filename){
    FILE* fp = fopen(filename, "wb");
    node_t* temp = head->next;
    if(fp == NULL || head == NULL){
        printf("Failed to save items.\n");
        return -1;
    }
    while(temp){
        fwrite(&temp->val, sizeof(int), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
    printf("Successfully wrote items.\n");
}

void readList(node_t* head, char filename){
    FILE* fp = fopen(filename, "rb");
    int val;
    while(fread(&val, sizeof(int), 1, fp) != 0){
        add_tail(head, val);
    }
    fclose(fp);
    printf("Read all items successfully.\n");
}

int main(int argc, char **argv){
    srand(time(NULL));
    book books[COUNT];

    for(int i = 0; i < COUNT; i++){
        books[i].price = randDouble(1.00, 1000.00);
        books[i].pages = randInt(5, 2000);
        int countLowercase = randInt(10, 20);
        books[i].title[0] = randInt('A', 'Z');
        books[i].author[0] = randInt('A', 'Z');
        for(int j = 1; j < countLowercase; j++){
            books[i].title[j] = randInt('a', 'z');
            books[i].author[j] = randInt('a', 'z');
        }
        books[i].title[countLowercase] = 0;
        books[i].author[countLowercase] = 0;
    }

    //bubbleSort(books, COUNT, sizeof(book), compTitle);
    

    
    if(argc < 3){
        printf("You need to type the <input file> <output file>\n");
        return EXIT_FAILURE;
    }
    char inputname[50] = argv[1];
    char outputname[50] = argv[2];

    
    
    
    
    
    return 0;
}
