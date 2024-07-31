#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Declaração de uma posição da fila
struct queue {
    // Valor da posição
    int data;
    // Ponteiro para a proxima posição
    struct queue *next;
}; 
typedef struct queue queue;

// Cria uma posição
queue *create_position(int d) {
    queue *head = (queue *)malloc(sizeof(queue));
    head->data = d;
    // Última posição criada, ou seja, aponta para NULL
    head->next = NULL;
    return head;
}

// Adiciona uma posição
queue *enqueue(int d, queue *h) {
    queue *head = create_position(d);
    head->next = h;
    return head;
}

// Verifica se a fila está vazia
int isEmpty(queue *l) { return (l->next == NULL); }

// Remove a primeira posição
queue *dequeue(queue *h) {
    if(isEmpty(h) == TRUE) {
        printf("Fila vazia\n");
        return NULL;
    }

    // Cria uma copia da fila
    queue *aux = h;
    // Itera a fila até encontrar a segunda posição
    while (aux->next->next != NULL)
        aux = aux->next;
    
    // Remove a primeira posição
    aux->next = NULL;
    
    return h;
}

// Imprime todas as posições
void print_queue(queue *h) {
    // Itera toda a fila
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main() {
    queue *head = NULL;

    for (int i = 0; i < 5; i++)
        head = enqueue(i, head);

    print_queue(head); 

    for (int i = 0; i < 5; i++) {
        head = dequeue(head);
        print_queue(head); 
    }

    return 0;
}
