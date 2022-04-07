#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid == -1){
        perror("Problems with forking.\n");
        exit(-1);
    }else if(pid == 0){
        printf("hello from child. Parent ID = %d\n", getppid());
        for(int i = 0; i < 10; i++){
            printf("%d \n", i);
        }
    } else {
        printf("hello from parent. Child ID = %d\n", pid);
        for(int i = 10; i < 20; i++){
            int status;
            wait(&status);
            printf("%d \n", i);
        }
    }

}