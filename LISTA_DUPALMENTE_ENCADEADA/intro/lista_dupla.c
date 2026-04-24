#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode;

struct DNode_ {
    int info;
    DNode *next;
    DNode *previous;
};
typedef struct DLIST_ {
    DNode *head;
    DNode *tail;    
    int size;
}DList;

DList* create_list() {
    DList *list = (DList*) malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insert_head(DList *list, int value) {
    DNode *new_node = (DNode*) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->previous = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->previous = new_node;
    }
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

void insert_tail(DList *list, int value) {
    DNode *new_node = (DNode*) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->next = NULL;
    new_node->previous = list->tail;

    
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }

    
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
    list->size++;
}

// EXERCÍCIO 3: Busca Reversa (do Tail para o Head)
int buscar_paciente_reverso(DList *list, int id_procurado) {
    DNode *atual = list->tail; // Começa no tail

    while (atual != NULL) {
        if (atual->info == id_procurado) {
            return 1;
        }
        atual = atual->previous; // Procura de trás para frente
    }
    return 0; 
}

// EXERCÍCIO 4: Inserir no meio (depois de um nó 'atual')
void insert_after(DList *list, DNode *atual, int value) {
    if (atual == NULL) return; 
    
    if (atual == list->tail) {
        insert_tail(list, value);
        return;
    }

    DNode *novo = (DNode*) malloc(sizeof(DNode));
    novo->info = value;

    
    novo->next = atual->next;     
    novo->previous = atual;       
    atual->next->previous = novo; 
    atual->next = novo;           

    list->size++;
}