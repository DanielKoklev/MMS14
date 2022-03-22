#include <stdio.h>
#include <string.h>

int mystrlen(char* str){
    int cnt = 0;
    while(str[cnt++]); // while (*(str + ++cnt));
    return cnt - 1;
}

void mystrcpy(char* dest, const char* src){
    int i = 0;
    while(src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void mystrcat(char* dest, const char* src){
    int i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    int j = 0;
    while(src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int main(){
    char name1[100] = "Stamat ";
    char name2[100] = "Ivanov";
    mystrcat(name1, name2);
    printf("String 1: %s\n", name1);
    return 0;
}