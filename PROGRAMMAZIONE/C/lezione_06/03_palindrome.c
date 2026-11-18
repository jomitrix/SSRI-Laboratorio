#include <stdio.h>

int main(void)
{
    void inserisci(char str1[BUFSIZ]);
    void palindroma(char* s);

    char str1[BUFSIZ];
    inserisci(str1);

    palindroma(str1);

    return 0;
}

void inserisci(char str1[BUFSIZ]) {
    printf("Inserisci una stringa: ");
    do {
        if (fgets(str1, BUFSIZ, stdin) == NULL) printf("\nERRORE: Inserire una stringa valida.\n");
    } while (str1 == NULL);
}

void palindroma(char* s) {
    int i = 0;
    while (s[i] != '\0') i++;

    int j = 0, check = 1;

    while (j < (i / 2) && check) {
        if (s[j] != s[i - j - 2]) check = 0;
        j++;
    }

    if (check) printf("\nLa stringa è palindroma.\n");
    else printf("\nLa stringa NON è palindroma!\n");
}
