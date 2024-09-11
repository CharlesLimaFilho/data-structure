#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria {
    int valor;
    struct arvoreBinaria *esq;
    struct arvoreBinaria *dir;
} arvore;

typedef struct no {
    arvore *noa;
    struct no *prox;
} noL;

arvore *inserir(arvore *raiz, int valor);
arvore *buscar(arvore *raiz, int valor);
arvore *remover(arvore *raiz, int valor);
void preOrdem(arvore *raiz);
void emOrdem(arvore *raiz);
void posOrdem(arvore *raiz);
void inserirFinalL(noL **l, arvore *enoa);
void inserirComecoL(noL **l, arvore *enoa);
noL *removerComecoL(noL **lista);
void buscaLargura(arvore *raizL);
void buscaProfundidade(arvore *raizL);

int main() {
    arvore *noa = NULL;
    noa = inserir(noa, 10);
    noa = inserir(noa, 20);
    noa = inserir(noa, 1);
    noa = inserir(noa, 5);
    noa = inserir(noa, 6);
    noa = inserir(noa, 21);
    noa = inserir(noa, 40);
    noa = inserir(noa, 30);
    noa = inserir(noa, 22);

    preOrdem(noa);
    printf("\n");
    emOrdem(noa);
    printf("\n");
    posOrdem(noa);
    printf("\n\n");
    buscaLargura(noa);
    printf("\n");
    buscaProfundidade(noa);
    printf("\n");
    noa = remover(noa, 10);
    noa = remover(noa, 20);
    noa = remover(noa, 1);
    noa = remover(noa, 5);
    noa = remover(noa, 6);
    noa = remover(noa, 21);
    noa = remover(noa, 40);
    noa = remover(noa, 30);
    noa = remover(noa, 22);
    return 0;
}

arvore *inserir(arvore *raiz, int valor) {
    if (!raiz) {
        arvore *novo = malloc(sizeof(arvore));
        novo->valor = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    } else if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    return raiz;
}

arvore *buscar(arvore *raiz, int valor) {
    if (!raiz) {
        return NULL;
    }

    if (valor > raiz->valor) {
        raiz->dir = buscar(raiz->dir, valor);
        return raiz;
    } else if (valor < raiz->valor) {
        raiz->esq = buscar(raiz->esq, valor);
        return raiz;
    }
    return raiz;
}

arvore *remover(arvore *raiz, int valor) {
    if (!raiz) {
        return NULL;
    }

    if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
        return raiz;
    } else if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
        return raiz;
    }

    if (!raiz->esq && !raiz->dir) {
        free(raiz);
        return NULL;
    } else if (raiz->esq && raiz->dir) {
        arvore *pAux = raiz;
        arvore *aux = raiz->esq;
        while (aux->dir) {
            pAux = aux;
            aux = aux->dir;
        }
        if (pAux != raiz) {
            pAux->dir = aux->esq;
            aux->esq = raiz->esq;
        }
        aux->dir = raiz->dir;
        free(raiz);
        return aux;

    } else {
        arvore *aux = (raiz->dir ? raiz->dir : raiz->esq);
        free(raiz);
        return aux;
    }
}

void preOrdem(arvore *raiz) {
    if (!raiz) {
        return;
    }

    printf("%d ", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void emOrdem(arvore *raiz) {
    if (!raiz) {
        return;
    }

    emOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    emOrdem(raiz->dir);
}

void posOrdem(arvore *raiz) {
    if (!raiz) {
        return;
    }

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d ", raiz->valor);
}


void inserirComecoL(noL **l, arvore *enoa) {
    if (!enoa) {
        return;
    }

    noL *novo = malloc(sizeof(noL));
    novo->noa = enoa;
    novo->prox = NULL;

    if (!*l) {
        *l = novo;
        return;
    }

    novo->prox = *l;
    *l = novo;
}

void inserirFinalL(noL **l, arvore *enoa) {
    if (!enoa) {
        return;
    }

    noL *novo = malloc(sizeof(noL));
    novo->noa = enoa;
    novo->prox = NULL;

    if (!*l) {
        *l = novo;
        return;
    }

    noL *aux = *l;
    while (aux->prox) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

noL *removerComecoL(noL **lista) {
    if (!*lista) {
        return NULL;
    }
    noL *aux = *lista;
    *lista = (*lista)->prox;
    return aux;
}

void buscaLargura(arvore *raizL) {
    if (!raizL) {
        return;
    }

    noL *borda = NULL;
    inserirFinalL(&borda, raizL);

    while (borda) {
        noL *comeco = removerComecoL(&borda);
        arvore *no_arvore = comeco->noa;
        printf("%d ", no_arvore->valor);
        inserirFinalL(&borda, no_arvore->esq);
        inserirFinalL(&borda, no_arvore->dir);
        free(comeco);
    }
}

void buscaProfundidade(arvore *raizL) {
    if (!raizL) {
        return;
    }

    noL *borda = NULL;
    inserirFinalL(&borda, raizL);

    while (borda) {
        noL *comeco = removerComecoL(&borda);
        arvore *no_arvore = comeco->noa;
        printf("%d ", no_arvore->valor);
        inserirComecoL(&borda, no_arvore->esq);
        inserirComecoL(&borda, no_arvore->dir);
        free(comeco);
    }
}