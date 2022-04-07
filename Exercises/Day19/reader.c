#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

int fifoFD;

void onInterrupt(int signum){
    close(fifoFD);
    exit(-1);
}

int main(){
    fifoFD = open("myFIFO", O_RDONLY);
    signal(SIGINT, onInterrupt);
    if(fifoFD == -1){
        perror("Could not open FIFO to read.\n");
        exit(-1);
    }
    char buff[100];
    int readCount;
    while(readCount = read(fifoFD, buff, 100)){
        if(readCount == -1){
            perror("Could not read from myFIFO.\n");
        }
        write(STDOUT_FILENO, buff, readCount);
    }
}