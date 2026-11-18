#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expand_range(const char* s);

int main() {
    char buffer[BUFSIZ];
    char *s1;

    printf("Inserisci stringa 1: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strlen(buffer)-1] = '\0';
    s1 = (char *) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(s1, buffer);

    expand_range(s1);

    free(s1);
}

char* expand_range(const char* s) {
    char buffer[BUFSIZ] = "";

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '-' && i != 0 && i < strlen(s)-1) {
            int start = s[i-1] + 1;
            char add[2] = "-";
            for (int j = start; j < (int) s[i+1]; j++) {
                add[0] = (char) j;
                strcat(buffer, add);
            }
            
        } else { strncat(buffer, s+i, 1); }

        printf("test: %s\n", buffer);
    }
}
