#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cifra(char *in, int k);
void decifra(char *in, int k);

int main() {
    char str[10] = "test";
    cifra(str, 3);
    printf("%s\n", str);
    decifra(str, 3);
    printf("%s\n", str);
    return 0;
}

void cifra(char *str, int k) {
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) { // Controlla se è una lettera
            char base = isupper(str[i]) ? 'A' : 'a';
            str[i] = (str[i] - base + k) % 26 + base;
        }
    }
}

void decifra(char *in, int k) {
    cifra(in, -k);
}