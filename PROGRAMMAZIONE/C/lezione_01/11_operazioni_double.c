#include <stdio.h>

int main(int argc, char const *argv[])
{
    double a, b;

    printf("Programma per tutte le operazioni con i due numeri\n--------------------------------\n\n");
    printf("Inserisci due numeri double (num, num) > ");
    scanf("%lf, %lf", &a, &b);

    printf("Somma: %lf\tSottrazione: %lf\tProdotto: %lf\tDivisione: %lf\n", a+b, a-b, a*b, a/b);

    return 0;
}
