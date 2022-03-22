#include <stdio.h>

int main(){
    int num;
    int cnt = 0;
    scanf("%d", &num);

    while(num != 0){
        num >>= 1;
        cnt++;
    }
    printf("%d\n", cnt);
}