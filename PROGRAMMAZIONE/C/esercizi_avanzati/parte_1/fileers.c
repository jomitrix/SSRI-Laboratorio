#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 255

char **fun(char *nomefile, int *rowCount);

int main() {
    int count;
    char **a;
    fun("test.txt", &count);
    return 0;
}

char **fun(char *nomefile, int *rowCount) {
    char **res = NULL;
    *rowCount = 0;
    FILE *read;

    if ((read = fopen(nomefile, "r")) == NULL) { printf("\nERRORE: Il file NON esiste.\n\n"); return NULL; }
    do {
        (*rowCount)++;
        res = (char **) realloc(res, (*rowCount) * sizeof(char *));
        res[*rowCount-1] = (char *) calloc(MAXCHAR, sizeof(char));
    } while (fgets(res[*rowCount-1], MAXCHAR, read) != NULL);
    
    fclose(read);

    int sorted = 0;
    while (sorted != 1) {
        sorted = 1;
        for (int i = 0; i < *rowCount-1; i++) {
            if (strlen(res[i]) > strlen(res[i+1])) {
                char *app = res[i];
                res[i] = res[i+1];
                res[i+1] = app;
                sorted = 0;
            }
        }
    }

    for (int i = 0; i < *rowCount; i++) {
        res[i][strcspn(res[i], "\n")] = '\0';
        printf("%s\n", res[i]);
    }
    
    return res;
}