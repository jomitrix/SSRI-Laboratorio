#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, prod;

    printf("Inserisci due numeri interi (num, num) -> ");
    scanf("%d, %d", &a, &b);

    if ((prod = a*b) < 0) printf ("\nIl risultato è un numero negativo");
    else printf ("\nIl risultato è un numero positivo");
    printf("\nIl risultato della moltiplicazione è %d\n", prod);
    
    return 0;
}