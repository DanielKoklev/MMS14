#include <stdio.h>

int main(){
    FILE* fp = fopen("myfile.txt", "w");
    char buffer[200];
    while(fgets(buffer, 200, stdin) != NULL){
        fputs(buffer, fp);
    }

    fclose(fp);
    return 0;
}