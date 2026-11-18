#include <stdio.h>
#include <string.h>

int main() {
    char test[BUFSIZ];
    fgets(test, BUFSIZ, stdin);

    test[strcspn(test, "\n")] = '\0';
    printf("%s\n", test);
    if (strcmp(test, "es") == 0) {
        printf("si!");
    }
}