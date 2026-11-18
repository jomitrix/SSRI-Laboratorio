#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pi;
    double *pd;
    char *pc;

    int ai[]={0,1};
    double ad[]={0.1,0.2};
    char ac[]="pippo";

    pi = &ai[0];
    pd = &ad[0];
    pc = &ac[0];

    printf("PRIMA\n--------------------------------------------\n");
    printf("Puntatore int alla locazione %d e contiene %d\n", pi, *pi);
    printf("Puntatore double alla locazione %d e contiene %lf\n", pd, *pd);
    printf("Puntatore char alla locazione %d e contiene %c\n", pc, *pc);

    pi++;
    pd++;
    pc++;

    printf("\nDOPO\n--------------------------------------------\n");
    printf("Puntatore int alla locazione %d e contiene %d\n", pi, *pi);
    printf("Puntatore double alla locazione %d e contiene %lf\n", pd, *pd);
    printf("Puntatore char alla locazione %d e contiene %c\n", pc, *pc);

    return 0;
}
