#include <stdio.h>

int isBalanced(const char * str){
    int i = 0;
    while(*str != '\0'){
        if(*str == '('){
            i++;
        } else {
            i--;
        }
        if(i < 0){
            return 0;
        }
        str++;
    }
    return i==0;
}

int main(){
    char str0[100];
    scanf("%s", str0);

    

    printf("%d\n", isBalanced(str0));
    return 0;
}