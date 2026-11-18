#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s1[BUFSIZ], s2[BUFSIZ];
    int i = 0, j = 0, check = 0;

    printf("Inserisci stringa 1 -> ");
    fgets(s1, BUFSIZ, stdin);
    printf("Inserisci stringa 2 -> ");
    fgets(s2, BUFSIZ, stdin);

    do {
        // Controllo l'inizio della seconda stringa
        if (s1[i] != s2[j]) {
            // Nel caso siano diverse ricomincio dalla prima iterazione della seconda stringa e resetto il check
            check = 0;
            j = 0;
        } else {
            // Mi sposto a destra nella seconda stringa
            j++;
            // Controllo se ho finito la stringa
            if (j < strlen(s2)-1) {
                // Se non l'ho finita ricontrollo come prima
                check = 1;
            } else {
                // Se l'ho finita esco
                check = 2;
            }
        }
        // Mi sposto a destra della prima stringa
        i++;
    } while (check != 2 && i < strlen(s1));
    
    printf("\n");
    if (check == 2) printf("La seconda stringa è una sottostringa della prima.\n");
    else printf("La seconda strina NON è una sottostringa.\n");

    return 0;
}
