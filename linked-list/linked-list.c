#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t* createNode(int data) {
    node_t* temp = NULL;
    temp = (node_t*) malloc(sizeof(node_t));

    if (!temp) {
        printf("Malloc error");
        return NULL;
    }

    temp->next = NULL;
    temp->data = data;

    return temp;
}

void free_list(linked_list_t* list) {
    node_t* next;

    for (; list->head; list->head = next) {
        next = list->head->next;
        free(list->head);
    }
}

void print_list(linked_list_t* list) {
    node_t * current = list->head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void push(linked_list_t* list, int data) {
    node_t* current = list->head;
    node_t* tmp = createNode(data);

    if (current == NULL) {
        list->head = tmp;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = tmp;
    }

    list->size++;
    list->tail = tmp;
}

linked_list_t* init() {
    linked_list_t* linkedList = NULL;
    linkedList = (linked_list_t*) malloc(sizeof(linked_list_t));

    if (!linkedList)
        return NULL;

    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;

    return linkedList;
}

