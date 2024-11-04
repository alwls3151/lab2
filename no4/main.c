#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0.0;
    }
    return (double)a / b;
}

int main() {
    int a = 20, b = 10;
    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    printf("Multiply: %d\n", multiply(a, b));
    printf("Divide: %.2f\n", divide(a, b));
    return 0;
}
