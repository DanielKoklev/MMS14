#include <stdio.h>

void reverse(char* ptr){
    char* end = ptr;
    char temp;

    while(*end != '\0'){
        end++;
    }
    end--;

    while(ptr < end){
        temp = *ptr;
        *ptr++ = *end;
        *end-- = temp;
    }

}


int main(){

    char str[] = "This is a test\0";
    reverse(str);
    printf("%s", str);
    return 0;
}