#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SCALARE 5

typedef struct Vett {
    double x;
    double y;
} Vett;

double dist(Vett, Vett);
Vett somma(Vett,Vett);
Vett invadd(Vett);
Vett sott(Vett,Vett);
Vett pscal(Vett);
double pint(Vett,Vett);
int linind(Vett *, Vett *);

int main(int argc, char *argv[]) {
    Vett v1 = { atof(argv[1]), atof(argv[2])};
    Vett v2 = { atof(argv[3]), atof(argv[4])};
    char menu;

    do {
        printf("Menu\n------\n1. Distanza\n2. Somma\n3. Inverso Additivo\n4. Sottrazione\n5. Prodotto Scalare\n6. Prodotto Interno\n7. Linearmente (in)dipendenti\n . per uscire\n> ");
        scanf(" %c", &menu);
        
        printf("\n");

        switch (menu)
        {
        case '1':
            printf("Distanza tra punti: %lf", dist(v1, v2));
            break;
        case '2':
            printf("Somma: %lf", somma(v1, v2));
            break;
        case '3':
            printf("Inverso Additivo: %lf", invadd(v1));
            break;
        case '4':
            printf("Sottrazione: %lf", sott(v1, v2));
            break;
        case '5':
            printf("Prodotto Scalare: %lf", pscal(v1));
            break;
        case '6':
            printf("Prodotto Interno: %lf", pint(v1, v2));
            break;
        case '7':
            printf(linind(&v1, &v1) ? "Linearmente Indipendenti" : "Linearmente Dipendenti");
            break;
        }
        printf("\n\n");
    } while (menu >= '1' && menu <= '7');
    
    return 0;
}

double dist(Vett v1, Vett v2) {
    return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}

Vett somma(Vett v1,Vett v2) {
    Vett result;

    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

Vett invadd(Vett v) {
    Vett result = { -v.x, -v.y};
    return result;
}

Vett sott(Vett v1,Vett v2) {
    Vett result;

    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    
    return result;
}

Vett pscal(Vett v) {
    Vett result = { SCALARE * v.x, SCALARE * v.y};
    
    return result;
}

double pint(Vett v1,Vett v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int linind(Vett *v1, Vett *v2) {
    return ((v1->x * v2->y - v2->x * v1->y) != 0);
}