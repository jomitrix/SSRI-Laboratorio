#include <stdio.h>

int main(int argc, char const *argv[])
{
    char frase[BUFSIZ];
    int i = 0;

    printf("Inserisci una frase\n>> ");
    
    // scanf("%s", frase);
    fgets(frase, BUFSIZ, stdin);

    printf("\nHai scritto: ");
    
    while (frase[i] != '\n')
    {
        printf("%c", frase[i]);
        i++;
    }

    printf("\nLunghezza stringa: %d\n", i);
    
    return 0;
}
