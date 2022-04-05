#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* fp = fopen("test", "r+");
    if(fp == NULL){
        fprintf(stderr, "Could not open file.\n");
        exit(-1);
    }
    char inputbuff[11];
    if(10 != fread(inputbuff, 1, 10, fp)){
        fprintf(stderr, "Could not read from file.\n");
        exit(-1);
    }
    fprintf(stdout, "First 10 symbols: %s\n", inputbuff);
    //fclose(fp);
    
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fprintf(stdout, "File is %d symbols long\n", fileSize);

    char outputbuff[] = "Hello world!";
    fseek(fp, 20, SEEK_SET);
    if(strlen(outputbuff) != fwrite(outputbuff, 1, strlen(outputbuff), fp)){
        fprintf(stderr, "Could not write to file.\n");
        exit(-1);
    }
    fclose(fp);
    return 0;
}