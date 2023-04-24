#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

struct fila_prioridade {
    struct no *cabeca;
};

struct fila_prioridade *criar_fila() {
    struct fila_prioridade *fila = (struct fila_prioridade*) malloc(sizeof(struct fila_prioridade));
    fila->cabeca = NULL;
    return fila;
}

void adicionar_elemento(struct fila_prioridade *fila, int valor) {
    struct no *novo_no = (struct no*) malloc(sizeof(struct no));
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if (fila->cabeca == NULL) {
        fila->cabeca = novo_no;
    } else if (valor > fila->cabeca->valor) { 
        novo_no->prox = fila->cabeca;
        fila->cabeca = novo_no;
    } else { 
        struct no *atual = fila->cabeca;
        while (atual->prox != NULL && valor <= atual->prox->valor) {
            atual = atual->prox;
        }
        novo_no->prox = atual->prox;
        atual->prox = novo_no;
    }
}

int remover_elemento(struct fila_prioridade *fila) {
    if (fila->cabeca == NULL) {
        printf("A fila está vazia.\n");
        return -1;
    } else {
        int valor = fila->cabeca->valor;
        fila->cabeca = fila->cabeca->prox;
        return valor;
    }
}

void imprimir_fila(struct fila_prioridade *fila) {
    struct no *atual = fila->cabeca;
    printf("Fila de prioridades: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    struct fila_prioridade *fila = criar_fila();

    adicionar_elemento(fila, 8);
    adicionar_elemento(fila, 4);
    adicionar_elemento(fila, 10);
    adicionar_elemento(fila, 3);
    adicionar_elemento(fila, 6);

    imprimir_fila(fila); 

    remover_elemento(fila);
    remover_elemento(fila);

    imprimir_fila(fila); 

    adicionar_elemento(fila, 9);
    adicionar_elemento(fila, 1);

    imprimir_fila(fila);

    remover_elemento(fila);
    remover_elemento(fila);
    remover_elemento(fila);
    remover_elemento(fila);
    remover_elemento(fila);
    remover_elemento(fila);

    imprimir_fila(fila); 

    free(fila);

    return 0;
}
