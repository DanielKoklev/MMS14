#include <stdio.h>

char transformSymbol(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + ('a' - 'A');
    }
    if(c >= '0' && c <= '9'){
        return c + ('A' - '0');
    }
    return '\'';
}

int main(){
    
    printf("%c\n", transformSymbol('D'));
    printf("%c\n", transformSymbol('2'));
    printf("%c\n", transformSymbol('*'));
}