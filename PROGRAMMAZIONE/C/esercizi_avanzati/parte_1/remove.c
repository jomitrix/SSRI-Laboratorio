#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_word(const char* str, const char* word);

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

    printf("\nOutput: %s\n", remove_word(s1, s2));

    free(s1);
    free(s2);
}

char* remove_word(const char* str, const char* word) {
    int check = 0, count = 0, index = -1;
    for (int i = 0; i < strlen(str) && count < strlen(word); i++) {
        if (str[i] == word[count]) {
            if (count == 0) { index = i; }
            check = 1;
            count++;
        } else {
            check = 0;
            count = 0;
        }
    }

    if (check == 1 && count == strlen(word)) {
        char buffer[BUFSIZ] = "";
        strncat(buffer, str, index);
        strncat(buffer, str+index+strlen(word), strlen(str)-index+strlen(word));

        char *res = (char *) calloc(strlen(buffer), sizeof(char));
        if (res == NULL) { printf("errore"); return NULL; }
        strcpy(res, buffer);
        return res;
    }


    char *res = (char *) calloc(strlen(str), sizeof(char));
    if (res == NULL) { printf("errore"); return NULL; }
    strcpy(res, str);
    return res;
}