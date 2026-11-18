#include <stdio.h>
#include <stdlib.h>

#define out "res.txt"

int countDivisori(int n);

int main() {
    int buffer = 1, size = 0;
    int *arr = NULL;
    FILE *write;
    
    do {
        printf("num %d: ", size+1);
        scanf(" %d", &buffer);
        if (buffer > 0) {
            arr = (int *) realloc(arr, (++size) * sizeof(int));
            if (arr == NULL) {
                printf("\nERRORE: Memoria Insufficiente.\n\n");
                exit(-1);
            }
            arr[size-1] = buffer;
        }
    } while (buffer > 0);

    getchar();
    
    if ((write = fopen(out, "r")) != NULL) {
        fclose(write);
        printf("\nIl file di destinazione è occupato.\nSovrascrivere? (y/N) > ");

        if (getchar() != 'y') { printf("\nOperazione Annullata.\n"); free(arr); return 1; }
        else getchar();
    }

    if ((write = fopen(out, "w")) == NULL) {
        printf("\nERRORE: Apertura in scrittura FALLITA.\n\n");
        exit(-1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(write, "%d %d\n", arr[i], countDivisori(arr[i]));
    }

    fclose(write);
    free(arr);

    printf("\nOperazione completata con successo.\n");

    return 0;
}

int countDivisori(int n) {
    int count=0;

    for (int i = 2; i <= n/2; i++) if (n % i == 0) count++;

    return count;
}