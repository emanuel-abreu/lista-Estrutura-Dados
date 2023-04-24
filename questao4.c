#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX_PILHA 100

typedef struct {
    int topo;
    int itens[TAMANHO_MAX_PILHA];
} Pilha;

void empilhar(Pilha* p, int valor) {
    if (p->topo == TAMANHO_MAX_PILHA - 1) {
        printf("Estouro da pilha!\n");
        exit(EXIT_FAILURE);
    } else {
        p->topo++;
        p->itens[p->topo] = valor;
    }
}

int desempilhar(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        exit(EXIT_FAILURE);
    } else {
        int valor = p->itens[p->topo];
        p->topo--;
        return valor;
    }
}

int main() {
    Pilha pilha;
    pilha.topo = -1;
    
    char input[100];
    printf("Digite a expressão: ");
    fgets(input, 100, stdin);
    
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            int numero = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                numero = numero * 10 + (input[i] - '0');
                i++;
            }
            empilhar(&pilha, numero);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            int operando2 = desempilhar(&pilha);
            int operando1 = desempilhar(&pilha);
            int resultado;
            switch (input[i]) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                default:
                    printf("Operador inválido!\n");
                    return 1;
            }
            empilhar(&pilha, resultado);
            i++;
        } else {
            i++;
        }
    }
    
    int resultado = desempilhar(&pilha);
    if (pilha.topo == -1) {
        printf("Resultado: %d\n", resultado);
    } else {
        printf("Expressão inválida!\n");
        return 1;
    }
    
    return 0;
}
