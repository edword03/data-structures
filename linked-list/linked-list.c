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
//    list->tail = tmp;
}

node_t* find_node_by_index(linked_list_t* list, int idx) {
    node_t *current = list->head;
    int count = 0;

    if (current == NULL) {
        printf("Error");
        return NULL;
    }

    if (idx > list->size - 1 || idx < 0) {
        printf("This index is out of list size");
        return NULL;
    }

    while (current->next != NULL && count != idx) {
        if(count == list->size - 1) {
            return current;
        }

        current = current->next;
        count++;
    }



    return current;
}

node_t* find_node_by_value(linked_list_t* list, int val) {
    node_t *current = list->head;

    if (current == NULL) {
        printf("Error");
        return NULL;
    }

    while (current->next != NULL && current->data != val) {
        current = current->next;
    }

    if (current->data == val) return current;

    printf("Not found");
    return NULL;
}

int remove_first(linked_list_t* list) {
    node_t* head = list->head;

    if (head == NULL) {
        printf("Head is NULL");
        return -1;
    }

    int value = head->data;

    node_t* tmp = head->next;

    free(head);
    list->head = tmp;
    list->size--;

    return value;
}

int remove_last(linked_list_t* list) {
    node_t* current = list->head;
    int val = 0;

    if (list->head == NULL) {
        printf("Head is NULL");
        return -1;
    }

    if (current->next == NULL) {
        val = current->data;
        free(current);

        return val;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    val = current->next->data;
    free(current->next);
    current->next = NULL;
    list->tail = current;
    list->size--;

    return val;
}

int remove_item(linked_list_t* list, int value) {
    node_t* current = list->head;
    node_t* prev = NULL;

    if (current == NULL) {
        printf("Head is NULL");
        return -1;
    }

    if (list->head->data == value) {
        return remove_first(list);
    }

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return -1;

    if (current->data == value) {
        prev->next = current->next;
        int val = current->data;

        free(current);
        list->size--;

        return val;
    }

    return -1;
}

int remove_by_index(linked_list_t* list, int idx) {
    int val;
    node_t* current = list->head;
    node_t* tmp = NULL;

    if (idx == 0) {
        return remove_first(list);
    }

    for (int i = 0; i < idx - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }

        current = current->next;
    }

    tmp = current->next;
    val = tmp->data;

    current->next = tmp->next;

    free(tmp);
    list->size--;

    return val;
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
