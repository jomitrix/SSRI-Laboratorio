#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity);
void push(Stack *stack, int elem);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
int size(Stack *stack);

int main() {
    Stack *stack = create_stack(5);

    printf("Is empty? -> %d\n", isEmpty(stack));
    printf("Size: %d\n", size(stack));

    for (int i = 1; i <= 5; i++) push(stack, i);
    printf("Pop List1:\n");
    for (int i = 0; i <= 5; i++) printf("%d\n", pop(stack));

    for (int i = 1; i <= 7; i++) push(stack, i);

    printf("Size: %d\n", size(stack));

    printf("\nPeek -> %d\n", peek(stack));

    printf("Is empty? -> %d\n", isEmpty(stack));

    printf("\nPop List2:\n");
    for (int i = 0; i <= 8; i++) printf("%d\t", pop(stack));
    printf("\n");

    printf("Is empty? -> %d\n", isEmpty(stack));

    return 0;
}

Stack* create_stack(int capacity) {
    Stack* stack = (Stack *) malloc(sizeof(Stack)); // Allocazione memoria per la struttura Stack
    stack->arr = (int *) malloc(capacity * sizeof(int)); // Allocazione dell'array dinamico
    stack->top = -1; // La pila è vuota inizialmente
    stack->capacity = capacity;

    return stack;
}

void push(Stack *stack, int elem) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity += 1;
        stack->arr = (int *) realloc(stack->arr, stack->capacity * sizeof(int));
    }

    stack->arr[++stack->top] = elem;
}

int pop(Stack *stack) {
    int elem = -1;

    if (stack->top != -1) {
        elem = stack->arr[stack->top];
        stack->arr[stack->top] = 0;
        stack->top--;
    } else {
        printf("\nERRORE: La pila è vuota.\n\n");
    }

    return elem;
}

int peek(Stack *stack) {
    int elem = -1;

    if (stack->top != -1) elem = stack->arr[stack->top];
    else printf("\nERRORE: La pila è vuota.\n\n");

    return elem;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

int size(Stack *stack) {
    return (stack->top + 1);
}