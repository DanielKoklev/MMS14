#include <stdio.h>
#include <math.h>

int main() {
    double height, radius;
    scanf("%lf %lf", &radius, &height);
    double volume = 0;
    double area = 0;

    area = M_PI * pow(radius, 2);

    volume = area * height;
    printf("%lf", volume);

}