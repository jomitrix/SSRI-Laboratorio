#include <stdio.h>
#include <math.h>
#define N 2

void riempi(double m[N][N]);
int verifica(double A[N][N], double B[N][N]);
void scalare(double m[N][N], double ms[N][N]);
void trasposta(double m[N][N], double mt[N][N]);
void identita1(double A[N][N], double B[N][N], double C[N][N]);
void identita2(double A[N][N], double B[N][N], double C[N][N]);
void identita3(double A[N][N], double B[N][N], double C[N][N]);
void stampa(double m[N][N]);

int main(int argc, char const *argv[])
{
    double A[N][N], B[N][N], C[N][N];
    printf("Inserisci matrice 1\n"), riempi(A);
    printf("Inserisci matrice 2\n"), riempi(B);
    printf("Inserisci matrice 3\n"), riempi(C);

    printf("\n\nVerifica Identità 1\n");
    identita1(A, B, C);

    printf("\n\nVerifica Identità 2\n");
    identita2(A, B, C);

    printf("\n\nVerifica Identità 3\n");
    identita3(A, B, C);

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

int verifica(double A[N][N], double B[N][N]) {
    int i = 0, j, check = 1;
    const double epsilon = 0.0001;

    do {
        j = 0;
        do {
            if (fabs(A[i][j] - B[i][j]) > epsilon) check = 0;
            j++;
        } while (j < N && check);
        i++;
    } while (i < N && check);

    return check;
}

void scalare(double m[N][N], double msc[N][N]) {
    double r = 5.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            msc[i][j] = m[i][j] * r;
        }
    }
}

void trasposta(double m[N][N], double mt[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mt[i][j] = m[j][i];
        }
    }
}

void stampa(double m[N][N]) {
    for (int i = 0; i < N; i++) {
        printf("[");
        for (int j = 0; j < N; j++) {
            printf("%lf", m[i][j]);
            if (j < N - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("\n");
}

void identita1(double A[N][N], double B[N][N], double C[N][N]) {
    double v1[N][N], v2[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            v1[i][j] = B[i][j] + C[i][j];
            v1[i][j] *= A[i][j];
            
            v2[i][j] = A[i][j] * B[i][j];
            v2[i][j] += A[i][j] * C[i][j];
        }
    }
    stampa(v1), stampa(v2);
    if(verifica(v1, v2)) printf("L'identità1 è VERIFICATA\n");
    else printf("L'identità1 NON è VERIFICATA\n");
}

void identita2(double A[N][N], double B[N][N], double C[N][N]) {
    double v1[N][N], v2[N][N];
    
    scalare(A, v2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            v1[i][j] = A[i][j] * B[i][j];
            
            v2[i][j] *= B[i][j];
        }
    }
    scalare(v1, v1);

    stampa(v1), stampa(v2);
    if(verifica(v1, v2)) printf("L'identità2 è VERIFICATA\n");
    else printf("L'identità2 NON è VERIFICATA\n");
}

void identita3(double A[N][N], double B[N][N], double C[N][N]) {
    double v1[N][N], v2[N][N];
    
    trasposta(A, v1);
    trasposta(B, v2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            v2[i][j] *= v1[i][j];
            
            v1[i][j] = A[i][j]*B[i][j];
        }
        trasposta(v1,v1);
    }
    stampa(v1), stampa(v2);
    if(verifica(v1, v2)) printf("L'identità3 è VERIFICATA\n");
    else printf("L'identità3 NON è VERIFICATA\n");
}

