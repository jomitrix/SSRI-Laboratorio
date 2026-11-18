#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { printf("ERRORE: Parametri NON validi.\nSintassi: ./%s <file_da_stampare>\n\n", argv[0]); exit(1); }
    FILE *read = fopen(argv[1], "r");
    if (read == NULL) { printf("ERRORE: Il file \"%s\" ha fallito l'apertura. Riprova.\n\n", argv[1]); }

    char buffer[BUFSIZ];
    while (!feof(read)) { fgets(buffer, BUFSIZ, read); printf("%s", buffer); }
    printf("\n");

    fclose(read);    

    return 0;
}