#include <stdio.h>

int array[] = {20, 30, 40, 50};

void printNum(){
    static int n = 0;
    n++;
    printf("%d\n", n);
}

void printNextElement(){
    static int i = 0;
    printf("array[%d] = %d\n", i, array[i]);
    i++;
}

int main(){
    
    printNextElement();
    printNextElement();
    printNextElement();

    return 0;
}