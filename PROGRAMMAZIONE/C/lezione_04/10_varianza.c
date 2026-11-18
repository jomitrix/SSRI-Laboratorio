#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int N, scambio = 1;
    double media = 0.0, varianza = 0.0, sq, app, mediana;
    
    do {
        printf("Inserisci lunghezza array -> ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("\nERRORE: Lunghezza array NON valida.\n\n");
        }
    } while (N <= 0);
    double v[N];

    printf("Inserisci array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &v[i]);
        media += v[i];
    }
    media /= N;
    printf("\nLa media aritmetica è: %lf\n", media);

    for (int i = 0; i < N; i++) {
        varianza += pow(v[i] - media, 2);
    }
    
    varianza /= N;
    sq = sqrt(varianza);
    printf("La varianza è: %lf\n", varianza);
    printf("La scarto quadratico è: %lf\n", sq);

    // Bubble Sort
    while (scambio) {
        scambio = 0;
        for (int i = 0; i < N-1; i++) {
            if (v[i] > v[i+1]) {
                app = v[i];
                v[i] = v[i+1];
                v[i+1] = app;

                scambio = 1;
            }
        }
    }
    
    if ((N % 2) != 0) {
        mediana = v[N / 2];
    } else {
        mediana = (v[(N / 2) - 1] + v[N / 2]) / 2.0;
    }

    printf("La mediana è: %lf\n", mediana);
    

    printf("Ecco l'array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%lf, ", v[i]);
    }
    printf("\n");
    
    return 0;
}
