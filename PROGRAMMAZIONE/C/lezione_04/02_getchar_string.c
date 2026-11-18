#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c1, c2;
    do {
        printf("Inserisci c1 -> ");
        c1 = getchar();
    } while (c1 == '\n');
    
    // Pulisco il buffer
    getchar();

    do {
        printf("Inserisci c2 -> ");
        c2 = getchar();
    } while (c2 == '\n');

    printf("%c, %c", c1, c2);

    return 0;
}
