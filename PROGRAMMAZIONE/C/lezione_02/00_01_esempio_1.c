#include <stdio.h>

int main(int argc, char *argv[]) {
    char c;
    // utilizzo di getchar();
    printf("Inserisci carattere -> ");
    c = getchar(); // la getchar() aspetta che si riempia lo standard input
    printf("carattere: %c\t\tintero carattere: %d\n", c, c);

    c = c+1;
    printf("carattere dopo: %c\tintero carattere dopo: %d\n", c, c);

    //utilizzo di scanf();
    printf("Inserisci carattere -> ");
    scanf(" %c", &c);
    printf ("carattere: %c\n", c);
}
