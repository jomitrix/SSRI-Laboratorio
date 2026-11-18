#include <stdio.h>
#include <stdlib.h>
#define N 100

int *merge(int *, int *, int, int);
void stampa(int *, int);

int main(int argc, char const *argv[]) {
    int v1[N], v2[N];
    int l1, l2;
    int *merged;

    // Input per la prima sequenza
    printf("Quanti valori vuoi inserire per la prima successione? -> ");
    scanf(" %d", &l1);
    if (l1 > N) printf("Errore: troppi elementi per la prima successione.\n"), exit(1);

    for (int i = 0; i < l1; i++) {
        printf("v1[%d] > ", i);
        scanf(" %d", &v1[i]);
    }

    // Input per la seconda sequenza
    printf("Quanti valori vuoi inserire per la seconda successione? -> ");
    scanf(" %d", &l2);
    if (l2 > N) printf("Errore: troppi elementi per la seconda successione.\n"), exit(1);

    for (int i = 0; i < l2; i++) {
        printf("v2[%d] > ", i);
        scanf(" %d", &v2[i]);
    }

    merged = merge(v1, v2, l1, l2);
    stampa(merged, l1 + l2);

    free(merged);

    return 0;
}

int *merge(int *v1, int *v2, int l1, int l2) {
    int *merged;
    merged = (int *)malloc((l1 + l2) * sizeof(int));
    if (merged == NULL) printf("Errore di allocazione memoria.\n"), exit(1);

    for (int i = 0; i < l1; i++) merged[i] = v1[i];
    for (int i = 0; i < l2; i++) merged[i + l1] = v2[i];

    return merged;
}

void stampa(int *v, int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}
