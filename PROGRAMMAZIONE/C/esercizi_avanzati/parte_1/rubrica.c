#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 25
#define MAX_NUM 10

typedef struct Entry {
    char nome[MAX_NAME];
    char cognome[MAX_NAME];
    char numero[MAX_NUM];
} Entry;

typedef struct Rubrica {
    Entry *lista;
    int size;
} Rubrica;

Rubrica inizializzaRubrica();
void aggiungiContatto(Rubrica *r);
void visualizzaRubrica(Rubrica r);
void cercaContatto(Rubrica r);
void eliminaContatto(Rubrica *r);
void liberaMemoria(Rubrica *r);

int main() {
    Rubrica rubrica = inizializzaRubrica();
    
    int scelta;
    do {
        printf("\n--- Rubrica Telefonica ---\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Cerca contatto\n");
        printf("4. Elimina contatto\n");
        printf("5. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();  // Consuma il newline

        switch (scelta) {
            case 1:
                aggiungiContatto(&rubrica);
                break;
            case 2:
                visualizzaRubrica(rubrica);
                break;
            case 3:
                cercaContatto(rubrica);
                break;
            case 4:
                eliminaContatto(&rubrica);
                break;
            case 5:
                liberaMemoria(&rubrica);
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 5);

    return 0;
}

Rubrica inizializzaRubrica() {
    Rubrica newRubrica;
    newRubrica.size = 0;
    return newRubrica;
}

void aggiungiContatto(Rubrica *r) {
    int index = r->size;
    char buffer[BUFSIZ];
    r->lista = realloc(r->lista, (++r->size) * sizeof(Entry));
    if (r->lista == NULL) { printf("\nERRORE: Allocazione memoria NON riuscita.\n\n"); exit(-1); }

    printf("Nome Contatto: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(r->lista[index].nome, buffer, MAX_NAME);
    r->lista[index].nome[MAX_NAME - 1] = '\0';

    printf("Cognome Contatto: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(r->lista[index].cognome, buffer, MAX_NAME);
    r->lista[index].cognome[MAX_NAME - 1] = '\0';

    printf("Numero Contatto: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(r->lista[index].numero, buffer, MAX_NUM);
    r->lista[index].numero[MAX_NUM - 1] = '\0';

    printf("Contatto aggiunto con successo.\n");
}

void visualizzaRubrica(Rubrica r) {
    printf("\nRubrica\n----------\n");
    for (int i = 0; i < r.size; i++) {
        printf("%s %s: %s\n", r.lista[i].nome, r.lista[i].cognome, r.lista[i].numero);
    }
}

void cercaContatto(Rubrica r) {
    char query[BUFSIZ];
    int found = 0;

    printf("Inserisci il nome, il cognome o il numero da trovare -> ");
    fgets(query, BUFSIZ, stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < r.size; i++) {
        if (strcmp(query, r.lista[i].nome) == 0 || strcmp(query, r.lista[i].cognome) == 0 || strcmp(query, r.lista[i].numero) == 0) {
            printf("Trovato: %s %s: %s\n", r.lista[i].nome, r.lista[i].cognome, r.lista[i].numero);
            found = 1;
        }
    }

    if (found == 0) printf("Non è stato trovato un contatto.\n");
}

void eliminaContatto(Rubrica *r) {
    char query[BUFSIZ];
    int indexToRemove = -1;
    printf("Inserisci il numero del contatto da eliminare -> ");
    fgets(query, MAX_NUM+1, stdin);
    query[strcspn(query, "\n")] = '\0';
    
    for (int i = 0; i < r->size && indexToRemove == -1; i++) {
        if (strcmp(query, r->lista[i].numero) == 0) {
            indexToRemove = i;
            r->size--;
        }
    }

    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < r->size; i++) {
            r->lista[i] = r->lista[i+1];
        }

        r->lista = realloc(r->lista, r->size * sizeof(Entry));
        printf("Operazione completata con successo.\n");
    } else {
        printf("Non c'è un contatto con quel numero.\n");
    }
}

void liberaMemoria(Rubrica *r) {
    free(r->lista);
    r->lista = NULL;
    r->size = 0;
}