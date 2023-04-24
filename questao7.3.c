#define TAMANHO_MAX_FILA 100

typedef struct {
    int inicio, fim;
    int dados[TAMANHO_MAX_FILA];
} Fila;

typedef struct {
    Fila fila1;
    Fila fila2;
} FilaDeFilas;

int fila_vazia(Fila *f) {
    return f->inicio == -1 && f->fim == -1;
}

int fila_cheia(Fila *f) {
    return (f->fim + 1) % TAMANHO_MAX_FILA == f->inicio;
}

void fila_enfileirar(Fila *f, int val) {
    if (fila_cheia(f)) {
        printf("Estouro da fila\n");
        return;
    }
    if (fila_vazia(f)) {
        f->inicio = f->fim = 0;
    } else {
        f->fim = (f->fim + 1) % TAMANHO_MAX_FILA;
    }
    f->dados[f->fim] = val;
}

int fila_desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    int val = f->dados[f->inicio];
    if (f->inicio == f->fim) {
        f->inicio = f->fim = -1;
    } else {
        f->inicio = (f->inicio + 1) % TAMANHO_MAX_FILA;
    }
    return val;
}

int fila_de_filas_vazia(FilaDeFilas *ff) {
    return fila_vazia(&ff->fila1) && fila_vazia(&ff->fila2);
}

void fila_de_filas_enfileirar(FilaDeFilas *ff, int val) {
    fila_enfileirar(&ff->fila1, val);
}

int fila_de_filas_desenfileirar(FilaDeFilas *ff) {
    if (fila_de_filas_vazia(ff)) {
        printf("Fila de filas vazia\n");
        return -1;
    }
    if (!fila_vazia(&ff->fila1)) {
        while (!fila_vazia(&ff->fila1)) {
            int val = fila_desenfileirar(&ff->fila1);
            fila_enfileirar(&ff->fila2, val);
        }
    }
    int val = fila_desenfileirar(&ff->fila2);
    while (!fila_vazia(&ff->fila2)) {
        int val = fila_desenfileirar(&ff->fila2);
        fila_enfileirar(&ff->fila1, val);
    }
    return val;
}
