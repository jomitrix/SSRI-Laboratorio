#include <stdio.h>
#include <stdlib.h>

void creaSucc(double **, int *);
void sort(double *, int);
void print(double *, int);

int main(int argc, char *argv[]) {
    int size;
    double *v;
    
    int menu;

    do {
        printf("Che operazione vuoi effettuare?\n1.\tInserisci successione.\n2.\tOrdina Elenco.\n3.\tVisualizza Elenco.\n<any>.\tTermina\n> ");
        scanf(" %d", &menu);

        printf("\n");

        switch (menu) {
            case 1:
                creaSucc(&v, &size);
                break;
            case 2:
                sort(v, size);
                break;
            case 3:
                print(v, size);
                break;
            default:
                free(v);
                printf("\nProgramma Terminato.\n");
        }
        printf("\n");
    } while (menu > 0 && menu < 4);

    return 0;
}

void creaSucc(double **v, int *size) {
    printf("Quanti valori vuoi inseire? -> ");
    scanf("%d", size);
    printf("\n");
    
    if (*v != NULL) { free(*v); }
    *v = (double *) calloc(*size, sizeof(double));
    if (*v == NULL) { printf("ERRORE: Memoria Insufficiente.\n"); exit(1); }

    for (int i = 0; i < *size; i++) {
        printf("v[%d]: ", i);
        scanf("%lf", &(*v)[i]);
    }
}

void sort(double *v, int size) {
    if (v == NULL) { printf("ERRORE: Successione NON inserita.\n"); return; }

    int sorted = 0;
    
    do {
        sorted = 1;

        for (int i = 0; i < size-1; i++) {
            if (v[i] > v[i+1]) {
                double app = v[i];
                v[i] = v[i+1];
                v[i+1] = app;
                sorted = 0;
            }
        }
    } while (!sorted);
}

void print(double *v, int size) {
    printf("[\t");
    for (int i = 0; i < size; i++) {
        printf("%3f\t", v[i]);
    }
    printf("]\n");
}