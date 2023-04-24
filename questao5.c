#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char dado;
    struct no* proximo;
} No;

void inserir(No** cabeca, char dado) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

void exibir(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%c", atual->dado);
        atual = atual->proximo;
    }
}

int ehVogal(char c) {
    char vogais[] = "AEIOUaeiou";
    int i;
    for (i = 0; vogais[i] != '\0'; i++) {
        if (c == vogais[i]) {
            return 1;
        }
    }
    return 0;
}

void criptografar(No* cabeca) {
    No* atual = cabeca;
    No* inicio = cabeca;
    while (atual != NULL) {
        if ((atual->dado >= 'A' && atual->dado <= 'Z') || (atual->dado >= 'a' && atual->dado <= 'z')) {
            if (!ehVogal(atual->dado)) {
                No* fim = atual;
                while (fim->proximo != NULL && ((fim->proximo->dado >= 'A' && fim->proximo->dado <= 'Z') || (fim->proximo->dado >= 'a' && fim->proximo->dado <= 'z')) && !ehVogal(fim->proximo->dado)) {
                    fim = fim->proximo;
                }
                No* temp = fim->proximo;
                fim->proximo = NULL;
                while (atual != NULL) {
                    No* proximo = atual->proximo;
                    atual->proximo = temp;
                    temp = atual;
                    atual = proximo;
                }
                if (inicio == cabeca) {
                    cabeca = temp;
                } else {
                    inicio->proximo = temp;
                }
                inicio = fim;
                atual = temp;
            } else {
                inicio = atual;
                atual = atual->proximo;
            }
        } else {
            inicio = atual;
            atual = atual->proximo;
        }
    }
}

int main() {
    No* cabeca = NULL;
    char c;
    printf("Digite uma sequencia de caracteres: ");
    while ((c = getchar()) != '\n') {
        inserir(&cabeca, c);
    }
    criptografar(cabeca);
    printf("Sequencia criptografada: ");
    exibir(cabeca);
    printf("\n");
    return 0;
}
