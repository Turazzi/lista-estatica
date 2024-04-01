#include <stdio.h>

#include "list.h"
#include "list.c"

int main() {
    t_list *list = create_list(10);

    append(list, 4);
    append(list, 4);
    append(list, 4);
    append(list, 5);
    append(list, 7);
    append(list, 152);
    append(list, 1);
    append(list, 4);
    append(list, 5);
    append(list, 3);

    print_list(list);

    printf("%d\n", size(list));

    insert(list, 4, 163);
    print_list(list);

    update(list, 4, 165);
    print_list(list);

    remove_by_index(list, 4);
    printf("%d\n", size(list));
    print_list(list);

    remove_by_element(list, 152);
    printf("%d\n", size(list));
    print_list(list);

    index_of(list, 4);
    count(list, 4);

    destroy_list(list);

    return 0;
}