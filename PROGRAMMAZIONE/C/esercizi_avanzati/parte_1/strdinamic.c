#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

int *array() {
    return (int *) calloc(N, sizeof(int));
}

int **matrix() {
    int **matrix = (int **) calloc(N, sizeof(int));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *) calloc(N, sizeof(int));
    }
    return matrix;
}

char **strarrf() {
    char **strs, buffer[BUFSIZ];

    strs = (char **) calloc(N, sizeof(char));
    for (int i = 0; i < N; i++) {
        fgets(buffer, BUFSIZ, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strs[i] = (char *) calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(strs[i], buffer);
    }
    
    return strs;
}

int main() {
    int *v = array();
    int **m = matrix();
    char **strarr = strarrf();

    return 0;
}