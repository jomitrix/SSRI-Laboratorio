#include <stdio.h>
#include <stdlib.h>

int **creaMatrice(int **m, int r, int c);

int main() {
    int **matr;

    matr = creaMatrice(matr, 10, 10);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", matr[i][j]);
        }
        printf("\n");
        
    }
    
}

int **creaMatrice(int **m, int r, int c) {
    m = (int **) calloc(r, sizeof(int *));
    for (int i = 0; i < r; i++)
        m[i] = (int *) calloc(c, sizeof(int));

    return m;
    
}