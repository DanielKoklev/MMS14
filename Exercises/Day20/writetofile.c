#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd = open("testFile", O_CREAT | O_WRONLY, 00600);
    if(fd == 0) {perror("Error opening file.\n");}

    dup2(fd, 1);
    close(fd);
    for(int i = 0; i < 10; i++){
        printf("%d ", i);
    }

    printf("\n");
    execl("./sum", "./sum", NULL);
    perror("Exec failed.\n");
    exit(-1);
}