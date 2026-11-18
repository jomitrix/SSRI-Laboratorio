#include <stdio.h>
int checkISBN(char isbn[11]);

int main(int argc, char argv[]) {
    char test[11] = "359821507X\0";

    if (checkISBN(test) == 1) {
        printf("ISBN valido.\n");
    } else {
        printf("ISBN non valido.\n");
    }

    return 0;
}

int checkISBN(char isbn[11]) {
    int min = (int) '0';
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        if (isbn[i] >= '0' && isbn[i] <= '9') {
            sum += ( (i+1) * (isbn[i] - min));
        } else if (i == 9 && isbn[i] == 'X') {
            sum += 100;
        } else {
            return 0;
        }
        //printf("char %d, isbn min %d, sumtest: %d\n", isbn[i], isbn[i]-min, sum);
    }

    if (sum % 11 == 0) return 1;
    else return 0;
}