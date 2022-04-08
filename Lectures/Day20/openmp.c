#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(){

    /*#pragma omp parallel num_threads(10)
    {
        int id = omp_get_thread_num();
        printf("Hello from thread: %d\n", id);
        printf("HAHA from thread: %d\n", id);
    }*/


    /*#pragma omp parallel for num_threads(20)
    for(int i = 0; i < 20; i++){
        sleep(1);
        printf("%d\n", i);
    }*/

    /*int a[] = {20, 30, 40, 50, 60};
    int b[] = {5, 1, 3, 6, 2};
    int c[5];
    #pragma omp parallel for num_threads(3)
    for(int i = 0; i < 5; i++){
        c[i] = a[i] + b[i];
    }

    for(int i = 0; i < 5; i++){
        printf("%d\n", c[i]);
    }*/
    //omp_lock_t mux;
    int n = 0;
    //omp_init_lock(&mux);
    #pragma omp parallel num_threads(100)
    {
        for(int i = 0; i < 100; i++){
            //omp_set_lock(&mux);
            #pragma omp critical
            n++;
            //omp_unset_lock(&mux);
        }
    }
    //omp_destroy_lock(&mux);
    printf("N = %d\n", n);

    return 0;
}