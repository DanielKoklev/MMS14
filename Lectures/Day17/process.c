#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    if(pid == -1){
        perror("error");
        return EXIT_FAILURE;

    } else if(0 == pid){
        for(int i = 0; i<10; i++){
            printf("Hello im child\n");
            sleep(1);
        }
   
    } else {
        for(int i = 0; i<10; i++){
            printf("Hello im parent\n");
            sleep(1);
        }
        wait(NULL);
        printf("Bye bye from parent\n");
    }
    return 0;
}