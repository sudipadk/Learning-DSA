#include <stdio.h>

int power(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * power(x, y - 1);
    }
}

int main() {
    int base, exponent;
    
    printf("Enter the base: ");
    scanf("%d", &base);
    
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    
    int result = power(base, exponent);
    
    printf("Result: %d\n", result);
    
    return 0;
}

