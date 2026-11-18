#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node *next;
} node;

node *coppie(int n);
int aggiungiElem(node **head, int val1, int val2);
void printList(node *head);
void freeList(node **head);

int main() {
    node *out = coppie(11);
    printList(out);
    freeList(&out);
    printList(out);

    return 0;
}

node *coppie(int n) {
    node *res = NULL;
    int size = 0;

    for (int i = 1; i <= n/2; i++) {
        if (n-i != i) {
            if ((aggiungiElem(&res, i, n-i)) == -1) {
                printf("\nERRORE!\n"); return NULL;
            }
        }
    }

    return res;
}

int aggiungiElem(node **head, int val1, int val2) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) { printf("\nERRORE: Memoria Insufficiente.\n\n"); return -1; }

    newNode->x = val1;
    newNode->y = val2;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    return 0;
}

void printList(node *head) {
    node *temp = head;

    while(temp != NULL) {
        printf("(%d, %d)\t", temp->x, temp->y);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(node **head) {
    node *temp = *head;
    node *app;

    *head = NULL;

    while(temp != NULL) {
        app = temp;
        temp = temp->next;
        free(app);
    }
}