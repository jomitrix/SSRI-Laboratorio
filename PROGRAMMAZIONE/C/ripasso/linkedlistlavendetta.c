#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

node* createNode(int val);
void insertHead(node **, int);
void insertTail(node **, int);
void insertAtPosition(node **, int pos, int val);
void insertAtFirstOccurrence(node **, int, int);
void printList(node *);

int main(int argc, char *argv[]) {
    int count = 0;
    node *head;
    head = NULL;    

    printf("\n\n\n");
    printList(head);

    insertTail(&head, count++);
    printList(head);

    insertTail(&head, count++);
    printList(head);

    insertTail(&head, count++);
    printList(head);

    insertTail(&head, count++);
    printList(head);

    insertAtPosition(&head, 2, 7);
    printList(head);

    insertAtFirstOccurrence(&head, 7, 99);
    printList(head);
    

    return 0;
}

node* createNode(int val) {
    node* newNode;
    
    newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) { printf("\nERRORE: Allocazione dell'elemento NON riuscita.\n"); exit(1); }
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void insertHead(node **head, int val) {
    node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head; 
        *head = newNode;
    }
}

void insertTail(node **head, int val) {
    node *newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(node **head, int pos, int val) {
    node *newNode = createNode(val);
    node *temp = *head;
    int i = 2;

    if (pos < 1) { printf("\nERRORE: Posizione NON valida!\n\n"); return; }

    if (*head == NULL || pos == 1) {    // se posizione == 1 allora si richiede un inserimento in testa
        insertHead(head, val);
    } else {
        while (temp->next != NULL && i < pos) { // se posizione >= 2 allora si vuole inseirire in mezzo alla lista
            temp = temp->next;
            i++;
        }
        
        if (i == pos) { // se la lista è terminata prima della posizione richiesta, l'utente ha sbagliato la posizione
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("\nERRORE: Posizione NON valida!\n\n");
        }
    }
}

void insertAtFirstOccurrence(node **head, int valAfter, int val) {
    node *temp = *head;
    int app;

    if (*head == NULL) {
        printf("\nERRORE: Elemento NON trovato!\n\n");
        return;
    }
    
    while (temp->next != NULL && temp->val != valAfter) { // se posizione >= 2 allora si vuole inseirire in mezzo alla lista
        temp = temp->next;
    }

    if (temp->next != NULL) {   // rivedi casi d'uso cgpt
        insertHead(head, val);
    } else if (temp->val == valAfter) {
        node *newNode = createNode(temp->val);
        temp->val = val;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
            printf("\nERRORE: Elemento NON trovato!\n\n");
    }
}

void removeHead(node **head);
void removeTail(node **head);
void removeAtPosition(node **head, int pos);
void removeAtFirstOccurrence(node **head, int valAfter);
void removeAll(node **head);

void printList(node *head) {
    node *temp = head;
    
    printf("Print List:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("END\n");
}