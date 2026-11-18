#include <stdio.h>

int main(void)
{
    void inserisci(char str1[BUFSIZ]);
    void reverse(char* s, char* t);

    char str1[BUFSIZ], str2[BUFSIZ];
    inserisci(str1);
    
    /* Sovrascrive \n finale */
    int i = 0;
    for (; str1[i] != '\n' && str1[i] != '\0'; i++);
    str1[i] = '\0';

    reverse(str1, str2);

    printf("La stringa al contrario e': %s\n", str2);

    return 0;
}

void inserisci(char str1[BUFSIZ]) {
    do {
        printf("Inserisci una stringa: ");
        if (fgets(str1, BUFSIZ, stdin) == NULL) printf("\nERRORE: Inserire una stringa valida.\n");
    } while (str1 == NULL);
}

void reverse(char* s, char* t) {
    int i = 0;
    while (s[i] != '\0') i++;

    for (int j = 0; j < i; j++)
        t[j] = s[i - 1 - j];
    t[i] = '\0';
}