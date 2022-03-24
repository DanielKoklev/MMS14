#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    char* user = "USER";
    int opt;
    double result = 0;
    int a, b, c = 0;
    
    while ((opt = getopt(argc, argv, ":a:b:c:")) != -1){
        switch (opt){
            case 'a':
                sscanf(optarg, "%d", &a);
                //a = atoi(optarg);
                break;
            case 'b':
                sscanf(optarg, "%d", &b);
                //b = atoi(optarg);
                break;
            case 'c':
                sscanf(optarg, "%d", &c);
                //c = atoi(optarg);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                return EXIT_FAILURE;
            case ':':
                printf("Missing arg for %c\n", optopt);
                return EXIT_FAILURE;
        }
    }
    result = (a-b)*c;
    printf("Result is: %lf\n", result);
    printf("Current user is: %s\n", getenv(user));
    
}