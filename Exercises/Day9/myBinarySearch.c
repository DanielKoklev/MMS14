#include <stdio.h>



int main(){
    int lo = 0, hi = 1000000;
    printf("Think of a number between %d and %d\n", lo, hi);

    while(1){
        int mid = (lo + hi)/2;
        printf("%d?\n", mid);
        char input;
        scanf("%c", &input);
        if(input == '='){
            printf("Congratulations\n");
            return 0;
        }
        if(input == '<'){
            hi = mid;
        }
        if(input == '>'){
            lo = mid;
        }
        scanf("%c", &input);
    }
}