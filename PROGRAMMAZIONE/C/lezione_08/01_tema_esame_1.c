#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void stampaLista(Node *head);
void stampaDebug(Node *head);
int inserisciInTesta(Node **head);
int inserisciInCoda(Node **head);
void rimuoviTesta(Node **head);
void rimuoviCoda(Node **head);
void cancella(Node **head);

int main(int argc, char const *argv[]) {
    Node* head = NULL;
    
    inserisciInTesta(&head);
    inserisciInTesta(&head);

    stampaDebug(head);

    inserisciInCoda(&head);
    inserisciInCoda(&head);

    stampaDebug(head);

    rimuoviTesta(&head);

    stampaDebug(head);

    rimuoviCoda(&head);

    stampaDebug(head);

    cancella(&head);

    stampaDebug(head);

    return 0;
}

void stampaLista(Node *head) {
    Node *current = head;

    if (current == NULL) printf("La lista e' vuota!");
    else {
        printf("[ ");
        while (current != NULL) {
            printf("%d, ", current->value);
            current = current->next;
        }
        printf("]");
    }
}

void stampaDebug(Node *head) {
    Node *current = head;

    printf("\n\n");
    if (current == NULL) printf("La lista e' vuota!");
    else {
        while (current != NULL) {
            printf("valore->%d, prossimo->%p\n", current->value, current->next);
            current = current->next;
        }
    }

    printf("\n");
}

int inserisciInTesta(Node **head) {
    Node *elemLista = (Node *) malloc(sizeof(Node));
    if(elemLista == NULL) { printf("ERRORE: Allocazione Fallita."); return -1; }

    printf("Elemento da inserire -> ");
    scanf("%d", &elemLista->value);
    elemLista->next = NULL;

    if (*head == NULL) {
        *head = elemLista;
    } else {
        elemLista->next = *head;
        *head = elemLista;
    }

    return 0;
}

int inserisciInCoda(Node **head) {
    Node *elemLista = (Node*) malloc(sizeof(Node));
    if(elemLista == NULL) { printf("ERRORE: Allocazione Fallita."); return -1; }

    printf("Elemento da inserire -> ");
    scanf("%d", &elemLista->value);
    elemLista->next = NULL;

    if (*head == NULL) {
        *head = elemLista;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next=elemLista;
    }

    return 0;
}

void rimuoviTesta(Node **head) {
    if (*head == NULL) {
        printf("La lista è già vuota!");
    } else {
        Node *current = *head; 
        *head = (*head)->next;
        free(current);
    }
}

void rimuoviCoda(Node **head) {
    if (*head == NULL) {
        printf("La lista è già vuota!\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }
}

void cancella(Node **head) {
    Node *track;
    while (*head != NULL) {
        track = *head;
        *head = (*head)->next;
        free(track);
    }
}