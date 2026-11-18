#include <stdio.h>

int main(int argc, char const *argv[])
{
    short int stato = 2;
    double x, y;
    char scelta;

    char menu(char scelta);
    double somma(double x, double y);
    double sottrazione(double x, double y);
    double prodotto(double x, double y);
    double divisione(double x, double y);


    do {
        if (stato == 2) scelta = 0, stato = 1;
        else scelta = menu(scelta);
        
        switch (scelta)
        {
            case 0:
                printf("Inserisci due valori (x, y) -> ");
                scanf("%lf, %lf", &x, &y);
                break;
            case 1:
                printf("Risultato: %lf", somma(x,y));
                break;
            case 2:
                printf("Risultato: %lf", sottrazione(x,y));
                break;
            case 3:
                printf("Risultato: %lf", prodotto(x,y));
                break;
            case 4:
                if (y == 0) printf("\nERRORE: NON è possibile dividere per zero.");
                else printf("Risultato: %lf", divisione(x,y));
                break;
            case 5:
                printf("Programma Terminato.");
                stato = 0;
                break;
        }
        printf("\n\n");
    } while (stato != 0);

    return 0;
}

char menu(char scelta) {
    do {
        printf("Che operazione vuoi effettuare?\n");
        printf("0 - Inserisci Operandi\n1 - Somma\n2 - Sottrazione\n3 - Moltiplicazione\n4 - Divisione\n5 - Esci dal Programma\n>> ");
        scanf("%d", &scelta);
        printf("\n");

        if (scelta < 0 || scelta > 5) printf("ERRORE: Scelta NON valida.\n\n");

    } while (scelta < 0 || scelta > 5);

    return scelta;
}
double somma(double x, double y) {
    return x+y;
}
double sottrazione(double x, double y) {
    return x-y;
}
double prodotto(double x, double y) {
    return x*y;
}
double divisione(double x, double y) {
    return x/y;
}