#include <stdio.h>

int myStrLen(const char * const str){
    unsigned len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

int main(){
    printf("%d\n",myStrLen("Hello world"));
    return 0;
}