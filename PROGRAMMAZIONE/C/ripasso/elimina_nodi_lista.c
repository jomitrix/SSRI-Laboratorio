#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura della lista
typedef struct node {
    int value;
    struct node *next;
} list_t;

// Funzione per eliminare tutti i nodi con un dato valore dalla lista
void delete(list_t **head, int val) {
    list_t *current = *head, *prev = NULL;

    while (current != NULL) {
        if (current->value == val) {
            if (prev == NULL) { // se il primo elemento lo devo levare dall'head in quanto primo puntatore
                *head = current->next;
            } else { //senno aggiorno il precedente all'elemento successivo a quello da eliminare (quello che diventa corrente)
                prev->next = current->next;
            }

            // elimino l'elemento corrente (val)
            list_t *temp = current;
            current = current->next;
            free(temp);
        } else {
            //aggiorno il precedente
            prev = current;
            //aggiorno l'attuale
            current = current->next;
        }
    }
}

// Funzione per contare le occorrenze di un valore nella lista
int count_occurrences(list_t *head, int val) {
    int count = 0;
    while (head != NULL) {
        if (head->value == val) {
            count++;
        }
        head = head->next;
    }
    return count;
}

// Funzione per eliminare i nodi con valore val se le occorrenze sono inferiori a limit
void conditional_delete(list_t **head, int val, int limit) {
    int occurrences = count_occurrences(*head, val);
    if (occurrences < limit) {
        delete(head, val);
    }
}

// Funzione di supporto per aggiungere un elemento alla lista
void push(list_t **head, int val) {
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

// Funzione di supporto per stampare la lista
void print_list(list_t *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Esempio di utilizzo
int main() {
    list_t *head = NULL;
    
    // Creazione della lista
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);
    
    printf("Lista originale:\n");
    print_list(head);
    
    // Applicazione della funzione di eliminazione condizionale
    conditional_delete(&head, 3, 4);
    
    printf("Lista dopo l'eliminazione di 3 se appare meno di 4 volte:\n");
    print_list(head);
    
    return 0;
}
