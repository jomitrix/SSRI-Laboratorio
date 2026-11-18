#include <stdio.h>
#include <stdlib.h>

typedef struct list_t {
    int val;
    struct list_t *next;
} list_t;

list_t *creaNodo(int val);
int inserisciInTesta(list_t **head, int val);
void printLista(list_t *head);
void delete(list_t **head, int val);
int contaOccorrenze(list_t *head, int val);
int deleteLimit(list_t **head, int val, int limit);


int main() {
    list_t *lista = NULL;

    inserisciInTesta(&lista, 1);
    inserisciInTesta(&lista, 1);
    inserisciInTesta(&lista, 1);
    inserisciInTesta(&lista, 1);

    printf("%d\n\n", contaOccorrenze(lista, 1));

    printLista(lista);
    deleteLimit(&lista, 1, 5);
    printLista(lista);

    inserisciInTesta(&lista, 7268463);
    
}

list_t *creaNodo(int val) {
    list_t *nuovoNodo = (list_t *) malloc(sizeof(list_t));
    
    if (nuovoNodo != NULL) {
        nuovoNodo->val = val;
        nuovoNodo->next = NULL;
    }

    return nuovoNodo;
}

int inserisciInTesta(list_t **head, int val) {
    list_t *nuovaTesta = creaNodo(val);
    if (nuovaTesta == NULL) return -1;

    if (*head != NULL) nuovaTesta->next = *head;
    *head = nuovaTesta;

    return 0;
}

void delete(list_t **head, int val) {
    if (*head == NULL) return;
    else {
        list_t *temp = *head;
        list_t *prev = NULL;
        int i = 0;
        do {
            if (temp->val == val) {
                if (prev == NULL) {
                    prev = temp;
                    temp = temp->next;
                    *head = temp;
                    free(prev);
                    prev = NULL;
                } else {
                    prev->next = temp->next;
                    free(temp);
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        } while (temp != NULL);
    }
}

void printLista(list_t *head) {
    list_t *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("END\n");    
}

int contaOccorrenze(list_t *head, int val) {
    list_t *temp = head;
    int count = 0;

    while (temp != NULL) {
        if (temp->val == val) count++;
        temp=temp->next;
    }
    
    return count;
}

int deleteLimit(list_t **head, int val, int limit) {
    if (contaOccorrenze(*head, val) >= limit) return -1;

    delete(head, val);
}