#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void myPrintErr(char* errMsg){
    if(write(2, errMsg, strlen(errMsg)) == -1){
        write(2, "ERROR\n", 6);
        exit(-1);
    }
}

int main(){
    int fd = open("test", O_RDWR);
    if(fd == -1){
        myPrintErr("Could not open test file.\n");
    }
    char inputBuff[11];
    int byteCount = read(fd, inputBuff, 10);
    if(byteCount == -1){
        myPrintErr("Could not read from file\n");
    }
    write(STDOUT_FILENO, inputBuff, 10);
    int fileSize = lseek(fd, 0, SEEK_END);
    printf("fileSize = %d\n", fileSize);

    char outputBuff[] = "Hello world!";
    lseek(fd, 20, SEEK_SET);
    write(fd, outputBuff, strlen(outputBuff));
    close(fd);
    return 0;
}