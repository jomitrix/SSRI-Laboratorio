#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Occ {
    char *str;
    int count;
} Occ;

Occ *contaOccorrenze(char *nomeFile, int *size);
int aggiungiOccorrenza(Occ **list, int *size, char *string);
void sort(Occ **list, int size);
void printOccor(Occ *list, int size);
void freeOcc(Occ **list, int size);

int main() {

    int size;
    Occ *out = contaOccorrenze("abc.txt", &size);
    printOccor(out, size);
    freeOcc(&out, size);

    return 0;
}

Occ *contaOccorrenze(char *nomeFile, int *size) {
    FILE *read;
    Occ *res = NULL; *size = 0;

    read = fopen(nomeFile, "r");
    if (read == NULL) {
        printf("\nERRORE: Il file NON esiste.\n\n");
        return NULL;
    }

    char word[BUFSIZ] = "", add[2] = "-";
    char c;
    int isBuilding = 0;

    while ((c = tolower(getc(read))) != EOF) { 
        if (isalnum(c)) {  
            strncat(word, &c, 1); 
            isBuilding = 1;  // Stiamo costruendo una parola
        } else if (isBuilding) {  
            // Abbiamo finito una parola, la salviamo
            char *occ = (char *) calloc(strlen(word) + 1, sizeof(char));
            strcpy(occ, word);
            aggiungiOccorrenza(&res, size, occ);

            strcpy(word, "");  // Svuoto la parola
            isBuilding = 0;    // Resettiamo il flag
        }
    }
    fclose(read);

    sort(&res, *size);

    return res;
}

int aggiungiOccorrenza(Occ **list, int *size, char *string) {
    if (string == NULL) { printf("\nERRORE: La stringa NON è valida.\n\n"); return -1; }
    
    int isNew = 1;
    for (int i = 0; i < *size && isNew == 1; i++) {
        if (strcmp(string, (*list)[i].str) == 0) {
            (*list)[i].count++;
            isNew = 0;
        }
    }
    if (isNew == 1) {
        *list = (Occ *) realloc(*list, (++(*size)) * sizeof(Occ));
        (*list)[(*size)-1].str = string;
        (*list)[(*size)-1].count = 1;
    }

    return 0;
}

void sort(Occ **list, int size) {
    int sorted = 0;
    while (sorted == 0) {
        sorted = 1;
        for (int i = 0; i < size-1; i++) {
            if ((*list)[i].count < (*list)[i+1].count) {
                Occ app = (*list)[i];
                (*list)[i] = (*list)[i+1];
                (*list)[i+1] = app;
                sorted = 0;
            }
        }
        
    }
}

void printOccor(Occ *list, int size) {
    printf("Elenco Occorrenze:\n");
    for (int i = 0; i < size; i++)   {
        printf("\"%s\" - %d occorrenze\n", list[i].str, list[i].count);
    }
}

void freeOcc(Occ **list, int size) {
    for (int i = 0; i < size; i++)   {
        free((*list)[i].str);
        (*list)[i].str = NULL;
    }

    free(*list);
}