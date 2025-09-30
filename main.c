#include <stdio.h>
int main() {
    // Printing personal information
    char name[50];
    int age;
    printf("My name is Peter.\n");
    printf("I am 21 years old.\n");
    printf("My favorite hobby is basketball.\n\n");

    // Asking for user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age:");
    scanf("%d", &age);

    printf("Hello %s your are %d years old.\n", name, age);

    return 0;
}

