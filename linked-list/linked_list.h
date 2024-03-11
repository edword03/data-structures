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

#endif //DATA_STRUCTURES_LINKED_LIST_H
