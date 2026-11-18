#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char stringa[BUFSIZ];
    printf("Inserisci una stringa -> "); 
    fgets(stringa, BUFSIZ, stdin);

    for (int i = 0; i < strlen(stringa); i++) stringa[i] = toupper(stringa[i]);
    printf("\nStringa Maiuscola: %s", stringa);
    
    return 0;
}
