#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_LEN 5

// Declaração da pilha
struct stack {
    // Vetor da pilha
    int vetor[MAX_LEN];
    // Posição do topo da pilha
    int top;
}; typedef struct stack Stack;

// Limpa a pilha
void reset(Stack *stack) {
    stack->top = -1;
}

// Adiciona um elemento
void push(int d, Stack *stack) {
    if(isFull(stack) == FALSE) {
        stack->top++;
        stack->vetor[stack->top] = d;
    } else 
        printf("\nPilha cheia");
}

// Remove um elemento
int pop(Stack *stack) {
    if(isEmpty(stack) == TRUE) {
        printf("\nPilha vazia");
        return NULL;
    }
    return(stack->vetor[stack->top--]);
}

// Retorna o elemento do topo
int top(Stack *stack) {
    return(stack->vetor[stack->top]);
}

// Verifica se a pilha está vazia
int isEmpty(const Stack *stack) { return(stack->top == -1); }
// Verifica se a pilha está cheia
int isFull(const Stack *stack) { return(stack->top > MAX_LEN - 1); }

int main() {
    Stack stackInt;
    int vetor[6] = {1, 2, 3, 4, 5, 6};
    reset(&stackInt);

    printf("Vetor original: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
        push(vetor[i], &stackInt);
    }

    push(7, &stackInt);

    printf("\nVetor invertido: ");
    while(!isEmpty(&stackInt))
        printf("%d ", pop(&stackInt));
    pop(&stackInt);
    return 0;
}