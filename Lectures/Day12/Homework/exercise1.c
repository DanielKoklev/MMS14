#include <stdio.h>
#include <stdint.h>

unsigned char checkBit(unsigned int uValue){
    unsigned int count = 0;
    while(uValue){
        count += uValue & 1;
        uValue >>=1;
    }
    if(count == 1){
        return 1;
    }else{
        return 0;
    }
    

}


int main(){
    
    printf("%x", checkBit(0x600));

    return 0; 
}