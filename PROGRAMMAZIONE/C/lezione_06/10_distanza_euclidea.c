#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} vett;

double calcoloDistanza(vett, vett);

int main(int argc, char const *argv[]) {
    vett punto1, punto2;

    printf("Inserisci coordinata x del punto 1 -> ");
    scanf("%lf", &punto1.x);
    printf("Inserisci coordinata y del punto 1 -> ");
    scanf("%lf", &punto1.y);
    printf("Inserisci coordinata x del punto 2 -> ");
    scanf("%lf", &punto2.x);
    printf("Inserisci coordinata y del punto 2 -> ");
    scanf("%lf", &punto2.y);

    printf("La distanza tra i due punti e' di %.2f\n", calcoloDistanza(punto1, punto2));

    return 0;
}

double calcoloDistanza(vett punto1, vett punto2) {
    return sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2)); 
}