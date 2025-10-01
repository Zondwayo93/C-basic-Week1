#include <stdio.h>

int main() {
    float radius, area;
    float pi = 3.14;

    // Input radius
    printf("Enter radius: ");
    scanf("%f", &radius);

    // Calculate area
    area = 3.14 * radius * radius;

    // Output
    printf("Area of the circle = %f\n", area);

    return 0;
}
