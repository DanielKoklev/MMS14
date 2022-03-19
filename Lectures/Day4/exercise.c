#include <stdio.h>
#include <stdint.h>

int setBit(uint32_t mask, unsigned bit) {
    return mask | (1 << bit);
}

int checkBit(uint32_t mask, unsigned bit) {
    return !!(mask & (1 << bit));
}


int main() {
    uint32_t attendance = 0;
    int option;
    int classNumber;
    

    while (1) {

        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter the attendance 0 or 1 and the class number: \n");
            scanf("%d %d",&attendance, &classNumber);
            setBit(attendance, classNumber);
        }
        else if (option == 2)
        {
        // to do
        }
        else if (option == 3)
        {
            for (int i = sizeof(uint32_t) * 8; i >= 0; i--) {
                printf("%d", checkBit(attendance, i));
            }
            printf("\n");
        }
        else if (option == 4)
        {

        }
        else
        {
            break;
        }
    }
    return 0;
}