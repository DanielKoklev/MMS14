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
     fifoFD = open("myFIFO", O_WRONLY);
     signal(SIGINT, onInterrupt);
    if(fifoFD == -1){
        perror("Could not open FIFO to write.\n");
        exit(-1);
    }
    char buff[100];
    

    while(1){
        int readCount = read(STDIN_FILENO, buff, 100);
        if(readCount == -1){
            perror("Could not read from terminal.\n");
        }
        write(fifoFD, buff, readCount);
    }
}