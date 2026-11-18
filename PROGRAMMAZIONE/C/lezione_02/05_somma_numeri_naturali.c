#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n, somma = 0, sommatoria, sommap = 0, sommatoriap, sommac = 0, sommatoriac;
    
    do {
        printf("Fino a che numero vuoi sommare i numeri naturali? (almeno 1)\n> ");
        scanf("%d", &n);
    } while (n < 1);
    
    for (int i = 1; i <= n; i++) {
        somma += i;
        sommap += pow(i, 2);
        sommac += pow(i, 3);
    }

    sommatoria = n * (n + 1) / 2;
    sommatoriap = n * (n + 1) * (2 * n + 1) / 6;
    sommatoriac = pow(n,2) * pow(n+1,2) / 4;

    printf("\nSomma primi n naturali\n-------------------\nSomma = %d\nSommatoria = %d\n\n", somma, sommatoria);
    printf("\nSomma primi n quadrati naturali\n-------------------\nSomma = %d\nSommatoria = %d\n\n", sommap, sommatoriap);
    printf("\nSomma primi n cubi naturali\n-------------------\nSomma = %d\nSommatoria = %d\n\n", sommac, sommatoriac);

    return 0;
}
