#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter the operation (+ - * /): ");
    scanf(" %c", &operator);

    printf("Enter Number 1: ");
    scanf("%lf", &num1);

    printf("Enter Number 2: ");
    scanf("%lf", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %lf", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %lf", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %lf", result);
            break;

        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                printf("Result: %lf", result);
            } else {
                printf("Cannot divide by zero!");
            }
            break;

        default:
            printf("Invalid operator!");
    }

    return 0;
}