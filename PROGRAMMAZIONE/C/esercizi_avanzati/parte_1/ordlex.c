#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 5

int lex(char *s, char *t);
void ordina(char **s, int lung);

int main() {
    char **strings;
    strings = (char **) calloc(L, sizeof(char *));
    if (strings == NULL) exit(-1);
    for (int i = 0; i < L; i++) {
        char buffer[BUFSIZ];
        fgets(buffer, BUFSIZ, stdin);
        buffer[strlen(buffer)-1] = '\0';
        strings[i] = (char *) calloc(strlen(buffer)+1, sizeof(char));
        if (strings[i] == NULL) exit(-1);
        strcpy(strings[i], buffer);
    }
    

    printf("Prima\n");
    for (int i = 0; i < L; i++) {
        printf("s%d: %s\t", i+1, strings[i]);
    }
    
    ordina(strings, L);

    printf("\nDopo\n");
    for (int i = 0; i < L; i++) {
        printf("s%d: %s\t", i+1, strings[i]);
    }

    for (int i = 0; i < L; i++)
    {
        free(strings[i]);
    }

    free(strings);
    
}

int lex(char *s, char *t) {
    int minLenght = (strlen(s) < strlen(t)) ? strlen(s) : strlen(t);

    int i = 0;
    while (i < minLenght && tolower(s[i]) == tolower(t[i])) i++;
    if (tolower(s[i]) > tolower(t[i])) return 2;

    return 1;
    
}

void ordina(char **s, int lung) {
    int sorted = 0;

    while (sorted == 0) {
        sorted = 1;
        for (int i = 0; i < lung-1; i++) {
            if (lex(s[i], s[i+1]) == 2) {
                sorted = 0;
                char *app;
                app = s[i];
                s[i] = s[i+1];
                s[i+1] = app;
            }
        }
        
    }
}