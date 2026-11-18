#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    float medial = 0.0;
    char stringa[BUFSIZ];

    do {
        printf("Inserisci stringa (INVIO per terminare)\n>> ");
        fgets(stringa, BUFSIZ, stdin);
        if (stringa[0] != '\n') {
            i++;
            medial += strlen(stringa)-1;
        }
        
    } while (stringa[0] != '\n');

    medial /= i;
    printf("\nLa media della lunghezza delle stringhe è %f\n", medial);

    return 0;
}
