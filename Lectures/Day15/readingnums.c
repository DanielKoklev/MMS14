#include <stdio.h>

int main(){
    FILE* fp = fopen("myfile.txt", "r");
    int a, b;
    fscanf(fp, "%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    fclose(fp);
    return 0;
}