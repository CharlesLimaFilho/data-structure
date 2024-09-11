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
void list(fila *listFila);
int finish(fila *finishFila);

int main() {
	fila *fila;
    int op, valorMain;
    init(&fila);
	
	for (;;) {
        printf("[1] - Adicionar\n[2] - Remover\n[3] - Ver o primeiro\n[4] - Listar todos\n[0] - Encerrar\n->");
        scanf(" %d", &op);

        switch (op) {
            case 1 :
                printf("\nDigite o valor que deseja adicionar: ");
                scanf("%d", &valorMain);
                add(&fila, valorMain);
                break;
            case 2:
                if (removeFila(&fila)) {
                    printf("\nRemovido com sucesso\n");
                } else {
                    printf("\nFila vazia\n");
                }
                break;
            case 3:
                peek(fila);
                break;
            case 4:
                printf("\n");
                list(fila);
                break;
            case 0:
                finish(fila);
                exit(0);
            default:
                printf("\nInsira um valor valido\n");
        }
    }
}


void init(fila** initFila) {
    *initFila = NULL;
}


int add(fila **addFila, int addValor) {
	fila *filaNova = malloc(sizeof(fila));
    filaNova->prox = NULL;
    filaNova->valor = addValor;
	
	if (*addFila == NULL) {
		*addFila = filaNova;
	} else {
        fila* aux = *addFila;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = filaNova;
	}
    return 1;
}

int removeFila(fila **removeFila) {
    fila* aux = *removeFila;
	if (aux == NULL) {
		return 0;
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

void list(fila *listFila) {
	fila *aux = listFila;
	while(aux != NULL) {
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
    printf("\n");
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
