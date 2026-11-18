#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *px, *py, *aus;
    int x, y;

    px = &x;
    py = &y;

    *px = 0;
    *py = 1;

    printf("PRIMA: Il puntatore px punta al valore %d\n", *px);
    printf("PRIMA: Il puntatore py punta al valore %d\n", *py);
    printf("PRIMA: x vale %d\n", x);
    printf("PRIMA: y vale %d\n", y);   
    printf("-----------------------------------\n");

    aus = px;
    px = py;
    py = aus;

    printf("DOPO : Il puntatore px punta al valore %d\n", *px);
    printf("DOPO : Il puntatore py punta al valore %d\n", *py);
    printf("DOPO : x vale %d\n", x);
    printf("DOPO : y vale %d\n", y);
    
    return 0;
}
