#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rimuoviDoppi(char *fileinput, char *fileoutput);

int main() {
    rimuoviDoppi("a", "b");

    return 0;
}

void rimuoviDoppi(char *fileinput, char *fileoutput) {
    FILE *read;
    char add[2] = "-";
    char res[BUFSIZ] = "";

    read = fopen(fileinput, "r");
    if (read == NULL) {
        printf("\nERRORE: Il file non esiste.\n\n");
        return;
    }

    while ((add[0] = getc(read)) != EOF) {
        if (strstr(res, add) == NULL && isalnum(add[0])) {
            strcat(res, add);
        }
    }
    fclose(read);

    FILE *write;
    write = fopen(fileoutput, "r");
    if (write != NULL) {
        printf("\nATTENZIONE: Il file da scrivere è già presente\nSovrascrivere? (y/N): ");
        if ((getchar()) != 'y') {
            printf("Operazione Annullata.\n");
            getchar(); //pulisco
            fclose(write);
            return;
        }
        getchar(); //pulisco
        fclose(write);
    }
    
    if ((write = fopen(fileoutput, "w")) == NULL) {
        printf("\nERRORE: Apertura in scrittura NON riuscita.\n\n");
        return;
    }

    fprintf(write, "%s", res);
    fclose(write);

    printf("Operazione Effettuata con Successo.\n");
    return;
}