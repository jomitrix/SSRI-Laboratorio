#include <stdio.h>
#include <stdlib.h>

long long unsigned int catalan(long long unsigned int);

int main(int argc, char *argv[]) {
    int n;
    printf("Inserisci numero: ");
    scanf("%d", &n);
    printf("Numero di Catalan: ");
    catalan(n);
    printf("\n");
    return 0;
}

long long unsigned int catalan(long long unsigned int n) {
    // caso base
    if (n == 0) {
        printf("1, ");
        return 1;
    }
    // caso ricorsivo
    long long unsigned int risultato = (2 * (2*n - 1) * catalan(n - 1)) / (n + 1);
    printf("%d, ", risultato);
    return risultato;
}