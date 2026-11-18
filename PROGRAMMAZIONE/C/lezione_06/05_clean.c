#include <stdio.h>

int main(void)
{
    void inserisci(char []);
    void clean(char *, char *, char *);

    char str1[BUFSIZ], str2[BUFSIZ], rim[BUFSIZ];

    //Gestione Stringa
    printf("Inserisci stringa 1 -> ");
    inserisci(str1);
    // Inserisci il terminatore di stringa al posto dell'invio a capo
    int k = 0;
    for (; str1[k] != '\n'; k++);
    str1[k] = '\0';
    
    //Gestione Caratteri da rimuovere
    int lenght;
    printf("Quanti caratteri vuoi levare? -> "), scanf("%d", &lenght);
    for(int i = 0; i < lenght; i++) printf("carattere %d -> ", i), scanf(" %c", &rim[i]);
    // Inserisci il terminatore di stringa al posto dell'invio a capo
    rim[lenght] = '\0';

    clean(str1, str2, rim);
    printf("\nLa stringa privata dei caratteri: \"%s\"\n", str2);

    return 0;
}

void inserisci(char str1[BUFSIZ]) {
    do {
        if (fgets(str1, BUFSIZ, stdin) == NULL) printf("\nERRORE: Inserire una stringa NON vuota.\n");
    } while (str1 == NULL);
}


void clean(char *s, char *t, char *rim) {
    int j = 0, m = 0, remove;

    // Iterazione per il controllo della stringa vergine
    for (int i = 0; s[i] != '\0'; i++) {
        // Check per rimuovere il carattere
        remove = 0, m = 0;
        while (rim[m] != '\0' && !remove) {
            // Se il carattere da rimuovere è presente nella stringa triggero il check e ed esco dal ciclo
            if (s[i] == rim[m]) remove = 1;
            m++;
        } 

        // Se il carattere non è da rimuovo lo aggiungo alla stringa output
        // altrimenti non lo aggiungo
        if (!remove) t[j++] = s[i];
    }
    t[j] = '\0';
}