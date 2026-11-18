#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sostituisciFile(char *fileInput, char *remove, char *change, char *fileOutput) {
    FILE *file;
    char **data = NULL;
    int rows = 0;

    if ((file = fopen(fileInput, "r")) == NULL) {
        printf("\nERRORE: Impossibile aprire il file in input.\n\n");
        return -1;
    }
    while (1) {
        data = (char **) realloc(data, (rows + 1) * sizeof(char *));
        data[rows] = (char *) calloc(BUFSIZ, sizeof(char));
        if (fgets(data[rows], BUFSIZ, file) == NULL) {
            free(data[rows]);
            break;
        }
        rows++;
    }
    fclose(file);

    if ((file = fopen(fileOutput, "r")) != NULL) {
        fclose(file);
        char c;
        printf("\nIl file indicato esiste già.\n Sovrascrivere? (y/N) > ");
        scanf(" %c", &c);
        if (c != 'y') return 0;
    }
    if ((file = fopen(fileOutput, "r")) == NULL) { char c; printf("\nIl file indicato esiste già.\n Sovrascrivere? (y/N) > "); scanf(" %c", &c); if (c != 'y') return 0; }
    if ((file = fopen(fileOutput, "w")) == NULL) { printf("\nERRORE: Impossibile aprire il file in output.\n\n"); return -1; }
    char *part1 = NULL, *part2 = NULL;
    char *print = NULL;

    for (int i = 0; i < rows; i++) {
        data[i][strcspn(data[i], "\n")] = '\0';
        print = data[i];

        part2 = strstr(data[i], remove);
        if (part2 != NULL) {
            int len1 = strlen(data[i]) - strlen(part2);
            part1 = (char *)malloc((len1 + 1) * sizeof(char));
            strncpy(part1, data[i], len1);
            part1[len1] = '\0';
            strcpy(part2, part2 + strlen(remove));
            snprintf(print, BUFSIZ, "%s%s%s", part1, change, part2);
            printf("%s\n", print);
        }

        fprintf(file, "%s\n", print);
    }
    
    fclose(file);


    return 0;
}

int main() {
    sostituisciFile("fileers", "ciao", "nig", "puzzo");
}