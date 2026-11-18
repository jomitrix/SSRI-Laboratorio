#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress_string(const char* s);

int main() {
    char buffer[BUFSIZ];
    char *str;

    fgets(buffer, BUFSIZ, stdin);
    int len = 0;
    while (buffer[len] != '\n' && buffer[len] != '\0') len++;
    buffer[len] = '\0';
    len++; // formatto la stringa pronta per essere dinamica

    str = (char *) malloc(len * sizeof(char));
    strcpy(str, buffer); // copio la statica nella dinamica

    printf("Stringa -> %s\n", compress_string(str));

    free(str);
    return 0;
}


char* compress_string(const char* s) {
    if (s == NULL) printf("\nERRORE: La stringa NON è valida.\n\n");

    char check = s[0];
    int count = 1;
    char app[BUFSIZ] = "";
    char adder[BUFSIZ];
    
    for (int i = 1; i <= strlen(s); i++) {
        if (check == s[i]) count++;
        else {
            sprintf(adder, "%c%d", check, count);
            strcat(app, adder);

            check = s[i];
            count = 1;
        }
    }
    
    char *res = (char *) malloc((strlen(app)+1) * sizeof(char));
    strcpy(res, app);

    return res;
}