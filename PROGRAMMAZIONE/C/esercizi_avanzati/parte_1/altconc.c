#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_alternate(const char* s1, const char* s2);

int main() {
    char buffer[BUFSIZ];
    char *s1, *s2;

    printf("Inserisci stringa 1: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strlen(buffer)-1] = '\0';
    s1 = (char *) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(s1, buffer);
    
    printf("Inserisci stringa 2: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strlen(buffer)-1] = '\0';
    s2 = (char *) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(s2, buffer);

    printf("\nOutput: %s\n", concat_alternate(s1, s2));

    free(s1);
    free(s2);
    
    return 0;
}

char* concat_alternate(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) { printf("\nERRORE: Le stringe NON sono valide.\n\n"); return NULL; }

    int minLenght = (strlen(s1) < strlen(s2)) ? strlen(s1) : strlen(s2);
    char app[BUFSIZ] = "";
    char adder[BUFSIZ];

    for (int i = 0; i < minLenght; i++) {
        sprintf(adder, "%c%c", s1[i], s2[i]);
        strcat(app, adder);
    }

    if (strlen(s1) != strlen(s2)) {
        if (strlen(s1)<strlen(s2)) strncat(app, s2 + minLenght, strlen(s2)-minLenght);
        else strncat(app, s1 + minLenght, strlen(s1)-minLenght);
    }

    char *res = (char *) calloc(strlen(app)+1, sizeof(char));
    if (res == NULL) { printf("\nERRORE di Allocazione memoria.\n\n"); return NULL; }
    strcpy(res, app);

    return res;
}