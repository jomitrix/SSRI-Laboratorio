#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Si scriva un programma che chieda all’utente quante parole voglia inserire.
// Tali parole (senza spazi o caratteri speciali) dovranno essere inserite in un array di
// puntatori a stringhe di dimensione N = 20. Per ciascuna di tale parole, inserite
// dall’utente, si allochi dinamicamente una nuova stringa della dimensione esatta
// della parola inserita. Stampare a schermo la frase ottenuta.

#define MAX_PAROLE 20

int main() {
    char **arrstr;
    char app[BUFSIZ];
    int size;

    arrstr = (char **) malloc(MAX_PAROLE * sizeof(char *));

    printf("Quante parole vuoi inserire? -> ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_PAROLE) { printf("\nERRORE: Numero parole NON valido.\n"); exit(1); }

    while (getchar() != '\n');

    for (int i = 0; i < size; i++) {
        printf("parola %d: ", i+1);
        fgets(app, BUFSIZ, stdin);
        
        int j = 0;
        while(app[j] != ' ' && app[j] != '\n' && app[j] != '\0') { j++; }
        app[j] = '\0';

        arrstr[i] = (char *) calloc(j+1, sizeof(char));
        if (arrstr[i] == NULL) printf("\nERRORE: Memoria Insufficiente.\n"), exit(1);
        strcpy(arrstr[i], app);
    }
    
    // Print frase
    printf("\nFrase:\n\" ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arrstr[i]);
    }
    printf("\"\n");

    for (int i = 0; i < size; i++) free(arrstr[i]);
    free(arrstr);

    return 0;
}