#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diffDiagonali(int **m, int n);

int main() {
    int **m;
    int n = 3;

    m = (int **) malloc(n *sizeof(int *));
    for (int i = 0; i < n; i++) m[i] = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf(" %d", &(m[i][j]));
        }
    }

    printf("res: %d\n", diffDiagonali(m, n));

    return 0;
}

int diffDiagonali(int **m, int n) {
    if (m == NULL) return -1;

    int diagPrinc = 0, diagSecond = 0;

    for (int i = 0; i < n; i++) {
        diagPrinc += m[i][i];
        diagSecond += m[n - 1 - i][i];
    }

    printf("%d %d\n", diagPrinc, diagSecond);
    return abs(diagPrinc - diagSecond);
}