#include <stdio.h>

int main() {
    double a, b, result;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("Choose operation (+, -, *, /): ");
    scanf(" %c", &op);

    if (op == '+') {
        result = a + b;
    }
    if (op == '-') {
        result = a - b;
    }
    if (op == '*') {
        result = a * b;
    }
    if (op == '/') {
        result = a / b;
    }

    printf("Result = %.2f\n", result);

    return 0;
}
