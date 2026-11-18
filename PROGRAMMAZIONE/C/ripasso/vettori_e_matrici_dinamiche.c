#include <stdio.h>
#include <stdlib.h>

#define col 3
#define row 2

void stampaArrayDin(int *);
void stampaMatrDin(int **);
void stampaArrString(char **);

int main(int argc, char *argv[]) {
    int *v;
    v = (int *) calloc(col, sizeof(int));
    if (v == NULL) { printf("CALLOC FAIL v"); exit(1); }
    for (int i = 0; i < col; i++) { *(v+i) = i; }

    int **m;
    m = (int **) calloc(row, sizeof(int *));
    if (m == NULL) { printf("CALLOC FAIL m"); exit(1); }
    for (int i = 0; i < row; i++) { m[i] = (int *) calloc(col, sizeof(int)); if (m[i] == NULL) { printf("CALLOC FAIL m[%d]", i); exit(1); } }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m[i][j] = i+j;
        }
    }

    char **strings;
    strings = (char **) calloc(row, sizeof(char *));
    if (strings == NULL) { printf("CALLOC FAIL strings"); exit(1); }
    
    for (int i = 0; i < col; i++) {
        strings[i] = (char *) calloc(col, sizeof(char));
        if (strings == NULL) { printf("CALLOC FAIL strings[%d]", i); exit(1); }

        char appoggio[BUFSIZ];
        printf("strings[%d] = ", i);
        fgets(appoggio, BUFSIZ, stdin);
        int j;
        for (j = 0; appoggio[j-1] != '\n'; j++) {
            strings[i][j] = appoggio[j];
        }
        strings[i][j-1] = '\0';
    }

    printf("\n-------------------------\n\n");

    stampaArrayDin(v);
    stampaMatrDin(m);
    stampaArrString(strings);
    
    free(v);

    for (int i = 0; i < row; i++) {
        free(m[i]);
        free(strings[i]);
    }
    free(m);
    free(strings);
    

    return 0;
}

void stampaArrayDin(int *v) {
    printf("Array Dinamico:\n[\t");
    for (int i = 0; i < col; i++) {
        printf("%d\t", v[i]);
    }
    printf("]\n");
}

void stampaMatrDin(int **m) {
    printf("\nMatrice Dinamica:\n");
    for (int i = 0; i < row; i++) {
        printf("[\t");
        for (int j = 0; j < col; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("]\n");
    }
}

void stampaArrString(char **str) {
    printf("\nArray di Stringhe:\n");
    printf("[\t");
    for (int i = 0; i < col; i++) {
        printf("%s\t", str[i]);
    }
    printf("]\n");
}