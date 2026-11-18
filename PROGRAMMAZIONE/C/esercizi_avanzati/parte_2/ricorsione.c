#include <stdio.h>

void inverti(char str[], int start, int end) {
    if (start>=end) return;

    char app;
    app = str[start];
    str[start] = str[end];
    str[end] = app;

    inverti(str, start+1, end-1);
}

int trovaMax(int arr[], int size) {
    if (size == 1) return arr[0];

    int check = trovaMax(arr, size-1);
    
    return (arr[size-1] > check) ? arr[size-1] : check;
}

#include <stdio.h>

// Funzione ricorsiva per risolvere la Torre di Hanoi
void hanoi(int n, char from, char to, char aux) {
    static long long unsigned int count = 0;
    count ++;
    if (n == 1) {
        printf("%d - Sposta il disco 1 da %c a %c\n", count, from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("%d - Sposta il disco %d da %c a %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n = 20;

    printf("Le mosse necessarie sono:\n");
    hanoi(n, 'A', 'C', 'B'); // A = origine, C = destinazione, B = ausiliario

    return 0;
}