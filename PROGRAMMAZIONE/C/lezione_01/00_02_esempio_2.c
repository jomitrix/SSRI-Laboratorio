#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    int maxint = INT_MAX;
    int err = maxint + 1;
    printf("%d\n", maxint);

    printf("%d\n", err);
}