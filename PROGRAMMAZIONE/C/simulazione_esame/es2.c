#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minDiff(int **m, int rows, int cols);

int main() {
    int rows, cols;
    printf("Inserisci grandezza matrice: (<rows>, <cols>) -> ");
    scanf("%d, %d", &rows, &cols);

    int **m = (int **) calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) m[i] = (int *) calloc(cols, sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf(" %d", &m[i][j]);
        }
        
    }
    
    printf("mindiff: %d\n", minDiff(m, rows, cols));

    return 0;
}

int minDiff(int **m, int rows, int cols) {
    int checkMin, checkMax;
    int diff, diffMin;
    int index = 0;

    for (int j = 0; j < cols; j++) {
        checkMin = m[0][j];
        checkMax = m[0][j];
        for (int i = 1; i < rows; i++) {
            if (m[i][j] > checkMax) checkMax = m[i][j];
            if (m[i][j] < checkMin) checkMin = m[i][j];
        }
        diff = abs(checkMax - checkMin);
        if (j == 0) diffMin = diff;
        else if (diff < diffMin) diffMin = diff, index = j;
    }

    return index;
}