#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
uint16_t buffer[] = {3213, 5432, 1232, 3213};

int binToTxt(char* bin, char* txt){
    FILE *pbin, *ptxt;
 
    if ((pbin = fopen("mydata.bin","rb")) == NULL){
        return 0;
    }                                 

    if ((ptxt = fopen("myfile.txt","w")) == NULL){     
        fclose(pbin);
        return 0;
    }                                  
    fclose(ptxt);

    fclose(pbin);
    return 1; 
}

int txtToBin(char* txt, char* bin){
    FILE *pbin, *ptxt;
 
    if ((ptxt = fopen("mydata.bin","r")) == NULL){
        return 0;
    }                                 

    if ((pbin = fopen("myfile.txt","wb")) == NULL){     
        fclose(ptxt);
        return 0;
    }                                  
    fclose(ptxt);

    fclose(pbin);
    return 1; 
}

int fileCreationBin(char* bin){
    FILE* pbin;
    if((pbin = fopen("mydata.bin", "wb")) == NULL){
        return 0;
    }
    fwrite(&buffer, sizeof(buffer), 1, pbin);
    fclose(pbin);
    return 1;
}

int fileCreationTxt(char* txt){
    FILE* ptxt;
    if((ptxt = fopen("mydata.txt", "w")) == NULL){
        return 0;
    }

    fgets(buffer, sizeof(buffer), ptxt);
    fclose(ptxt);
    return 1;
}


int main(int argc, char **argv){
    if(argv == "BT"){
        if (fileCreationBin("file.bin") == 0){
            printf("Error creating/opening the file.\n");
        }
        else {
            if (binToTxt("file.bin", "file.txt") == 0){
                printf("Error converting the files.\n");
            }
            else{
                printf("Successfully\n");
            }
        }
        return 0;
    }
    else if(argv == "TB"){
        if (fileCreationTxt("file.bin") == 0){
            printf("Error creating/opening the file.\n");
        }
        else {
            if (binToTxt("file.bin", "file.txt") == 0){
                printf("Error converting the files.\n");
            }
            else{
                printf("Successfully\n");
            }
        }
    } else {
        printf("Invalid argument.\n");
    }
    return 0;
}