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

    print_list(list);

    printf("tail: %d", list->tail->data);

//    return 0;
}
