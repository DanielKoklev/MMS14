#include <stdio.h>

typedef struct {
    char title[100];
    int pages;
    double price;
} Book;

int main(){
    //Book b1 = {.title = "C programming language", .pages = 300, .price = 25.20};
    Book book;
    FILE* fp = fopen("file.data", "rb");

    while(fread(&book, sizeof(Book), 1, fp) != 0){
        //book -> LL;
    }
    
    fclose(fp);
    return 0;
}