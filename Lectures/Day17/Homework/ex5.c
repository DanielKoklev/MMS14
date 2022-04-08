#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
///////////////////////////////////////////////////
//  Сигналът, който не може да бъде маскиран     //
//  е SIGKILL. Той винаги прекратява процеса,    //
//  защото се изпраща директно към операционната //  система, респективно - kernel.            //
///////////////////////////////////////////////////
void onInterrupt(int signum){
    printf("Received signum: %d \n", signum);
}

int main(){

    signal(SIGINT, onInterrupt);
    signal(SIGTSTP, onInterrupt);

    while(1){
        printf("MMS C Camp\n");
        sleep(0.5);
    }
}