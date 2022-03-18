#include <stdio.h>
#include <math.h>

int main() {
    double height, radius, lenght;
    scanf("%lf %lf %lf", &radius, &lenght, &height);
    double volume = 0;
    double area = 0;
    double square = 0;
    double acosinus = 0;
    // Area = cos-1((r − h) / r) * r2 − (r − h) √(2rh − h2)

    square = sqrt((2 * radius * height) - pow(height, 2));
    acosinus = acos((radius - height) / radius) * pow(radius, 2);
    

    area = acosinus - (radius - height) * square;

    volume = area * lenght;
    printf("%lf\n", volume);

}