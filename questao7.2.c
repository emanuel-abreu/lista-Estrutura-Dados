#define MAX_QUEUE_SIZE 100

typedef struct {
    int frente, tras;
    int dados[MAX_QUEUE_SIZE];
} Fila;

typedef struct {
    Fila q1;
    Fila q2;
} PilhaDeFilas;

int fila_vazia(Fila *f) {
    return f->frente == -1 && f->tras == -1;
}

int fila_cheia(Fila *f) {
    return (f->tras + 1) % MAX_QUEUE_SIZE == f->frente;
}

void fila_enfileirar(Fila *f, int val) {
    if (fila_cheia(f)) {
        printf("Estouro da Fila\n");
        return;
    }
    if (fila_vazia(f)) {
        f->frente = f->tras = 0;
    } else {
        f->tras = (f->tras + 1) % MAX_QUEUE_SIZE;
    }
    f->dados[f->tras] = val;
}

int fila_desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila Vazia\n");
        return -1;
    }
    int val = f->dados[f->frente];
    if (f->frente == f->tras) {
        f->frente = f->tras = -1;
    } else {
        f->frente = (f->frente + 1) % MAX_QUEUE_SIZE;
    }
    return val;
}

void pilha_de_filas_empilhar(PilhaDeFilas *p, int val) {
    fila_enfileirar(&p->q1, val);
}

int pilha_de_filas_desempilhar(PilhaDeFilas *p) {
    if (fila_vazia(&p->q1)) {
        printf("Pilha Vazia\n");
        return -1;
    }
    while (!fila_vazia(&p->q1) && p->q1.frente != p->q1.tras) {
        int val = fila_desenfileirar(&p->q1);
        fila_enfileirar(&p->q2, val);
    }
    int val = fila_desenfileirar(&p->q1);
    Fila temp = p->q1;
    p->q1 = p->q2;
    p->q2 = temp;
    return val;
}
