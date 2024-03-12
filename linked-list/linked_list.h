//
// Created by dima2 on 11.03.2024.
//

#ifndef DATA_STRUCTURES_LINKED_LIST_H
#define DATA_STRUCTURES_LINKED_LIST_H

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;

struct linked_list {
    node_t* head;
    node_t* tail;
    int size;
};

typedef struct linked_list linked_list_t;

void push(linked_list_t* list, int data);
void print_list(linked_list_t* list);
linked_list_t* init();
void free_list(linked_list_t* list);
node_t* find_node_by_index(linked_list_t* list, int idx);
node_t* find_node_by_value(linked_list_t* list, int val);

int remove_first(linked_list_t* list);
int remove_last(linked_list_t* list);
int remove_item(linked_list_t *list, int value);
int remove_by_index(linked_list_t* list, int idx);

#endif //DATA_STRUCTURES_LINKED_LIST_H
