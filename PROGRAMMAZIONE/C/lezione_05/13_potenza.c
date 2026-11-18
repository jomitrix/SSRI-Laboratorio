#include <stdio.h>
#include <math.h>
#define N 3

void riempi(double [N][N]);
void prodotto(double [N][N], double [N][N], double [N][N]);
void potenza(double [N][N], int);
void stampa(double [N][N]);

int main(int argc, char const *argv[])
{
    double A[N][N];
    int esp;

    printf("Inserisci matrice\n"), riempi(A);
    do {
        printf("Inserire esponente della matrice (>= 0) -> ");
        scanf("%d", &esp);
        if (esp < 0) printf("\nERRORE: Valore dell'esponente NON valido.\n\n");
    } while (esp < 0);

    printf("\nMatrice Prodotto:\n");
    potenza(A, esp);

    stampa(A);

    return 0;
}

void riempi(double m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &m[i][j]);
        }
    }
}

void copia(double m2[N][N], double m1[N][N]) {
    for (int j = 0; j < N; j++)
        for (int l = 0; l < N; l++)
            m2[j][l] = m1[j][l];
}

void prodotto(double m1[N][N], double m2[N][N], double mp[N][N]) {
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            mp[i][j] = 0;
            for (int l = 0; l < N; l++) mp[i][j] += m1[i][l] * m2[l][j];
        }
    }
}

void potenza(double m[N][N], int esp) {
    double iniz[N][N], app[N][N];

    if (esp == 0) {
        //Matrice Identità
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                (i == j) ? m[i][j] = 1 : m[i][j] = 0;
            
    } else if (esp > 0) {
        //Matrice Prodotto

        // Riempio la matrice d'appoggio 
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) iniz[i][j] = m[i][j];

        // Fino a quando l'iterazioni di moltiplicazioni non sono uguali all'esponente
        for (int i = 1; i < esp; i++) {
            prodotto(m, iniz, app); // Prodotto tra matrice del prodotto precedente e matrice iniziale (iniz*iniz)*iniz ...
            copia(m, app);          // Faccio diventare m = (m * m-1)
        }
        
    }
}

void stampa(double m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", m[i][j]); // Stampa con due decimali
        }
        printf("\n");
    }
    printf("\n");
}
