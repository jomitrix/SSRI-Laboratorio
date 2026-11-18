#include <stdio.h>
#include <stdlib.h>

void riempi(int *, int);
void stampa(int *, int);
void bubblesort(int *, int, int (*)(int, int));
int confrontoCresc(int, int);
int confrontoDecresc(int, int);

int main() {
    int *v, size;
    char choice;

    printf("\033[1;4;31mOrdinamento di un array\033[0m\n\n");

    printf("\033[32mInserire grandezza array \033[33m(dim > 0)\033[32m -> \033[0m");
    scanf("%d", &size);
    while (getchar() != '\n'); // Pulisce il buffer dell'input

    if (size < 1) {
        printf("\033[1;4;35m\nERRORE: Dimensione array NON valida.\n\033[0m");
        exit(1);
    }

    v = (int *) calloc(size, sizeof(int));
    if (v == NULL) {
        printf("\033[1;4;35m\nERRORE: Allocazione di memoria non riuscita.\n\033[0m");
        exit(1);
    }

    riempi(v, size);

    printf("\033[36mIl tuo array:\033[0m\n");
    stampa(v, size);
    
    printf("\n\033[36mCome vuoi ordinare l'array? \033[33m(\033[1;33m[0] crescente\033[0;33m, [1] decrescente\033[32m) -> \033[0m");
    scanf("%c", &choice);
    while (getchar() != '\n'); // Pulisce il buffer dell'input

    if (choice == '1') {
        bubblesort(v, size, confrontoDecresc);
    } else {
        bubblesort(v, size, confrontoCresc);
    }

    printf("\n\033[36mArray ordinato:\033[0m\n");
    stampa(v, size);

    free(v);
    return 0;
}

// Funzioni
void riempi(int *arr, int size) {
    printf("\n\033[36mRiempi Array:\n");
    for (int i = 0; i < size; i++) {
        printf("\033[32melem \033[0m%d\033[32m = \033[0m", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void stampa(int *arr, int size) {
    printf("\033[31m[ ");
    for (int i = 0; i < size - 1; i++) {
        printf("\033[1;34m%d\t", arr[i]);
    }
    printf("\033[1;34m%d ", arr[size - 1]);
    printf("\033[31m]\033[0m\n");
}

void bubblesort(int *arr, int size, int (*confronto)(int, int)) {
    int sorted;

    do {
        sorted = 1;
        for (int i = 0; i < size - 1; i++) {
            if (confronto(arr[i], arr[i + 1])) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    } while (!sorted);
}

int confrontoCresc(int a, int b) {
    return a > b;
}

int confrontoDecresc(int a, int b) {
    return a < b;
}
