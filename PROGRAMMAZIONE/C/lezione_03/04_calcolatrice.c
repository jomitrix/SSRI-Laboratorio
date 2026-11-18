#include <stdio.h>

int main(int argc, char const *argv[])
{
    double x, y;
    int scelta;

    do {
        printf("Che operazione vuoi effettuare?\n");
        printf("1 - Somma\n2 - Sottrazione\n3 - Moltiplicazione\n4 - Divisione\n0 - Esci dal Programma\n>> ");
        scanf("%d", &scelta);

        if (scelta == 1 || scelta == 2 || scelta == 3 || scelta == 4) {
            printf("Inserisci due valori (x, y) -> ");
            scanf("%lf, %lf", &x, &y);
        }

        switch (scelta)
        {
        case 1:
            printf("\nRisultato: %lf + %lf = %lf", x, y, x+y);
            break;
        case 2:
            printf("\nRisultato: %lf - %lf = %lf", x, y, x-y);
            break;
        case 3:
            printf("\nRisultato: %lf * %lf = %lf", x, y, x*y);
            break;
        case 4:
            if (y == 0) printf("\nERRORE: NON è possibile dividere per zero.");
            else printf("\nRisultato: %lf / %lf = %lf", x, y, x/y);
            break;
        default:
            printf("\nProgramma Terminato.");
            break;
        }
        printf("\n\n");
    } while (scelta == 1 || scelta == 2 || scelta == 3 || scelta == 4);

    return 0;
}
