#include <stdio.h>
#include <stdint.h>

int checkBit(uint32_t mask, unsigned bit){
    return !!(mask & (1 << bit));
}

void setBitP(uint32_t* mask, unsigned bit){
    *mask |= (1 << bit);
}
void clearBitP(uint32_t* mask, unsigned bit){
    *mask &= ~(1 << bit);
}

void changeBitP(uint32_t* mask, unsigned bit){
    *mask ^= (1 << bit);
}

int main(void)
{
    uint32_t attendance = 0;
    int option;
    int bit = 0;

    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        if (option == 1){
            printf("Enter the class number: \n");
            scanf("%d", &bit);
            if(bit > 32){
                printf("No such class number\n");
            }
            setBitP(&attendance, (bit - 1));
        }
        else if (option == 2){
            printf("Enter the class number: \n");
            scanf("%d", &bit);
            if(bit > 32){
                printf("No such class number\n");
            }
            clearBitP(&attendance, (bit - 1));
        }
        else if (option == 3){
            for (int i = sizeof(uint32_t) * 8 - 1; i >= 0; i--){
                printf("%d", checkBit(attendance, i));
            }
            printf("\n");
        }
        else if (option == 4){
            printf("Enter the class number: \n");
            scanf("%d", &bit);
            if(bit > 32){
                printf("No such class number\n");
            }
            changeBitP(&attendance, (bit - 1));
        }
        else if (option == 5){
            break;
        }
        else {
            printf("Invalid option\n");
        }
    }
    return 0;
}
