#include <stdio.h>
#include <ctype.h>

int main(void)
{
    void inserisci(char str1[BUFSIZ]);
    int lex(char *s, char *t);

    char str1[BUFSIZ], str2[BUFSIZ];

    printf("Inserisci stringa 1 -> ");
    inserisci(str1);
    printf("Inserisci stringa 2 -> ");
    inserisci(str2);
    
    if (lex(str1, str2)) printf("\nLe stringhe sono ordinate lessicograficamente.\n");
    else printf("\nLe stringhe NON sono ordinate lessicograficamente!\n");

    return 0;
}

void inserisci(char str1[BUFSIZ]) {
    do {
        if (fgets(str1, BUFSIZ, stdin) == NULL) printf("\nERRORE: Inserire una stringa NON vuota.\n");
    } while (str1 == NULL);
}

int lex(char *s, char *t) {
    int check = 1;
    
    int k = 0;
    for (; s[k] != '\0'; tolower(s[k]), (int)s[k], k++);
    s[k] = '\0';
    int l = 0;
    for (; t[l] != '\0'; tolower(s[k]), (int)t[k], l++);
    t[k] = '\0';
    if (l < k) k = l;
    
    int i = 0;
    do {
        if (s[i] > t[i]) check = 0;
        i++;
    } while (i < l && check);

    return check;
}