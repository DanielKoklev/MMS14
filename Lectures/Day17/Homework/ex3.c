#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int forkCommand(const char* cmd){

    pid_t pid = fork();
    if (-1 == pid){
        perror("Problem with forking.\n");
        exit(EXIT_FAILURE);

    } else if (pid == 0){
        if (-1 == execlp(cmd, cmd, NULL)){
            perror("Problem with executing command.\n");
            exit(EXIT_FAILURE);
        }
    }

    int status;
    wait(&status);
    return WEXITSTATUS(status);
}

int main(int argc, char **argv){

    if (argc != 3){
        perror("Too many/less arguments.\n");
        exit(EXIT_FAILURE);
    }
    int exitStatus = forkCommand(argv[1]);
    if (EXIT_SUCCESS == exitStatus){
        return EXIT_FAILURE;
    }
    exitStatus = forkCommand(argv[2]);
    if (EXIT_SUCCESS == exitStatus){
        return EXIT_FAILURE;
    }
    return exitStatus;
}