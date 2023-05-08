#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no {
    char valor;
    struct no *prox;
} NO;

typedef struct pilha {
    NO *topo;
    int tam;
} PILHA;

void empilhar(char c, PILHA *p) {
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->valor = c;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

char desempilhar(PILHA *p) {
    if (p->tam == 0) {
        printf("Pilha vazia!\n");
        return '\0';
    }
    NO *aux = p->topo;
    char valor = aux->valor;
    p->topo = aux->prox;
    free(aux);
    p->tam--;
    return valor;
}

void exibir_pilha_inversa(PILHA *p) {
    while (p->tam > 0) {
        printf("%c", desempilhar(p));
    }
}

int main() {
    char c;
    PILHA *p = (PILHA *) malloc(sizeof(PILHA));
    p->topo = NULL;
    p->tam = 0;

    while (scanf("%c", &c) != EOF) {
        if (isalpha(c) && !strchr("aeiouAEIOU", c)) {
            empilhar(c, p);
        } else {
            printf("%c", c);
            exibir_pilha_inversa(p);
        }
    }

    while (p->tam > 0) {
        printf("%c", desempilhar(p));
    }

    free(p);
    return 0;
}
