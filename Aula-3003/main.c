#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
}Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int enfileirar(Fila *f, int valor) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));

    if (novo == NULL) {
        return -1;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if(f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }
}

int main() {

    return 0;
}