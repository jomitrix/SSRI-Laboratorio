#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Numero di argomenti non valido.");
        exit(1);
    }

    char **strings;
    strings = (char **) malloc((argc-1) * sizeof(char*));
    if (strings == NULL) { printf("ERRORE di MALLOC\n"); exit(1); }

    for (int i = 1; i < argc; i++) {
        strings[i] = argv[i];
    }

    for (int i = 1; i < argc; i++) {
        printf("%s, ", strings[i]);
    }

    return 0;
}