#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(const char *str, int startIndex, int lenght, char *dest);
char* reverse_words(const char* s);

int main() {
    char buffer[BUFSIZ] = "";
    char *s1;

    printf("Inserisci stringa 1: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strlen(buffer)-1] = '\0';
    s1 = (char *) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(s1, buffer);

    char* reversed = reverse_words(s1);
    printf("Reversed string: %s\n", reversed);
    free(reversed);

    return 0;
}

char* reverse_words(const char* s) {
    int len = strlen(s);
    int lastIndex = len-1;
    char buffer[BUFSIZ] = "";
    char app[BUFSIZ];
    for (int i = len-1; i >= 0; i--) {
        if (s[i] == ' ' || i == 0) {
            substring(s, (i == 0) ? i : i+1, (i == 0) ? lastIndex + 1 : lastIndex - i, app);
            i--;
            lastIndex = i;

            strcat(buffer, app);
            if (i != -1) strcat(buffer, " ");
        }
    }

    char *res = (char *) calloc(strlen(buffer), sizeof(char));
    strcpy(res, buffer);

    return res;
}

void substring(const char *str, int startIndex, int lenght, char *dest) {
    strncpy(dest, str + startIndex, lenght);
    dest[lenght] = '\0';
}
