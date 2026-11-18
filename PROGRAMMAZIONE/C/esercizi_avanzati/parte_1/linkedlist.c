#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

node *createNode(int val);
int headInsert(node **head, int val);
int tailInsert(node **head, int val);
int positionInsert(node **head, int pos, int val);
int headRemove(node **head);
int tailRemove(node **head);
int positionRemove(node **head, int pos);
int valueRemove(node **head, int val);
void clearList(node **head);
int searchPosition(node *head, int val);
node *search(node *head, int val);
void printList(node *head);

int main() {
    node *head = NULL;

    for (int i = 1; i <= 5; i++) {
        positionInsert(&head, i, i);
        printList(head);
    }

    printf("XXX\n");

    valueRemove(&head, 1);
    printList(head);

    clearList(&head);

    return 0;
}

node *createNode(int val) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int headInsert(node **head, int val) {
    node *newHead = createNode(val);
    if (newHead == NULL) return -1;

    if (*head == NULL) {
        *head = newHead;
    } else {
        newHead->next = *head;
        *head = newHead;
    }

    return 0;
}

int tailInsert(node **head, int val) {
    node *newTail = createNode(val);
    if (newTail == NULL) return -1;

    if (*head == NULL) {
        *head = newTail;
    } else {
        node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newTail;
    }

    return 0;
}

int positionInsert(node **head, int pos, int val) {
    if (pos <= 1) {
        return headInsert(head, val);
    } else if ((*head) == NULL) return -1;
    else {
        int i = 2;
        node *newNode = createNode(val);
        node *temp = *head;

        while (i < pos && temp->next != NULL) temp = temp->next, i++;

        node* app = temp->next;
        temp->next = newNode;
        newNode->next = app;
    }

    return 0;
}

int headRemove(node **head) {
    if (*head == NULL) {
        return -1;
    } else {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    return 0;
}

int tailRemove(node **head) {
    if (*head == NULL) {
        return -1;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node *temp = *head;

        while (temp->next->next != NULL) temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }

    return 0;
}

int positionRemove(node **head, int pos) {
    if (*head == NULL) return -1;

    if (pos <= 1) return headRemove(head);

    node *temp = *head;
    node *prev = NULL;
    int i = 1;

    while (i < pos && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i < pos) return -1;

    prev->next = temp->next;
    free(temp);

    return 0;
}

int valueRemove(node **head, int val) {
    int pos = searchPosition(*head, val);
    if (pos != -1) {
        return positionRemove(head, pos);
    }

    return -1;
}

void clearList(node **head) {
    while (headRemove(head) == 0);
    printf("Lista svuotata correttamente.\n");
}

int searchPosition(node *head, int val) {
    node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->val == val) return pos;
        temp = temp->next;
        pos++;
    }
    
    return -1;
}

node *search(node *head, int val) {
    node *temp = head;

    while (temp != NULL) {
        if (temp->val == val) return temp;
        temp = temp->next;
    }

    return NULL;
}

int updateValue(node **head, int oldVal, int newVal) {
    node *toUpdate = search(*head, oldVal);
    if (toUpdate != NULL) { toUpdate->val = newVal; return 0; }

    return -1;
}

void printList(node *head) {
    node *temp = head;

    if (temp != NULL) {
        while (temp != NULL) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("END\n");
    } else {
        printf("La lista è vuota.\n");
    }
}