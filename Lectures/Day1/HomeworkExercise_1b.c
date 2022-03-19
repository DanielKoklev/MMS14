#include <stdio.h>
#include <math.h>

int main()
{
    double kg, height;
    double bmi = 0;

    scanf("%lf %lf", &kg, &height);


    bmi = 1.3 * (kg / pow(height, 2.5));

    printf("%lf\n", bmi);
}