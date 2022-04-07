#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    pid_t pid = fork();
    if(0 == pid){
        while(1){
            printf("Red On\n");
            sleep(2);
            printf("Red Off\n");
            sleep(2);
        }
    } else {
        while(1){
            printf("Green On\n");
            sleep(1);
            printf("Green Off\n");
            sleep(1);
        }
    }
    return EXIT_SUCCESS;
}