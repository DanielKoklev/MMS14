#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

typedef struct
{
    char name[100];
    int number;
    double grade;

} student;

void printInfo(student);

int main(){

    /*student st1, st2;
    student *sp = &st1;

    strcpy(st1.name, "Ivan");
    st1.grade = 3.50;
    st1.number = 23;

    strcpy(st2.name, "Mitko");
    st2.grade = 5.50;
    st2.number = 3;
    printInfo(st1);
    printInfo(st2);
    printf("Number: %d\n", sp->number);*/

    srand(time(NULL));

    const char names[][10] = {"Ivan", "Zoro", "Miro", "Nadq", "Pesho"};
    student stds[COUNT];
    for (int i = 0; i < COUNT; i++){
        strcpy(stds[i].name, names[rand() % 5]);
        stds[i].number = rand() % 100;
        stds[i].grade = rand() % 100;
    }

    return 0;
}

void printInfo(student st)
{
    printf("Name: %s\n", st.name);
    printf("Number: %d\n", st.number);
    printf("Name: %.2lf\n", st.grade);
}