#include <stdio.h>

int main() {
    int num1, num2;

    // Input
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    // Check for division by zero
    if (num2 != 0) {
        int quotient = num1 / num2;
        printf("Sum = %d\n", sum);
        printf("Difference = %d\n", difference);
        printf("Product = %d\n", product);
        printf("Quotient = %d\n", quotient);
    } else {
        printf("Sum = %d\n", sum);
        printf("Difference = %d\n", difference);
        printf("Product = %d\n", product);
        printf("Quotient = Undefned (division by zero)\n");
    }
    
    return 0;
} 
