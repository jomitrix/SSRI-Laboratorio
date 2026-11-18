#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char stringa[BUFSIZ], c;
    int i = 0;

    printf("Inserisci una parola -> ");
    scanf("%s", stringa);

    while ((getchar()) != '\n');

    printf("Inserisci un carattere -> ");
    scanf("%c", &c);
    
    printf("\n");

    if (stringa[strlen(stringa)-1] == c)
        printf("La stringa termina con il carattere %c\n", c);
    else
        printf("La stringa NON termina con il carattere %c\n", c);

    return 0;
}
