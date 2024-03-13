#include <stdio.h>
#include "linked-list/linked_list.h"

int main() {
    linked_list_t* list = init();

    push(list, 10);
    push(list, 20);
    push(list, 30);
    push(list, 40);

    printf("find: %d \n", find_node_by_index(list, 3)->data);

    print_list(list);
    free_list(list);
}
