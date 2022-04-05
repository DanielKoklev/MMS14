#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv){
    if (argc != 1 && argc != 2 && argc != 3){
        fprintf(stderr, "Invalid arguments!\n");
        exit(EXIT_FAILURE);
    }
    char name[200];
    int rows;
    int fd;
    if (3 == argc){
        strcpy(name, argv[2]);
        fd = open(name, O_RDONLY);
        rows = atoi(argv[1]);
    } else if (2 == argc){
        strcpy(name, argv[1]);
        fd = open(name, O_RDONLY);
        rows = 10;
    } else {
        fd = STDIN_FILENO;
        rows = 10;
    }
    if (-1 == fd){
        perror("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char ch;
    int n;
    unsigned cnt = 0;
    while (n = read(fd, &ch, 1)){
        if (-1 == n){
            perror("Error reading file.\n");
            exit(EXIT_FAILURE);
        }
        if(-1 == write(STDOUT_FILENO, &ch, 1)){
            perror("Error reading file.\n");
            exit(EXIT_FAILURE);
        }
        if (ch == '\n' && ++cnt == rows){
            break;
        }
    }

    if (argc != 1)
    if (close(fd) == -1){
        perror("Error.\n");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}