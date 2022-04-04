#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char buffer[BUFSIZ];
    size_t bytes;
    while(bytes = read(STDIN_FILENO, buffer, BUFSIZ) > 0){
        write(STDOUT_FILENO, buffer, bytes);
    }
    return 0;
}