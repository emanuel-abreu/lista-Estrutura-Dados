#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
    int peso;
    struct Caixa* prox;
} Caixa;

typedef struct Pilha {
    Caixa* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void empilhar(Pilha* pilha, int peso) {
    Caixa* nova_caixa = (Caixa*)malloc(sizeof(Caixa));
    nova_caixa->peso = peso;
    nova_caixa->prox = pilha->topo;
    pilha->topo = nova_caixa;
}

int desempilhar(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    int peso = pilha->topo->peso;
    Caixa* caixa_removida = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(caixa_removida);
    return peso;
}

void imprimir_pilha(Pilha* pilha) {
    printf("[ ");
    Caixa* caixa_atual = pilha->topo;
    while (caixa_atual != NULL) {
        printf("%d ", caixa_atual->peso);
        caixa_atual = caixa_atual->prox;
    }
    printf("]\n");
}

void mover_caixas(Pilha* pilha_origem, Pilha* pilha_auxiliar_1, Pilha* pilha_auxiliar_2) {
    while (!pilha_vazia(pilha_origem)) {
        int peso = desempilhar(pilha_origem);
        if (peso == -1) {
            printf("Erro ao desempilhar\n");
            exit(1);
        }
        if (!pilha_vazia(pilha_auxiliar_1) && peso > pilha_auxiliar_1->topo->peso) {
            mover_caixas(pilha_auxiliar_1, pilha_origem, pilha_auxiliar_2);
        }
        if (!pilha_vazia(pilha_auxiliar_2) && peso > pilha_auxiliar_2->topo->peso) {
            mover_caixas(pilha_auxiliar_2, pilha_origem, pilha_auxiliar_1);
        }
        empilhar(pilha_auxiliar_1, peso);
    }
}

void voltar_caixas(Pilha* pilha_destino, Pilha* pilha_auxiliar_1, Pilha* pilha_auxiliar_2) {
    while (!pilha_vazia(pilha_auxiliar_1)) {
        int peso = desempilhar(pilha_auxiliar_1);
        if (peso == -1) {
            printf("Erro ao desempilhar\n");
            exit(1);
        }
        if (!pilha_vazia(pilha_auxiliar_2) && peso > pilha_auxiliar_2->topo->peso) {
            mover_caixas(pilha_auxiliar_2, pilha_destino, pilha_auxiliar_1);
        }
        empilhar(pilha_destino, peso);
    }
}
int main() {
    Pilha* pilhaA = criar_pilha();
    Pilha* pilhaB = criar_pilha();
    Pilha* pilhaC = criar_pilha();

    empilhar(pilhaA, 5);
    empilhar(pilhaA, 3);
    empilhar(pilhaA, 7);

    printf("Pilha A: ");
    imprimir_pilha(pilhaA);

    mover_caixas(pilhaA, pilhaB, pilhaC);

    printf("Pilha A: ");
    imprimir_pilha(pilhaA);
    printf("Pilha B: ");
    imprimir_pilha(pilhaB);
    printf("Pilha C: ");
    imprimir_pilha(pilhaC);

    voltar_caixas(pilhaA, pilhaB, pilhaC);

    printf("Pilha A: ");
    imprimir_pilha(pilhaA);
    printf("Pilha B: ");
    imprimir_pilha(pilhaB);
    printf("Pilha C: ");
    imprimir_pilha(pilhaC);

    return 0;
}
