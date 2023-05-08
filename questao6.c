#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

struct pilha {
    int itens[TAM_MAX];
    int topo;
};

void inicializar(struct pilha *p) {
    p->topo = -1;
}

int esta_vazia(struct pilha *p) {
    return p->topo == -1;
}

int esta_cheia(struct pilha *p) {
    return p->topo == TAM_MAX - 1;
}

void empilhar(struct pilha *p, int item) {
    if (esta_cheia(p)) {
        printf("Erro: pilha cheia\n");
        exit(EXIT_FAILURE);
    }
    p->itens[++p->topo] = item;
}

int desempilhar(struct pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->itens[p->topo--];
}

void remover_item(struct pilha *p, int c) {
    struct pilha pilha_temporaria;
    inicializar(&pilha_temporaria);

    while (!esta_vazia(p)) {
        int item = desempilhar(p);
        if (item != c) {
            empilhar(&pilha_temporaria, item);
        }
    }

    while (!esta_vazia(&pilha_temporaria)) {
        int item = desempilhar(&pilha_temporaria);
        empilhar(p, item);
    }
}

int main() {
    struct pilha p;
    inicializar(&p);

    empilhar(&p, 1);
    empilhar(&p, 2);
    empilhar(&p, 3);
    empilhar(&p, 4);
    empilhar(&p, 5);

    printf("Pilha original:\n");
    while (!esta_vazia(&p)) {
        printf("%d\n", desempilhar(&p));
    }

    empilhar(&p, 1);
    empilhar(&p, 2);
    empilhar(&p, 3);
    empilhar(&p, 4);
    empilhar(&p, 5);

    int c;
    printf("Digite a chave do item a ser removido: ");
    scanf("%d", &c);
    remover_item(&p, c);

    printf("Pilha resultante:\n");
    while (!esta_vazia(&p)) {
        printf("%d\n", desempilhar(&p));
    }

    return 0;
}
