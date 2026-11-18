#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkISBN(char *isbn);

int main() {

    printf("0078818095: %d\n", checkISBN("0078818095"));
    printf("1234567890: %d\n", checkISBN("1234567890"));

    return 0;
}

int checkISBN(char *isbn) {
    if (strlen(isbn) != 10) return 0;

    int sumcifre = 0, sumsomma = 0;

    for (int i = 0; i < 10; i++) {
        if (isdigit(isbn[i])) {
            sumcifre += (isbn[i] - '0');
            
        } else if (isbn[i] == 'X') {
            sumcifre += 10;
        }
        sumsomma += sumcifre;
    }

    return (sumsomma % 11) == 0;
}