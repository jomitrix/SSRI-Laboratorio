#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *createNode(int val) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    
    return newNode;
}

int headInsert(Node **head, int val) {
    Node *newHead = createNode(val);
    if (newHead == NULL) return -1;

    if (*head != NULL) newHead->next = *head;
    *head = newHead;

    return 0;
}

int tailInsert(Node **head, int val) {
    Node *newTail = createNode(val);
    if (newTail == NULL) return -1;

    if (*head == NULL) *head = newTail;
    else {
        Node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newTail;
    }

    return 0;
}

Node *mergeLists(Node *head1, Node *head2) {
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *newList = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val > temp2->val) {
            if ((tailInsert(&newList, temp2->val)) == -1) return NULL;
            temp2 = temp2->next;
        } else {
            if ((tailInsert(&newList, temp1->val)) == -1) return NULL;
            temp1 = temp1->next;
        }
    }

    if (temp1 == NULL) temp1 = temp2;
    while (temp1 != NULL) {
        if ((tailInsert(&newList, temp1->val)) == -1) return NULL;
        temp1 = temp1->next;
    }
    
    return newList;
}

void removeDoubles(Node **head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    Node *temp = *head;
    Node *prev = NULL;

    do {
        prev = temp;
        temp = temp->next;

        if (prev->val == temp->val) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }

        //printf("previ->val %d\n", prev->val);
    } while (temp != NULL && temp->next != NULL);
}

void printList(Node *head) {
    Node *temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("END\n");
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;
    

    for (int i = 0; i <= 21; i+=2) tailInsert(&list1, i);
    for (int i = 0; i <= 21; i+=2) tailInsert(&list2, i);
    
    printList(list1);
    printList(list2);

    Node *list3 = mergeLists(list1, list2);
    printList(list3);

    removeDoubles(&list3);
    printList(list3);

}