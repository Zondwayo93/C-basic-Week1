#include <stdio.h>

int main() {
    int length, width, area;
    
    // Input length and width
    printf("Enter length: ");
    scanf("%d", &length);

    printf("Enter width: ");
    scanf("%d", &width);
    
    // Calculate area
    area = length * width;
   
    // Output
    printf("Area of the rectangle = %d\n", area);

    return 0;
}
