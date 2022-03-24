#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[]){
    /*for(int i = 0; env[i] != NULL; i++){
        printf("%s\n", env[i]);
    }*/
    char* myName = getenv("USER");
    if(myName == NULL){
        printf("Not found!\n");
    }else{
        printf("Username: %s\n", myName);
    }
    return 0;
}