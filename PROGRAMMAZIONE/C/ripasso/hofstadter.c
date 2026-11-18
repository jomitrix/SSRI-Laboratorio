#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int fem(int n);
int masc(int n);
void print_timestamp();

int main(int argc, char *argv[]) {
    int n;
    printf("Inserisci n>= 0: ");
    scanf("%d", &n);
    while (n < 0) {
        printf("\nERRORE: Input NON valido.\n\n");
        printf("Inserisci n>= 0: ");
        scanf("%d", &n);
    }
    
    printf("\n------------------------------------\nn\t\tF(n)\t\tM(n)\n");
    for (int i = 0; i <= n+1; i++) {
        print_timestamp();
        printf("\t%d\t\t%d\t\t%d\n", i, fem(i), masc(i));
    }
    
    return 0;
}

int fem(int n) {
    // Caso base
    if (n == 0) {
        return 1;
    }
    
    // Caso ricorsivo
    return n - masc(fem(n-1));
}

int masc(int n) {
    if (n == 0) {
        return 0;
    }

    return n - fem(masc(n-1));
}


void print_timestamp() {
    struct timeval tv;
    struct tm *timeinfo;
    char timestamp[100];

    // Ottieni il tempo corrente (secondi e microsecondi)
    gettimeofday(&tv, NULL);

    // Converti i secondi in una struttura tm
    timeinfo = localtime(&tv.tv_sec);

    // Formatta la data/ora fino ai secondi
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Aggiungi i millisecondi
    printf("[%s.%03ld] ", timestamp, tv.tv_usec / 1000); // Millisecondi = microsecondi / 1000
}