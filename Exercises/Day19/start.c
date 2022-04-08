#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
int main(){
    int pid = fork();
    mkfifo("myFIFO", 00600);

    if(pid == -1){
        perror("Problem with forking.\n");
        exit(-1);
    } else if(pid == 0){ // child process
        execl("./reader", "./reader", NULL);

        perror("Creating reader failed.\n");
        exit(-1);
    }
    // Parent
    for(int i = 0; i < 5; i++){
        int pid = fork();
        if(pid == 0){ // new child process
            execl("./writer", "./writer", NULL);

            perror("Creating writer failed.\n");
            exit(-1);
        }
    }
    while(wait(NULL) > 0){
        printf("Waited for 1 process.\n");
    }
    

}