#include <stdio.h>

int main() {
    double c, f;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &c);

    f = (c * 9 / 5) + 32;
    printf("In Fahrenheit: %.1f\n", f);

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &f);

    c = (f - 32) * 5 / 9;
    printf("In Celsius: %.1f\n", c);

    return 0;
}

