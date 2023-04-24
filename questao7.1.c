#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

typedef struct {
    Stack s1;
    Stack s2;
} FilaDePilhas;

void push(Stack *pilha, int val) {
    if (pilha->top == MAX_STACK_SIZE - 1) {
        printf("Estouro de pilha\n");
        return;
    }
    pilha->top++;
    pilha->data[pilha->top] = val;
}

int pop(Stack *pilha) {
    if (pilha->top == -1) {
        printf("Pilha vazia\n");
        return -1;
    }
    int val = pilha->data[pilha->top];
    pilha->top--;
    return val;
}

int filaDePilhasVazia(FilaDePilhas *fila) {
    return fila->s1.top == -1 && fila->s2.top == -1;
}

void enqueue(FilaDePilhas *fila, int val) {
    push(&fila->s1, val);
}

int dequeue(FilaDePilhas *fila) {
    if (filaDePilhasVazia(fila)) {
        printf("Fila vazia\n");
        return -1;
    }
    if (fila->s2.top == -1) {
        while (fila->s1.top != -1) {
            int val = pop(&fila->s1);
            push(&fila->s2, val);
        }
    }
    return pop(&fila->s2);
}

int main() {
    FilaDePilhas minhaFila = { .s1.top = -1, .s2.top = -1 };

    enqueue(&minhaFila, 10);
    enqueue(&minhaFila, 20);
    enqueue(&minhaFila, 30);

    printf("%d\n", dequeue(&minhaFila)); // 10
    printf("%d\n", dequeue(&minhaFila)); // 20
    printf("%d\n", dequeue(&minhaFila)); // 30
    printf("%d\n", dequeue(&minhaFila)); // Fila vazia

    return 0;
}
