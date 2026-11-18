#include <stdio.h>

int fibonacci(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;

    int p = fibonacci(n-1) + fibonacci(n-2);
    printf("%d\n", p);
    return p;
}

int main() {
    printf("fibonacci di %d: %d\n", 100, fibonacci(10));
}