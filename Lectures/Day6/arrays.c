#include <stdio.h>
#define COUNT 5


int main(){
    int nums[COUNT];
    /*for(int i = 0; i < COUNT; i++){
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i < COUNT; i++){
        printf("nums[%d] = %d\n", i, nums[i]);
    }*/

    for(int i = 0; i < COUNT; i++){
        scanf("%d", nums + i);
    }
    for(int i = 0; i < COUNT; i++){
        printf("nums[%d] = %d\n", i, *(nums + i));
    }
    
    
    /*for(int i = 0; i < 5; i++){
        printf("nums[%d] = %d\n", i, nums[i]);
    }

    // different kind of initialization(in this kind there is no need for declaring the size of the array)
    int nums2[] = {10, 2, 3, 6};

    printf("%p\n", nums);
    printf("%d\n", *(nums2 + 1)); // displaying the second el of the array (ptr + n = ptr + n^sizeof)*/

    return 0;

}