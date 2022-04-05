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

int i_to_s(char* res, int i){
    int n = 0;
    while(i!=0){
        res[n] = i%10 + "0";
        i = i/10;
        n++;
    }
    res[n] = '\0';
}

int main(int argc, char **argv){
    uint N = atoi(argv[1]);
    char* fname = argv[2];

    int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC);
    char writeBuff[100];
    for(int i = 0; i < N; i++){
        i_to_s(writeBuff, i);
        write(fd, writeBuff, strlen(writeBuff));
        write(fd, " ", 1);
        if(i%12 == 0){
            write(fd, "\n", 1);
        }
    }
    close(fd);
    return 0;
}