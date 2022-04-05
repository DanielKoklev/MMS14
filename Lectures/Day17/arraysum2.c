#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int arr[] = {20, 10, 56, 45, 78, 55, 1, 34};
    int len = sizeof(arr) / sizeof(*arr);

    pid_t pid = fork();
    int end, start;
    if(-1 == pid){
        perror("fork error");
        return EXIT_FAILURE;
    } else if(0 == pid){
        start = 0;
        end = len / 2;
    } else {
        start = len / 2;
        end = len;
    }
    int sum = 0;
    for(int i = start; i < end; i++){
        sum += arr[i];
    }
    if(pid > 0){
        wait(NULL);
    }
    printf("Sum = %d\n", sum);
    return EXIT_SUCCESS;
}