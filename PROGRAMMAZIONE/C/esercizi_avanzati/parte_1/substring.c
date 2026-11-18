#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(const char *, int, int, char *);

int main() {
    char s1[] = "Ciao sono lollo";
    char dest[BUFSIZ];

    substring(s1, 5, 11, dest);

    printf("dest: %s\n", dest);

    return 0;
}

void substring(const char *str, int startIndex, int lenght, char *dest) {
    strncat(dest, str + startIndex, lenght);
    dest[lenght+1] = '\n';
}