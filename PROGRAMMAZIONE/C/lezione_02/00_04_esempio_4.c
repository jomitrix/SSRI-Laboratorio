#include <stdio.h>
#include <float.h>

int main(int argc, char *argv[]) {
    int x, y, r;

    printf("Primo numero -> ");
    scanf(" %d", &x);
    printf("Secondo numero -> ");
    scanf(" %d", &y);

    r = x * y;
    printf("\n");

    if (r >= 0) {
        printf("Il numero è Positivo\n");
    } else {
        printf("Il numero è Negativo\n");
    }

    printf("\nRisultato: %d\n", r);

    return 0;
}
