#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *creaNodo(int val) {
    Node *newNodo = (Node *) malloc(sizeof(Node));

    newNodo->val = val;
    newNodo->next = NULL;

    return newNodo;
}

void aggiungiOrd(Node **head, int val) {
    Node *newNodo = creaNodo(val);

    if (*head == NULL) {
        *head = newNodo;
    } else if ((*head)->val > val) {
        newNodo->next = *head;
        *head = newNodo;
    } else {
        Node *temp = *head;

        while (temp->next != NULL && temp->next->val < val) {
            temp = temp->next;
        }

        newNodo->next = temp->next;
        temp->next = newNodo;
    }
}

void printList(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("END\n");
}

Node *cerca(Node *head, int val) {
    Node *temp = head;

    while(temp != NULL && temp->val != val) temp=temp->next;

    return temp;
}

Node *reverse(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    Node *l = NULL;

    aggiungiOrd(&l, 3);
    aggiungiOrd(&l, 1);
    aggiungiOrd(&l, 4);
    aggiungiOrd(&l, 2);
    aggiungiOrd(&l, 5);
    aggiungiOrd(&l, 0);
    aggiungiOrd(&l, 4);
    aggiungiOrd(&l, 0);
    aggiungiOrd(&l, 5);

    printList(l);
    Node *out = cerca(l, 1);

    printList(reverse(l));

    return 0;
}