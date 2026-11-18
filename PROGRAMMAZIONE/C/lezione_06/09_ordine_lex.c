#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
#define NUM_STRINGS 3

void ordina(char **, int);
int lex(char *s, char *t);

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
    char *appoggiostr;
    int scambio;

    // Bubble Sort
    do {
        scambio = 0;
        for (int i = 0; i < lung - 1; i++) {
            if (lex(s[i], s[i + 1]) > 0) {  // Confronto con funzione lex implementata
                
                // Scambio
                appoggiostr = s[i];
                s[i] = s[i + 1];
                s[i + 1] = appoggiostr;
                scambio = 1;
            }
        }
    } while (scambio);
}

int lex(char *s, char *t) {
    int i = 0;
    
    // Confronto delle stringhe
    while (s[i] != '\0' && t[i] != '\0') {
        char c1 = tolower(s[i]);
        char c2 = tolower(t[i]);
        
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        i++;
    }

    // Se tutte le lettere sono uguali, la stringa più corta viene prima
    if (s[i] == '\0' && t[i] != '\0') return -1;
    if (s[i] != '\0' && t[i] == '\0') return 1;

    return 0;  // Se sono uguali
}