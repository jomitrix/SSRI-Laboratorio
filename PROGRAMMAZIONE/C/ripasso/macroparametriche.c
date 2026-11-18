#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define PARI(a) ((a % 2 == 0) ? (1) : (0) )

int sum(int a, int b);
int sub(int a, int b);
int times(int a, int b);

int main(int argc, char *argv[]) {
    int x = -5, y = -4, i;

    printf("%d\n", PARI(MAX(x, y)));

    printf("\n--------------------\nPuntatori a funzione\n\n");

    int (*oper[])(int, int) = {sum, sub, times};

    printf("Inserisci a, b -> ");
    scanf("%d, %d", &x, &y);
    if (!x || !y) { exit(1); }


    printf("Che operazione fare? 1 somma, 2 sottrazione, 3 prodotto\n> ");
    scanf("%d", &i);
    if (i < 1 || i > 3) { exit(1); }
    printf("\n"), i--;
    
    printf("%d\n", (*oper[i])(x, y));

    return 0;
}

int sum(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int times(int a, int b) {
    return a*b;
}