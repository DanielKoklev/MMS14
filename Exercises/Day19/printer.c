#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void onInterrupt(int signum){
    printf("Received signum: %d \n", signum);
}

int main(){

    signal(SIGINT, onInterrupt);

    while(1){
        printf("a\n");
        sleep(1);
    }
}