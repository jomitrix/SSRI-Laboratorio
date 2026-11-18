#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *occorrenze(char *fileRead, int numToRead);

int main() {
    printf("final: %s\n", occorrenze("a", 30));
}

char *occorrenze(char *fileRead, int numToRead) {
    char *res = NULL; int size = 1;
    char adder[2] = "";

    FILE *read = fopen(fileRead, "r");
    if (read == NULL) {
        printf("\nERRORE: Il file da leggere NON esiste.\n\n");
        return NULL;
    }

    res = (char *) malloc(sizeof(char));
    if (res == NULL) { printf("\nERRORE: Memoria Insufficiente.\n\n"); fclose(read); return NULL; }
    res[0] = '\0';

    int i = 0;
    while ((adder[0] = getc(read)) != EOF && i < numToRead) {
        if (strstr(res, adder) == NULL) {
            res = (char *) realloc(res, (++size) * sizeof(char));
            if (res == NULL) { printf("\nERRORE: Memoria Insufficiente.\n\n"); fclose(read); return NULL; }

            strcat(res, adder);
        }
        i++;
    }
    fclose(read);

    return res;
}