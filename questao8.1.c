#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento* prox;
} Elemento;

Elemento* criar_elemento(int valor) {
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->prox = NULL;
    return elemento;
}

void imprimir_fila(Elemento* inicio) {
    Elemento* atual = inicio;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("]\n");
}

void adicionar_elemento(Elemento** inicio, int valor) {
    Elemento* novo_elemento = criar_elemento(valor);
    Elemento* atual = *inicio;
    Elemento* anterior = NULL;

    while (atual != NULL && valor < atual->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo_elemento->prox = *inicio;
        *inicio = novo_elemento;
    } else {
        novo_elemento->prox = anterior->prox;
        anterior->prox = novo_elemento;
    }
}

int remover_elemento(Elemento** inicio) {
    if (*inicio == NULL) {
        printf("Fila vazia\n");
        return -1;
    }

    int valor = (*inicio)->valor;
    Elemento* temp = *inicio;
    *inicio = (*inicio)->prox;
    free(temp);
    return valor;
}

int main() {
    Elemento* fila = NULL;

    adicionar_elemento(&fila, 10);
    adicionar_elemento(&fila, 5);
    adicionar_elemento(&fila, 20);
    adicionar_elemento(&fila, 15);

    imprimir_fila(fila); // Output: [ 20 15 10 5 ]

    int valor_removido = remover_elemento(&fila);
    printf("Valor removido: %d\n", valor_removido); // Output: Valor removido: 20

    imprimir_fila(fila); // Output: [ 15 10 5 ]

    return 0;
}
