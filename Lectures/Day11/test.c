#include <stdio.h>
#define SUM(x,y) ((x)+(y))
#define MULT(a,b) ((a)*(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(num1,num2) ((num1)<(num2)?(num1):(num2))
// print the numbers from 1 to 30
#define LOOP 3
#define FORI(start,end) for(int i = start; i <= end; i++) (printf("%d\n", i))




int main(){
    
    #ifdef LOOP
        #if LOOP == 1
            FORI(1, 30);
        #elif LOOP == 2
            int i = 0;
            while (i<30){
                printf("%d\n", i);
                i++;
            }
        #elif LOOP == 3
            int i = 0;
            do{
                printf("%d\n", i);
                i++;
            } while(i<30);
            
        #endif
    #endif

    return 0;
}