#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 5

void inserisciStringhe(char **strings);
void printStringhe(char **strings);
int lungString(const char *stringa);
void ordinaLung(char **strings, int lung);
void ordinaLex(char **strings, int lung);


int main (int argc, char *argv[]) {
    char **strings;

    strings = (char **) malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        strings[i] = (char *) malloc(BUFSIZ);
    }

    inserisciStringhe(strings);
    printf("\nNormali:");
    printStringhe(strings);
    ordinaLung(strings, N);
    printf("\nPer lunghezza:");
    printStringhe(strings);
    printf("\nPer lessicografico:");
    ordinaLex(strings, N);
    printStringhe(strings);

    return 0;
}

void inserisciStringhe(char **strings) {
    for (int i = 0; i < N; i++) {
        fgets(strings[i], BUFSIZ, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }
    
}

void printStringhe(char **strings) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        printf("\"%s\",\t", strings[i]);
    }
    printf("\n");
}

int lungString(const char *stringa) {
    int lenght;
    for (lenght = 0; stringa[lenght] != '\n' && stringa[lenght] != '\0'; lenght++);

    return lenght;
}

int confrontoLex(const char *str1, const char *str2) {
    int minLenght = (lungString(str1) < lungString(str2)) ? lungString(str1) : lungString(str2);
    for (int i = 0; i < minLenght; i++) {
        if (tolower(str1[i]) > tolower(str2[i])) {
            return 1;
        } else if (tolower(str1[i]) < tolower(str2[i])) {
            return 2;
        }
    }
    return 0;
}

void ordinaLung(char **strings, int lung) {
    int sorted;

    do {
        sorted = 1;
        for (int i = 0; i < lung-1; i++) {
            if (lungString(strings[i]) > lungString(strings[i+1])) {
                char *app = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = app;
                sorted = 0;
            }
        }
        
    } while (!sorted);
}

void ordinaLex(char **strings, int lung) {
    int sorted;

    do {
        sorted = 1;
        for (int i = 0; i < lung-1; i++) {
            if (confrontoLex(strings[i], strings[i+1]) == 1) {
                char *app = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = app;
                sorted = 0;
            }
        }
        
    } while (!sorted);
}