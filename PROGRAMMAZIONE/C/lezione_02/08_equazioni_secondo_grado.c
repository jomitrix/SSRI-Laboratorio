#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double a, b, c, delta, sol1, sol2;
    printf ("Inserisci i coefficienti dell'equazione ax^2 + bx + c = 0\n");
    do
    {
        printf("a = ");
        scanf("%lf", &a);

        if (a==0) {
            printf("\nERRORE: Il valore di 'a' non può essere zero.\n\n");
        }
    } while (a == 0);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    delta = pow(b, 2) - 4*a*c;

    printf("\nDelta = %lf\n", delta);

    if (delta < 0) printf("Non ci sono soluzioni per x");
    else if (delta == 0) {
        sol1 = -b/(2*a);
        printf("x = %lf", sol1);
    } else {
        sol1 = (-(b) + sqrt(delta)) / (2 * a);
        sol2 = (-(b) - sqrt(delta)) / (2 * a);
        printf("x1 = %lf\tx2 = %lf", sol1, sol2);
    }
    printf("\n");

    return 0;
}
