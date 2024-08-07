#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int valor;
    struct fila *prox;
}fila;


void init(fila** initFila);
int add(fila **addFila, int addValor);
int removeFila(fila **removeFila);
void peek(fila *peekFila);
int list(fila *listFila);
int finish(fila *finishFila);

int main() {
	fila *no;
    init(&no);
	
	add(&no, 20);
	add(&no, 0);
	add(&no, 50);
	add(&no, 8);
	add(&no, 90);
	add(&no, 3);
	add(&no, 14);
	add(&no, 71);

	
	list(no);
    printf("\n");

    removeFila(&no);
    removeFila(&no);
    removeFila(&no);
    removeFila(&no);

    list(no);


	
	
	finish(no);
	return 0;
}

void init(fila** initFila) {
    *initFila = NULL;
}


int add(fila **addFila, int addValor) {
	fila *no = malloc(sizeof(no));
	no->prox = NULL;
	no->valor = addValor;
	
	if (*addFila == NULL) {
		*addFila = no;
	} else {
        fila* aux = *addFila;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = no;
	}
    return 1;
}

int removeFila(fila **removeFila) {
    fila* aux = *removeFila;
	if (aux == NULL) {
		return 0;
	} else if (aux->prox == NULL) {
		free(*removeFila);
		*removeFila = NULL;
		return 1;
	} else {
		*removeFila = aux->prox;
		free(aux);
		return 1;
	}
}

void peek(fila *peekFila) {
	if (peekFila) {
        printf("%d", peekFila->valor);
    }
}

int list(fila *listFila) {
	fila *aux = listFila;
	while(aux != NULL) {
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	return 1;
}

int finish(fila *finishFila) {
    fila *aux = finishFila;
	if (finishFila != NULL) {
		while (aux != NULL) {
            aux = aux->prox;
			free(finishFila);
            finishFila = aux;
		}
		return 1;	
	}
	return 0;
}
