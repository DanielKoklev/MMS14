#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// unfinished

int main(){
    int num;
    printf("Enter number of wanted forks: ");
    scanf("%d", &num);

    srand(time(NULL));
    char arr[20];
    int n = rand() % (90-65) + 65;
    for(int i = 0; i < strlen(arr); i++){
        arr[i] = n;
    }

    for(int i = 0; i<num; i++){
        pid_t pid = fork();
        if(0 == pid){
            for(int i = 0; i < 10; i++){
                printf("%d\n", arr[i]);
            }
            exit(EXIT_SUCCESS);
        }
    }
    for(int i = 0; i < num; i++){
        wait(NULL);
    }
    return 0;
}