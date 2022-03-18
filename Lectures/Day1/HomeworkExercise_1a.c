#include <stdio.h>
#include <math.h>

int main()
{
    double kg, height;
    double bmi = 0;

    scanf("%lf %lf", &kg, &height);


    bmi = kg / pow(height, 2);

    printf("%lf\n", bmi);
}