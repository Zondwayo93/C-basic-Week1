#include <stdio.h>

int main() {
    float radius, height, volume;
    float pi = 3.14;

    // Input radius and height 
    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("Enter height: ");
    scanf("%f", &height);

    // Calculate volume
    volume = 3.14 * radius * radius * height;

    // Output
    printf("Volume of the cylinder = %f\n", volume);

    return 0;
}
