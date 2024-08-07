#include <stdlib.h>
#include <stdio.h>

#define capacidade 7

typedef struct fila {
	int fila[capacidade];
	int ultimo_fila;
}fila;

int init(fila* initFila);
int add(fila* addFila, int n);
int peek(fila* peekFila);
int removeFila(fila* removeFila);
int list(fila* listFila);

int main(){
	fila fila;
	
	int op, valor;
	init(&fila);
	
	add(&fila, 10);
	add(&fila, 12);
	add(&fila, 9);
	add(&fila, 6);
	add(&fila, 5);
	add(&fila, 2);
	add(&fila, 0);
	
	list(&fila);
	printf("\n");
	
	removeFila(&fila);
	removeFila(&fila);
	removeFila(&fila);
	
	list(&fila);
	printf("\n");
	
	add(&fila, 10);
	add(&fila, 12);
	add(&fila, 9);
	
	list(&fila);
	return 0;
}

int init(fila* initFila) {
	initFila->ultimo_fila = -1;
	return 1;
}

int add(fila* addFila, int n){
	if (addFila->ultimo_fila + 1 < capacidade) {
		addFila->ultimo_fila++;
		addFila->fila[addFila->ultimo_fila] = n;
		return 1;
	} else {
		return 0;
	}
}

int peek(fila* peekFila) {
	if (peekFila->ultimo_fila > -1) {
		printf("%d", peekFila->fila[0]);
		return 1;
	} else {
		return 0;
	}
}

int removeFila(fila* removeFila) {
	if (removeFila->ultimo_fila > -1) {
		for (int i = 0; i < removeFila->ultimo_fila + 1; i++) {
			removeFila->fila[i] = removeFila->fila[i + 1];
		}
		removeFila->ultimo_fila--;
		return 1;
	} else {
		return 0;
	}
}

int list(fila* listFila) {
	if (listFila->ultimo_fila > -1) {
		for (int i = 0; i < listFila->ultimo_fila + 1; i++) {
			printf("%d\n", listFila->fila[i]);
		}
		return 1;
	}
	return 0;
}











