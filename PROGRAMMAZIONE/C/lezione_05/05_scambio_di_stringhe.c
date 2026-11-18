#include <stdio.h>

int main(int argc, char const *argv[])
{
    char x[] = "Galileo Galilei", y[] = "Marco Spacca";
    char *px, *py, *aus;
    
    px = &x[0];
    py = &y[0];

    printf("PRIMA: Il puntatore px punta al valore %s\n", px);
    printf("PRIMA: Il puntatore py punta al valore %s\n", py);
    printf("PRIMA: x vale %s\n", x);
    printf("PRIMA: y vale %s\n", y);   
    printf("-----------------------------------\n");

    aus = px;
    px = py;
    py = aus;

    printf("DOPO : Il puntatore px punta al valore %s\n", px);
    printf("DOPO : Il puntatore py punta al valore %s\n", py);
    printf("DOPO : x vale %s\n", x);
    printf("DOPO : y vale %s\n", y);
    
    return 0;
}
