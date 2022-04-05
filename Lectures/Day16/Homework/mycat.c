#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Invalid arguments!\n");
        exit(EXIT_FAILURE);
    }
    int fd = open(argv[1], O_RDONLY);
    if (-1 == fd){
        perror("Opening");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFSIZ];
    int bytes;
    while (bytes = read(fd, buffer, BUFSIZ)){
        if (-1 == bytes){
            perror("Reading");
            exit(EXIT_FAILURE);
        }
        if (write(STDOUT_FILENO, buffer, bytes) == -1){
            perror("Writing");
            exit(EXIT_FAILURE);
        }
    }
    if (close(fd) == -1){
        perror("Closing");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}