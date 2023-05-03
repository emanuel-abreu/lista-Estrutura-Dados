#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //valores
    int valor;
    //mecanismo de ligacao de nos
    struct no * prox;
}NO;

typedef struct pilha{
    //valores
    NO * topo; //topo
    int tam;
}PILHA;

void add_pilha(int valor, PILHA *p){
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(p->topo == NULL){//pilha esta vazia
        p->topo = novo;
    }else {  //topo
        novo->prox = p->topo;
        p->topo = novo;
    }
    p->tam++;
}

int remover_pilha(int chave, PILHA *p){
    PILHA *p_aux = malloc(sizeof(PILHA)); //pilha auxiliar
    p_aux->topo = NULL;
    p_aux->tam = 0;

    NO * aux = p->topo;
    while(aux != NULL){
        if(aux->valor != chave){ //se a chave for diferente, empilhamos o item na pilha auxiliar
            add_pilha(aux->valor, p_aux);
        }
        aux = aux->prox;
    }

    p->topo = p_aux->topo;
    p->tam = p_aux->tam;

    //liberando memória da pilha auxiliar
    aux = p_aux->topo;
    while(aux != NULL){
        NO *lixo = aux;
        aux = aux->prox;
        free(lixo);
    }
    free(p_aux);

    if(p->tam > 0){ //se a pilha não estiver vazia, retorna o valor removido
        return chave;
    }else{
        printf("Pilha vazia! \n :(");
        return -1;
    }
}

void imprimir_pilha(PILHA *p){
    NO * aux = p->topo;
    for(int i = 0; i < p->tam; i++){
        printf("valor: %d\n", aux->valor);
        aux = aux->prox;
    }
}

int main(){
    PILHA *p = malloc(sizeof(PILHA));
    p->topo = NULL;
    p->tam = 0;

    add_pilha(10, p);
    add_pilha(20, p);
    add_pilha(30, p);
    add_pilha(40, p);
    add_pilha(50, p);

    imprimir_pilha(p);
    remover_pilha(30, p);
    imprimir_pilha(p);
    return 0;
}
