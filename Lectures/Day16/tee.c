#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc != 2){
        perror("error");
        return EXIT_FAILURE;
    }
    char buffer[BUFSIZ];
    size_t reading;
    int outputfd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC);

    if(outputfd == -1){
        perror("error");
        return EXIT_FAILURE;
    }
    while((reading = read(STDIN_FILENO, buffer, BUFSIZ)) > 0){
        if(write(STDOUT_FILENO, buffer, reading) != reading){
            perror("error");
            return EXIT_FAILURE;
        }
        if(write(outputfd, buffer, reading) != reading){
            perror("error");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;

}