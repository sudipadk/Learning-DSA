#include <stdio.h>

// Recursive function to find factorial
int fact(int y) {
    if (y == 0)
        return 1;
        else
    return y * fact(y - 1);
}

int main() {
    int x = 5;
    printf("The factorial of the number is %d", fact(x));
    return 0;
}
