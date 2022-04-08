#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv){
    struct timeval tv1;
    
    gettimeofday(&tv1, NULL);
    printf("Seconds: %ld, Microseconds: %ld\n", tv1.tv_sec, tv1.tv_usec);

    int pid = fork();

    if(pid < 0){
        perror("Fork failed.\n");
        exit(-1);

    } else if (pid == 0){
        //Child
        /*int fd = open(argv[2], O_RDONLY);

        if(fd < 0) {perror("Could not open input file"); exit(-1);}

        dup2(fd, 0);
        close(fd);

        execl(argv[1], argv[1], NULL);
        perror("Exec failed.\n");
        exit(-1);*/
    }
    // Parent
    wait(NULL);
    struct timeval tv2;
    
    gettimeofday(&tv2, NULL);
    printf("Seconds: %ld, Microseconds: %ld\n", tv2.tv_sec, tv2.tv_usec);
    
    long int elapsedUS = (tv2.tv_sec - tv1.tv_sec)*1000000 + (tv2.tv_usec - tv1.tv_usec);

    printf("Elapsed time (uS): %f\n", elapsedUS/1000.);

    return 0;
}