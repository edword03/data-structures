#include <stdio.h>
#include "linked-list/linked_list.h"

int main() {
    linked_list_t* list = init();

    if (!list) {
        printf("Malloc error");
        return 1;
    }

    push(list, 10);
    push(list, 20);
    push(list, 30);
    push(list, 40);

    print_list(list);

    remove_item(list, 40);

    printf("after remove \n");

    print_list(list);
    free_list(list);
}
