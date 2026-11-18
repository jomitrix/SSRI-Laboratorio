#include <stdio.h>

int main(int argc, char const *argv[])
{
    int intero; double ndouble;
    
    printf("Inserisci un numero intero -> ");
    scanf("%d", &intero);
    printf("Inserisci un numero double > ");
    scanf("%lf", &ndouble);

    printf("\nI numeri che hai inserito sono %d e %lf\n", intero, ndouble);

    return 0;
}
