#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv){
    char buffer[BUFSIZ];
    size_t bytes;
    if(argc == 1){
        while((bytes = read(STDIN_FILENO, buffer, BUFSIZ)) > 0){
            write(STDOUT_FILENO, buffer, bytes);
        }
    } else if(argc > 1){

        if(argc =! 2){
            printf("Invalid arguments!\n");
            return EXIT_FAILURE;
        }
        for(int i = 1; i < argc; i++){

            int fd = open(argv[i], O_RDONLY);
            if(fd == -1){
                perror("error info: ");
                return EXIT_FAILURE;
            }
            char buffer[BUFSIZ];
            size_t bytes;
            while((bytes = read(fd, buffer, BUFSIZ)) > 0){
                write(STDOUT_FILENO, buffer, bytes);
            }
            write(STDOUT_FILENO, buffer, bytes);
            close(fd);
        }
    }
    return EXIT_SUCCESS;
}