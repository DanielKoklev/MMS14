#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv){

    int i, fd1, fd2;
    char *file1, *file2, buf[2];
    if (argc < 3){
        perror("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    file1 = argv[1];
    file2 = argv[2];
    printf("file1=%s file2=%s", file1, file2);
    fd1 = open(file1, O_RDONLY, 0777);

    if(-1 == fd1){
        perror("Error opening file.\n");
        return EXIT_FAILURE;
    }
    fd2 = creat(file2, 0777);

    if(-1 == fd2){
        perror("Error creating file.\n");
        return EXIT_FAILURE;
    }
    while (i = read(fd1, buf, 1) > 0){
        write(fd2, buf, 1);
    }
    remove(file1);
    close(fd1);
    close(fd2);
    return EXIT_SUCCESS;
}