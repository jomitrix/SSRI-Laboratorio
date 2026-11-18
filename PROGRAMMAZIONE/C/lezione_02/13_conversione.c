#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
    char carattere, scelta;

    printf("Inserisci carattere alfabetico -> "); 
    scanf(" %c", &carattere);

    if (isalpha(carattere)) {
        printf("Convertire in maiuscolo (1) o in minuscolo (altro carattere)? -> ");
        scanf(" %c", &scelta);

        if (scelta == '1') carattere = toupper(carattere);
        else carattere = tolower(carattere); 
        
        printf("\n\nCarattere: %c", carattere);

    } else printf("\n\nERRORE: Il carattere inserito NON e' alfabetico.");

    return 0;
}

