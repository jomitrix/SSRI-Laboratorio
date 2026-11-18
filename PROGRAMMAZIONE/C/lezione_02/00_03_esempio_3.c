#include <stdio.h>

int main(int argc, char *argv[]) {
    char c = 'j';
    char gioco = '0';
    int i = 1;

    while (c!=gioco) {
        printf("Prova ad indovinare la lettera (a-z) -> ");
        scanf(" %c", &gioco);
        while (gioco < 'a' || gioco > 'z') {
            printf("Prova ad indovinare la lettera (inserisci lettera valida: a-z) -> ");
            scanf(" %c", &gioco);
        }

        if (c != gioco) {
            printf("Hai sbagliato! Riprova...\n");
            i++;
        }
    }
    printf("Hai Vinto! - N° tentativi: %d\n", i);

    return 0;
}
