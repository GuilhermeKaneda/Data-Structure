#include <stdio.h>

void main() {

    // Exemplo de vetor ordenado
    int vetor[7] = {10, 40, 70, 90, 120, 200, 300};
    // Tamanho do vetor (tamanho/unidade)
    int len = sizeof(vetor)/sizeof(vetor[0]);
    // Valor a ser encontrado
    int valor;
    scanf("%d", &valor);
    // Resultado da busca binaria
    int result = buscaBinaria(len, vetor, valor);

    if (result == -1)
        printf("Elemento nao encontrado");
    else
        printf("Elemento encontrado no index %d", result);
}

int buscaBinaria(int len, int * vetor, int valor){
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high){
        // Corta o vetor no meio
        mid = (low + high) / 2;
        // Caso o valor for menor que o valor da posição do meio, a posição final é torna-se o meio - 1, excluindo metade
        if (valor < vetor[mid])
            high = mid - 1;
        // Porém, caso for maior, a posição inicial torna-se a do meio + 1, excluindo a outra metade
        else if(valor > vetor[mid])
            low = mid + 1;
        // Agora, caso ela não for maior nem menor, o valor está na posição do meio, ou seja, ele foi encontrado
        else
            return mid;
    }

    // Caso a posição inicial da iteração do vetor for maior que a final, o elemento não está nele
    return -1;
}