#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int arr[] = {20, 10, 56, 45, 78, 55, 1, 34};
    int len = sizeof(arr) / sizeof(*arr);

    int fd[2];
    if(pipe(fd) == -1){
        perror("error with pipe");
        return EXIT_FAILURE;
    }
    

    pid_t pid = fork();
    int end, start;
    if(-1 == pid){
        perror("fork error");
        return EXIT_FAILURE;

    } else if(0 == pid){
        close(fd[0]);
        start = 0;
        end = len / 2;
        int sum = 0;

        for(int i = start; i < end; i++){
            sum += arr[i];
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    } else {
        close(fd[1]);
        start = len / 2;
        end = len;
        int sum = 0;
        for(int i = start; i < end; i++){
            sum += arr[i];
        }
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        printf("Sum of parent = %d\n", sum);
        printf("Sum of child = %d\n", sumChild);
        printf("Total = %d\n", sum + sumChild);
        close(fd[0]);
    }
    
    
    if(pid > 0){
        wait(NULL);
    }
    
    return EXIT_SUCCESS;
}