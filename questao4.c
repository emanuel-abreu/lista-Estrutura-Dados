#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
typedef struct no {
    float valor;
    struct no* prox;
} NO;

typedef struct pilha {
    NO* topo;
    int tam;
} PILHA;

void push(float valor, PILHA* p) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

float pop(PILHA* p) {
    if (p->tam > 0) {
        NO* aux = p->topo;
        float valor = aux->valor;
        p->topo = aux->prox;
        free(aux);
        p->tam--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

int main() {
    PILHA* p = (PILHA*) malloc(sizeof(PILHA));
    p->topo = NULL;
    p->tam = 0;

    char expressao[100];
    float operando;

    printf("Digite uma expressao pos-fixada (use espacos entre os operandos e operadores):\n");
    fgets(expressao, 100, stdin);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (isdigit(expressao[i])) { 
            operando = atof(&expressao[i]); 
            push(operando, p);
            while (isdigit(expressao[i + 1]) || expressao[i + 1] == '.') { 
                i++;
            }
        } else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/') { 
            float op1 = pop(p);
            float op2 = pop(p);
            float resultado;
            switch (expressao[i]) {
                case '+':
                    resultado = op2 + op1;
                    break;
                case '-':
                    resultado = op2 - op1;
                    break;
                case '*':
                    resultado = op2 * op1;
                    break;
                case '/':
                    resultado = op2 / op1;
                    break;
                default:
                    printf("Operador invalido!\n");
                    return -1;
            }
            push(resultado, p);
        }
    }
    printf("Resultado: %.2f\n", pop(p));
    return 0;
}
