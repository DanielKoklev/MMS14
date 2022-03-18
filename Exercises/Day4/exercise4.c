#include <stdio.h>

int main() {
    int n, curInput, lastInput = 0, curLenght = 0, curStartIndex = 0;
    int maxLenght = 0, maxStartIndex;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &curInput);

        if(curInput < lastInput) {
            printf("\n startIndex:%d  lenght:%d     \n", curStartIndex, curLenght);

            curLenght = 1;
            curStartIndex = i;
            
        } else {
            curLenght++;
        }
        if(curLenght > maxLenght){

            maxLenght = curLenght;
            maxStartIndex = curStartIndex;
        }
        printf("%d  ", curInput);

        lastInput = curInput;

    }
    
    printf("STARTINDEX: %d    LENGHT: %d\n", maxStartIndex, maxLenght);
    return 0;
}