#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define NUM_STRINGS 3

void ordina(char **, int);

int main() {
    char *ptrs[NUM_STRINGS];
    char buffer[MAX_LENGTH];
    char strings[NUM_STRINGS][MAX_LENGTH];
    // Acquisizione delle stringhe dall'utente
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("Inserisci la stringa %d: ", i + 1);
        fgets(buffer, MAX_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(strings[i], buffer);
        ptrs[i]=strings[i];
    }
    // Ordina le stringhe per lunghezza
    ordina(ptrs, NUM_STRINGS);
    
    // Stampa le stringhe ordinate
    printf("\nStringhe ordinate per lunghezza:\n");
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", ptrs[i]);
    }
    return 0;
}

void ordina(char **s, int lung) {
    int lunghezze[NUM_STRINGS], j, scambio = 1;
    int appoggio; char *appoggiostr;

    for (int i = 0; i < lung; i++) {
        for (j = 0; s[i][j] != '\0'; j++);
        lunghezze[i] = j;
    }

    // Bubble Sort
    while (scambio) {
        scambio = 0;
        for (int i = 0; i < lung - 1; i++) {
            if (lunghezze[i] > lunghezze[i + 1]) {
                // scambio lunghezze
                appoggio = lunghezze[i];
                lunghezze[i] = lunghezze[i + 1];
                lunghezze[i + 1] = appoggio;

                // scambio pointers
                appoggiostr = s[i];
                s[i] = s[i + 1];
                s[i + 1] = appoggiostr;

                scambio = 1;
            }
        }
    }
}