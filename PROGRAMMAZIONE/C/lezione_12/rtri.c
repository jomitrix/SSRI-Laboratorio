#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tri {
    double x1, y1;
    double x2, y2;
    double x3, y3;
} Tri;

int countDegeneri(Tri *ts, int sz);
double mediaAree(Tri *ts, int sz);
int minArea(Tri *ts, int sz);


int main(int argc, char *argv[]) {
    int i = 0, n;
    Tri *triangles;

    printf("Nome file -> ");
    char nome[BUFSIZ];
    fgets(nome, BUFSIZ, stdin);
    while (nome[i] != '\0' && nome[i] != '\n') i++;
    nome[i] = '\0';

    FILE *read;
    read = fopen(nome, "r");
    if (read == NULL) { printf("ERRORE nell'apertura file. Riprova.\n"); exit(1); }

    if (fscanf(read, "%d", &n) != 1 || n < 1) { printf("ERRORE numero triangoli non validi\n"); exit(1); } 
    triangles = (Tri *) calloc(n, sizeof(Tri));
    if (triangles == NULL) { printf("ERRORE allocazione memoria"); fclose(read); exit(1); }

    for (int i = 0; i < n; i++) {
        if(fscanf(read, "%lf %lf %lf %lf %lf %lf",    &triangles[i].x1, &triangles[i].y1,
                                                &triangles[i].x2, &triangles[i].y2,
                                                &triangles[i].x3, &triangles[i].y3) != 6)
        { printf("ERRORE nella prelevazione dei dati triangolo."); fclose(read); free(triangles); exit(1); }
    }
    
    fclose(read);

    // n
    int cdegen = countDegeneri(triangles, n);
    double avgArea = mediaAree(triangles, n);
    int minAr = minArea(triangles, n);

    printf("\n\n1) Numero triangoli: %d,\n2) Numero Triangoli degeneri: %d\n3) Media aree: %2f\n4) Indice miAr: %d", n, cdegen, avgArea, minAr);
    
    free(triangles);

    return 0;
}

double calcoloArea( Tri t ) {
    return 0.5 * fabs(t.x1 * (t.y2 - t.y3) + t.x2 * (t.y3 - t.y1) + t.x3 * (t.y1 - t.y2));
}

int countDegeneri(Tri *ts, int sz) {
    int count = 0;

    for (int i = 0; i < sz; i++) {
        if (calcoloArea(ts[i]) == 0.0) {
            count++;
        }
    }
    return count;
}

double mediaAree(Tri *ts, int sz) {
    double avg = 0;
    for (int i = 0; i < sz; i++) {
        avg += calcoloArea(ts[i]);
    };
    return avg /= sz;
}

int minArea(Tri *ts, int sz) {
    int min = sz-1;
    for (int i = sz-2; i >= 0; i--) {
        double app;
        if (app = calcoloArea(ts[i]) < min) min = i;
    }

    return min;
}