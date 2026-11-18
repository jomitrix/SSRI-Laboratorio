#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello World\n");

    int intero = 7;
    printf("Valore: %d\n", intero);

    //%c char %d intero
    char carattere = 'a';
    printf("%d %c\n", carattere, carattere);
    printf("%c\n", carattere + 1);

    const int COSTANTE = 3;

    return 0;
}
