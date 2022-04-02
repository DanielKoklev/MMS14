#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10
#define EPS 0.001

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} book;

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printBooks(book* arr, size_t n){
    for(int i = 0; i < n; i++){
        printf("Title: %s, ", arr[i].title);
        printf("Author: %s, ", arr[i].author);
        printf("Pages: %d, ", arr[i].pages);
        printf("Price: %.2lf\n ", arr[i].price);
    }
}

int compTitle(const void* a, const void* b){
    return strcmp(((book*)a)->title, ((book*)b)->title);
}

int compPages(const void* a, const void* b){
    return ((book*)a)-> pages - ((book*)b)->pages;
}

int compAuthor(const void* a, const void* b){
    return strcmp(((book*)b)->author, ((book*)a)->author);
}

int compPrice(const void* a, const void* b){
    if(fabs((((book*)a)->price - ((book*)b)->price)) < EPS){
        return 0;
    } else if(((book*)a)->price > ((book*)b)->price){
        return 1;
    }
    return -1;
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




int main(){
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
    //bubbleSort(books, COUNT, sizeof(book), compPages);
    //bubbleSort(books, COUNT, sizeof(book), compAuthor);
    //bubbleSort(books, COUNT, sizeof(book), compPrice);
    //printBooks(books, COUNT);
    char buffer[2640];
    FILE* fp = fopen("booksinput.data", "rb");
    //fwrite(books, sizeof(book), COUNT, fp);
    fread(books, sizeof(book), COUNT, fp);
    for(int i = 0; i < COUNT; i++){
        printf("%u", books[i]);
    }
    
    
    
    fclose(fp);
    return 0;
}
