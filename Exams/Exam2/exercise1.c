#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

#define cnt 10
#define EPS 0.0001

typedef struct {
    char model[20];
    uint8_t maxspeed;
    double price;
} car;

int compSpeedAsc(const void*,const void*);
int compSpeedDesc(const void*,const void*);
int compModelAsc(const void*,const void*);
int compModelDesc(const void*,const void*);
int compPriceAsc(const void*,const void*);
int compPriceDesc(const void*,const void*);
int randInt(int, int);
double randDouble(double,double);
void printCars(car*,size_t);
int (*getComparator(int n))(const void*, const void*);




int main(){
    srand(time(NULL));
    car cars[cnt];

    for(int i = 0; i < cnt; i++){
        cars[i].price = randDouble(1000.00, 100000.00);
        cars[i].maxspeed = randInt(100, 300);
        int countLowercase = randInt(4, 10);
        cars[i].model[0] = randInt('A', 'Z');
        for(int j = 1; j < countLowercase; j++){
            cars[i].model[j] = randInt('a', 'z');
        }
        cars[i].model[countLowercase] = 0;
    }
    int n = 0;
    //scanf("Enter number between 1 and 6: %d\n", &n);
    //getComparator(n);

    qsort(cars, cnt, sizeof(cars),compSpeedDesc);
    

    printCars(cars, cnt);

    return 0;
}

int compSpeedAsc(const void* a, const void* b){
    return ((car*)a)-> maxspeed - ((car*)b)->maxspeed;
}

int compSpeedDesc(const void* a, const void* b){
    return ((car*)b)-> maxspeed - ((car*)a)->maxspeed;
}


int compModelAsc(const void* a, const void* b){
    return strcmp(((car*)a)->model, ((car*)b)->model);
}

int compModelDesc(const void* a, const void* b){
    return strcmp(((car*)b)->model, ((car*)a)->model);
}

int compPriceAsc(const void* a, const void* b){
    if(fabs((((car*)a)->price - ((car*)b)->price)) < EPS){
        return 0;
    } else if(((car*)a)->price > ((car*)b)->price){
        return 1;
    }
    return -1;
}

int compPriceDesc(const void* a, const void* b){
    if(fabs((((car*)b)->price - ((car*)a)->price)) < EPS){
        return 0;
    } else if(((car*)b)->price > ((car*)a)->price){
        return 1;
    }
    return -1;
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printCars(car* arr, size_t n){
    for(int i = 0; i < n; i++){
        printf("Model: %s, ", arr[i].model);
        printf("Maxspeed: %d, ", arr[i].maxspeed);
        printf("Price: %.2lf\n, ", arr[i].price);
    }
}

int (*getComparator(int n))(const void*, const void*){
    if(n == 1){
        return compModelAsc;
    } else if(n == 2){
        return compModelDesc;
    } else if (n == 3){
        return compSpeedAsc;
    } else if (n == 4){
        return compSpeedDesc;
    } else if (n == 5){
        return compPriceAsc;
    } else if (n == 6){
        return compPriceDesc;
    } else {
        return 0;
    }

}