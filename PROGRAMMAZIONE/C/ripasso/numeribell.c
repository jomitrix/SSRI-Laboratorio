#include <stdio.h>
#include <stdlib.h>

int fat(int n);
int binom(int n, int k);
int bell(int n);

int main(int argc, char *argv[]) {
    printf("bell di %d = %d\n", 5, bell(5));
    return 0;
}

int bell(int n) {
    // Caso base non valido
    if (n < 0) {
        return -1;
    }

    // Caso base
    if (n == 0 || n == 1) {
        return 1;
    }

    // Caso ricorsivo
    int sum = 0;
    for (int k = 0; k <= n-1; k++) {
        sum+=binom(n-1, k) * bell(k);
    }
    return sum;
}

int fat(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    return (n * fat(n-1));
}

int binom(int n, int k) {
    return fat(n) / (fat(k) * fat(n - k));
}