#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Vett;

Vett somma(Vett,Vett);
Vett invadd(Vett);
Vett sott(Vett,Vett);
Vett pscal(Vett);
double pint(Vett,Vett);

int main(int argc, char const *argv[]) {
    Vett v1, v2, ris;
    double scalare;

    printf("Inserisci coordinata x del punto 1 -> ");
    scanf("%lf", &v1.x);
    printf("Inserisci coordinata y del punto 1 -> ");
    scanf("%lf", &v1.y);
    printf("Inserisci coordinata x del punto 2 -> ");
    scanf("%lf", &v2.x);
    printf("Inserisci coordinata y del punto 2 -> ");
    scanf("%lf", &v2.y);

    // Somma
    ris = somma(v1, v2);
    printf("Somma: (%.2f, %.2f)\n", ris.x, ris.y);

    // Opposto (inversione)
    ris = invadd(v1);
    printf("Vettore opposto di v1: (%.2f, %.2f)\n", ris.x, ris.y);

    // Sottrazione
    ris = sott(v1, v2);
    printf("Sottrazione v1 - v2: (%.2f, %.2f)\n", ris.x, ris.y);

    // Prodotto scalare con uno scalare
    ris = pscal(v1);
    printf("Prodotto scalare di v1: (%.2f, %.2f)\n", ris.x, ris.y);

    // Prodotto scalare tra due vettori
    double prodottoInterno = pint(v1, v2);
    printf("Prodotto interno v1 ⋅ v2: %.2f\n", prodottoInterno);

    return 0;
}

Vett somma (Vett v1, Vett v2) {
    Vett v3 = {v1.x + v2.x, v1.y + v2.y};
    return v3;
}

Vett invadd (Vett v) {
    Vett v3 = {-v.x, -v.y};
    return v3;
}

Vett sott (Vett v1, Vett v2) {
    Vett v3 = {v1.x - v2.x, v1.y - v2.y};
    return v3;
}

Vett pscal (Vett v) {
    double scalare;

    printf("Inserisci uno scalare: ");
    scanf(" %lf", &scalare);
    Vett v3 = {v.x * scalare, v.y * scalare};
    
    return v3;
}

double pint (Vett v1,Vett v2) {
    return v1.x * v2.x + v1.y * v2.y;
}