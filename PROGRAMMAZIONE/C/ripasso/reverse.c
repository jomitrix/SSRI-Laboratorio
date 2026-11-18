#include <stdio.h>

void reverse(char *str, char *rev);

int main(int argc, char *argv[]) {
    char str[BUFSIZ] = "Ciao\0";
    char rev[BUFSIZ] = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";

    reverse(str, rev);
    printf("%s\t%s\n", str, rev);

    return 0;
}

void reverse(char *str, char *rev) {
    int len = 0, i;
    while (str[len] != '\0' && str[len] != '\n') { len++; }
    str[len] = '\0';

    for (i = 0; --len >= 0; i++) {
        rev[i] = str[len];
    }
    rev[i] = '\0';
}