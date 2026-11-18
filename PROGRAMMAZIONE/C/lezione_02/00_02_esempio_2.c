#include <stdio.h>

int main(int argc, char *argv[]) {
    char c = 'j';
    char gioco;

    printf("Prova ad indovinare il carattere -> ");
    scanf(" %c", &gioco);

    if (gioco == c) {
        printf("Hai vinto! Gioca di nuovo!\n");
        c = 'm';
    } else {
        printf("Hai perso! Riprova..\n");
    }

    printf("Prova ad indovinare il carattere -> ");
    scanf(" %c", &gioco);

    if (gioco == c) {
        printf("Hai vinto! Gioca di nuovo!\n");
        c = 'p';
    } else {
        printf("Hai perso! Riprova..\n");
    }

    printf("Prova ad indovinare il carattere -> ");
    scanf(" %c", &gioco);

    if (gioco == c) {
        printf("Hai vinto!\n");
    } else {
        printf("Hai perso!\n");
    }
    return 0;
}
