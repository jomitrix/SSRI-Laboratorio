#include <stdio.h>
#include <stdlib.h>

int lung(char *str);
int occ(char *, char);

int main(int argc, char *argv[]) {
    char str[BUFSIZ]; int size = 0;

    fgets(str, BUFSIZ, stdin);
    while (str[size] != '\n') { size++; }
    str[size] = '\0';
    printf("\n%s\n", str);
    printf("lung: %d\n", lung(str));
    printf("occ di c: %d\n", occ(str, 'c'));

    return 0;
}

int lung(char *str) {
    if (str == NULL) {
        return -1;
    }
    if (*str == '\0') {
        return 0;
    }

    return 1 + lung(str + 1);
}

int occ(char *str, char c) {
    if (*str == '\0' || str == NULL) {
        return 0;
    }

    if (*str == c) {
        return 1 + occ(str + 1, c);
    }

    return occ(str + 1, c); 
}