#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char carattere;
    
    // Continuo ad eseguire il programma fino a quando l'utente non clicca invio
    do {
        printf("Inserisci un carattere (INVIO per terminare) -> ");
        scanf("%c", &carattere);;

        // Controllo di chiusura programma
        if (carattere != '\n') {
            
            // Controlli sulla natura del carattere
            if (!isalpha(carattere)) printf("Il carattere non è alfabetico.");
            else {
                if (isupper(carattere)) printf("Il carattere è una lettera maiuscola.");
                else printf("Il carattere è una lettera minuscola.");
            }

            // Pulizia buffer
            while (getchar() != '\n'); //
        } else printf("Programma Terminato.");

        // Parte di personalizzazione
        printf("\n\n");
    } while (carattere != '\n');
    
    return 0;
}
