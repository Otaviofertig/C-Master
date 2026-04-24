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