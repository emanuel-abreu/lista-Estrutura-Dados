#include<stdio.h>
#include<stdlib.h>

typedef struct no{
 
    int valor;
    struct no * prox;
}NO;
typedef struct pilha{
  
    NO * topo; 
    int tam;

    struct pilha *prox;
}PILHA;

typedef struct fila{
    PILHA * inicio;
    PILHA * fim;
    int tam;
    struct fila *prox;
}FILA;

void add_fila(PILHA *p, FILA **f){
    FILA *nova_fila = malloc(sizeof(FILA));
    nova_fila->inicio = p;
    nova_fila->fim = p;
    nova_fila->tam = 1;
    nova_fila->prox = *f;
    *f = nova_fila;
}

void add_pilha(int valor, PILHA *p){
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

void imprimir_pilha(PILHA *p){
    NO * aux = p->topo;
    for(int i = 0; i<p->tam; i++){
        printf("valor: %d\n", aux->valor);
        aux = aux->prox;
    }
}

void imprimir_fila(FILA *f){
    int i = 0;
    PILHA * aux_pilha;
    while (f != NULL) {
        aux_pilha = f->inicio;
        printf("Fila %d:\n", i);
        while (aux_pilha != NULL) {
            imprimir_pilha(aux_pilha);
            aux_pilha = aux_pilha->prox;
        }
        f = f->prox;
        i++;
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
    }else{
        printf("Pilha vazia! \n :(");
        return -1;
    }
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

    FILA *fila_topo = NULL;
    add_fila(p1, &fila_topo);
    add_fila(p2, &fila_topo);

    imprimir_fila(fila_topo);
    return 0;
}
