#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

Nodo* creaNodo(int in);
void inserisciInTesta(Nodo **testa, int in);
void inserisciInCoda(Nodo **testa, int in);
void stampaLista(Nodo *testa);



int main(int argc, char *argv[]) {
    int count = 0;
    Nodo* testa;
    testa = NULL;

    stampaLista(testa);
    inserisciInCoda(&testa, count++);
    stampaLista(testa);
    inserisciInTesta(&testa, count++);
    stampaLista(testa);
    inserisciInCoda(&testa, count++);
    stampaLista(testa);
    inserisciInTesta(&testa, count++);
    stampaLista(testa);
    inserisciInCoda(&testa, count++);
    stampaLista(testa);

    return 0;
}

Nodo* creaNodo(int in) {
    Nodo* nuovoNodo;
    nuovoNodo = (Nodo *) malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) { printf("\nERRORE: Allocazione in memoria NON riuscita"); exit(1); }

    nuovoNodo->dato = in;
    nuovoNodo->next = NULL;

    return nuovoNodo;
}

void inserisciInTesta(Nodo **testa, int in) {
    Nodo* nuovoNodo = creaNodo(in);

    if (*testa == NULL) {
        *testa = nuovoNodo;
    } else {
        nuovoNodo->next = *testa;
        *testa = nuovoNodo;
    }
}

void inserisciInCoda(Nodo **testa, int in) {
    Nodo* nuovoNodo = creaNodo(in);

    if (*testa == NULL) {
        *testa = nuovoNodo;
    } else {
        Nodo *temp = *testa;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuovoNodo;
    }
}

void stampaLista(Nodo *testa) {
    Nodo* temp = testa;

    printf("Lista:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->next;
    }
    printf("FINE\n");
}