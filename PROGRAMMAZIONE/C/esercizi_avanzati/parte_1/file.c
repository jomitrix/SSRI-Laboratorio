#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Scrivi un programma in C che:
Legga una stringa inserita dall'utente (max 100 caratteri).
Cripti la stringa usando un semplice algoritmo di cifratura di Cesare con un offset scelto dall'utente.
Scriva la stringa criptata in un file chiamato "output.txt".
Legga il file "output.txt" e stampi il contenuto decifrato.*/

void criptaStringa(char *str, int offset);

int main() {
    char buffer[] = "Puzzazzo nel cacazzo wquyeqwu  iqwuye  qw9ie";
    criptaStringa(buffer, -23);

    return 0;
}

void criptaStringa(char *str, int offset) {
    char buffer[BUFSIZ];
    offset %= 26; 
    if (offset < 0) offset = 26 + offset; 

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            for (int j = 0; j < offset; j++) {
                if (str[i] != 'z' && str[i] != 'Z') str[i]++;
                else str[i] = (islower(str[i]) ? 'a' : 'A');
            }
        }
    }

    FILE *write;
    write = fopen("output.txt", "w");
    if (fprintf(write, "%s", str) == EOF) printf("ERRORE\n");
    fclose(write);

    if ((write = fopen("output.txt", "r")) == NULL) printf("ERRORE\n");
    if ((fgets(buffer, BUFSIZ, write)) == EOF) printf("ERRORE");
    printf("%s\n", buffer);
    fclose(write);
}