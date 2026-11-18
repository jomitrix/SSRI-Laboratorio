#include <stdio.h>
#include <stdlib.h>

void riempi(double **, int *);
void aggiungi(double **, int *);
void ordina(double *, int);
void stampa(double *, int);


int main(int argc, char const *argv[]) {
    int lenght;
    double *arr;
    char scelta;

    arr = NULL;

    do {
        printf("Ordinamento Array\n-----------------\n1. Inserisci elenco di double.\n2. Ordina elenco.\n3. Visualizza elenco.\n4. Aggiungi elementi.\n5. Termina.\n> ");
        scanf(" %c", &scelta);

        printf("\n");
        switch (scelta) {
        case '1':
            if (arr) free(arr);
            riempi(&arr, &lenght);
            break;
        case '2':
            if (arr) ordina(arr, lenght);
            else printf("ERRORE: L'array NON è stato ancora riempito.\n");
            break;
        case '3':
            if (arr) stampa(arr, lenght);
            else printf("ERRORE: L'array NON è stato ancora riempito.\n");
            break;
        case '4':
            if (arr) aggiungi(&arr, &lenght);
            else printf("ERRORE: L'array NON è stato ancora riempito.\nPer riaggiungere serve aver già riempito prima l'array.\n");
            break;
        case '5':
            free(arr);
            printf("Programma Terminato.");
            break;
        default:
            printf("ERRORE: Scelta NON valida.\n");
            break;
        }
        printf("\n");
    } while (scelta != '5');
    return 0;
}

void riempi(double **v, int *lenght) {
    printf("Quanti valori si intende inserire? -> ");
    scanf("%d", lenght);

    *v = (double *) malloc(*lenght * sizeof(double));
    if (!*v) printf("\nErrore: Memoria insufficiente\n");

    for (int i = 0; i < *lenght; i++) {
        printf("Valore %d -> ", i+1);
        scanf("%lf", &(*v)[i]);
    }
}

void aggiungi(double **v, int *lenght) {
    int add;
    printf("Quanti valori vuoi aggiungere? -> ");
    scanf(" %d", &add);
    
    *v = (double *) realloc(*v, (*lenght+add) * sizeof(double)); 
    if (!*v) printf("\nErrore: Memoria insufficiente\n"); 

    for (int i = *lenght; i < *lenght+add; i++) {
        printf("Valore %d -> ", i+1);
        scanf("%lf", &(*v)[i]);
    }

    *lenght += add;
}

void ordina(double *v, int lenght) {
    // Bubble Sort
    int scambio = 1;
    double app;

    while (scambio) {
        scambio = 0;
        for (int i = 0; i < lenght-1; i++) {
            if (v[i] > v[i+1]) {
                app = v[i];
                v[i] = v[i+1];
                v[i+1] = app;
                
                scambio = 1;
            }
        }
    }
}

void stampa(double *v, int lenght) {
    printf("[  ");
    for (int i = 0; i < lenght; i++) {
        printf("%.2f  ", v[i]);
    }
    printf("]\n");
}