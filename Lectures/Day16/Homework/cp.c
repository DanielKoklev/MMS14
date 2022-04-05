#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buffer[BUFSIZ];
    int files[2];
    size_t bytes;

    
    if (argc < 3){
        perror("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    files[0] = open(argv[1], O_RDONLY);
    if (files[0] == -1){
        perror("Error opening file.\n");
        return EXIT_FAILURE;
    }
    files[1] = open(argv[2], O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
    if (files[1] == -1){
        perror("Error opening file.\n");
        return EXIT_FAILURE;
    }

    while ((bytes = read(files[0], buffer, sizeof(buffer))) != 0){
        write(files[1], buffer, bytes);
    }
    close(files[0]);
    close(files[1]);

    return EXIT_SUCCESS;
}