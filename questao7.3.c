#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  
    int valor;
  
    struct no * prox;
} NO;

typedef struct pilha {
    
    NO * topo; 
    int tam;
    
    struct pilha *prox;
} PILHA;

typedef struct fila {
    PILHA * inicio;
    PILHA * fim;
    int tam;
} FILA;

void add_fila(PILHA *p, FILA *f){
    if(f->inicio == NULL){ 
        f->inicio = p;
        f->fim = p;
        f->tam++;
        p->prox = NULL;
    } else { 
        f->fim->prox = p;
        f->fim = p;
        p->prox = NULL;
        f->tam++;
    }
}

void add_pilha(int valor, PILHA *p){
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if(p->topo == NULL){ 
        p->topo = novo;
    } else {  
        novo->prox = p->topo;
        p->topo = novo;
    }
    p->tam++;
}

void imprimir_pilha(PILHA *p){
    NO * aux = p->topo;
    for(int i = 0; i < p->tam; i++){
        printf("valor: %d\n", aux->valor);
        aux = aux->prox;
    }
}

void imprimir_fila(FILA *f){
    PILHA * aux = f->inicio;
    for(int i = 0; i < f->tam; i++){
        printf("Pilha %d:\n", i);
        imprimir_pilha(aux);
        aux = aux->prox;
    }
}

int remover_pilha(PILHA *p){
    if(p->tam > 0){
        NO *lixo = p->topo;
        int valor = p->topo->valor;
        p->topo = p->topo->prox;
        free(lixo);
        p->tam--;
        return valor;
    } else {
        printf("Pilha vazia! \n :(");
        return -1;
    }
    return 0;
}

PILHA * inicia(){
    PILHA * aux = malloc(sizeof(PILHA));
    aux->topo = NULL;
    aux->tam = 0;
    return aux;
}

int main(){
    PILHA *p1 = inicia();
    add_pilha(18, p1);
    add_pilha(19, p1);

    PILHA *p2 = inicia();
    add_pilha(17, p2);
    add_pilha(28, p2);
    add_pilha(39, p2);
    add_pilha(45, p2);

    FILA *f1 = malloc(sizeof(FILA));
    f1->inicio = NULL;
    f1->fim = NULL;
    f1->tam = 0;

    add_fila(p1, f1);
    add_fila(p2, f1);

    imprimir_fila(f1);

    return 0;
}
