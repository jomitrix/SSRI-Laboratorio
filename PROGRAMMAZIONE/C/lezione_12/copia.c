#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { printf("ERRORE: Parametri NON validi.\nSintassi: ./%s <file_di_out>\n\n", argv[0]); exit(1); }
    FILE *write = fopen(argv[1], "r");
    if (write != NULL) {
        fclose(write);  
        char sovr;
        printf("Il file esiste già! Vuoi sovrascriverlo? (y/N)\n> ", argv[1]);
        scanf("%c", &sovr);
        getchar();
        if (sovr != 'y' && sovr != 'Y') { printf("Operazione Annullata.\n"); return 0; }
    }
    write = fopen(argv[1], "w");
    
    char buffer[BUFSIZ];

    printf("Inserisci contenuto per il file (CTRL+D per terminare)\n");
    while (fgets(buffer, BUFSIZ, stdin)) {
        if (fputs(buffer, write) == EOF) { printf("\nERRORE nella scrittura su file.\n"); fclose(write); exit(1);}
    }

    fclose(write);  
    printf("\n\nScrittura Completata.\n");

    return 0;
}