#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPseudoPalindromo(char *in);

int main() {
    printf("%d\n", isPseudoPalindromo("A man, a plan, a canal, Panama!"));
    return 0;
}

int isPseudoPalindromo(char *in) {
    if (in == NULL) return -1;

    char *res = (char *) malloc(sizeof(char));
    int size = 0;
    char adder[2] = "-";

    for (int i = 0; i < strlen(in); i++) {
        if (isalnum(in[i]) != 0) {
            res = (char *) realloc(res, (++size+1) * sizeof(char));
            adder[0] = tolower(in[i]);
            strcat(res, adder);
        }
    }

    int check = 1;
    for (int i = 0; i < strlen(res)/2 && check == 1; i++) {
        if (res[i] != res[strlen(res)-1-i]) check = 0;
    }

    return check;
}