#include <stdio.h>
#define N 3

// Prototipi
char menu(char scelta);
void riempi(double m[N][N]);
void stampa(double m[N][N]);
void trasposta(double m[N][N], double mt[N][N]);
void somma(double m1[N][N], double m2[N][N], double ms[N][N]);
void scalare(double m[N][N], double msc[N][N], double k);
void prodotto(double m1[N][N], double m2[N][N], double mp[N][N]);
void scambio(double m1[N][N], double m2[N][N]);

int main(int argc, char const *argv[]) {
    double m1[N][N], m2[N][N], m3[N][N], r;
    char scelta;
    int inizm1 = 0, inizm2 = 0, inizr = 0, err;
    
    do {
        scelta = menu(scelta);
        switch (scelta)
        {
        case 1:
            riempi(m1);
            if(inizm1 == 0) inizm1 = 1;
            break;
        case 2:
            riempi(m2);
            if(inizm2 == 0) inizm2 = 1;
            break;
        case 3:
            printf("Inserisci la operando scalare r -> ");
            scanf("%lf", &r);
            if(inizr == 0) inizr = 1;
            break;
        case 4:
            if (inizm1) stampa(m1), printf("\n");
            else printf("NOTA: A NON è stato inserito.\n\n");
            if (inizm2) stampa(m2), printf("\n");
            else printf("NOTA: B NON è stato inserito.\n\n");
            if (inizr) printf("r = %lf\n", r);
            else printf("NOTA: r NON è stato inserito.\n");
            break;
        case 5:
            if(inizm1) trasposta(m1, m3), stampa(m3);
            else printf("ERRORE: A NON è stato inserito.\n");
            break;
        case 6:
            err = 0;
            if(!inizm1) printf("ERRORE: A NON è stato inserito.\n"), err=1;
            if(!inizr) printf("ERRORE: r NON è stato inserito.\n"), err=1;
            
            if (!err) scalare(m1, m3, r), stampa(m3);

            break;
        case 7:
            err = 0;
            if(!inizm1) printf("ERRORE: A NON è stato inserito.\n"), err=1;
            if(!inizm2) printf("ERRORE: B NON è stato inserito.\n"), err=1;
            
            if (!err) somma(m1, m2, m3), stampa(m3);

            break;
        case 8:
            err = 0;
            if(!inizm1) printf("ERRORE: A NON è stato inserito.\n"), err=1;
            if(!inizm2) printf("ERRORE: B NON è stato inserito.\n"), err=1;
            
            if (!err) prodotto(m1, m2, m3), stampa(m3);

            break;
        case 9:
            err = 0;
            if(!inizm1) printf("ERRORE: A NON è stato inserito.\n"), err=1;
            if(!inizm2) printf("ERRORE: B NON è stato inserito.\n"), err=1;
            
            if (!err) scambio(m1, m2), stampa(m1), printf("\n"), stampa(m2);
            break;
        case 10:
            printf("Programma Terminato.\n");
            break;
        }
        printf("\n");
    } while (scelta != 10);

    return 0;
}

// Definizione Funzioni

char menu(char scelta) {
    do {
        printf("Che operazione vuoi effettuare?\n");
        printf("1. Inserisci operando A.\n2. Inserisci operando B.\n3. Inserisci operando scalare r.\n4. Visualizza A, B ed r.\n5. Trasposta di A.\n6. rA.\n7. A+B.\n8. AB.\n9. Scambia A e B.\n10. Esci.\n>> ");
        scanf("%d", &scelta);
        printf("\n");

        if (scelta < 1 || scelta > 10) printf("ERRORE: Scelta NON valida.\n\n");
    } while (scelta < 0 || scelta > 10);

    return scelta;
}

void riempi(double m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &m[i][j]);
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
}

void trasposta(double m[N][N], double mt[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mt[i][j] = m[j][i];
        }
    }
}

void somma(double m1[N][N], double m2[N][N], double ms[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ms[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void scalare(double m[N][N], double msc[N][N], double r) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            msc[i][j] = m[i][j] * r;
        }
    }
}

void prodotto(double m1[N][N], double m2[N][N], double mp[N][N]) {
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            mp[i][j] = 0;
            for (int l = 0; l < N; l++) mp[i][j] += m1[i][l] * m2[l][j];
        }
    }
}

void scambio(double m1[N][N], double m2[N][N]) {
    double scambio;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scambio = m1[i][j];
            m1[i][j] = m2[i][j];
            m2[i][j] = scambio;
        }
    }
}