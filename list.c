#include <stdio.h>
#include <stdio.h>

#include "list.h"

t_list* create_list(int max_capacity) {
    t_list *list = (t_list*) malloc(sizeof(t_list));
    list->capacity = max_capacity;
    list->index = 0;
    list->items = (int*) malloc(max_capacity * sizeof(int));
    return list;
}

int destroy_list(t_list *list) {
    free(list->items);
    free(list);
    return 1;
}

int size(t_list *list) {
    return list->index;
}

int is_full(t_list *list) {
    return (list->index == list->capacity) ? 1 : 0;
}

int is_empty(t_list *list) {
    return (list->index == 0) ? 1 : 0;
}

int append(t_list *list, int elem) {
    if(!is_full(list)){
        list->items[list->index] = elem;
        list->index++;
        return 1;
    }
    return 0;
}

int insert(t_list *list, int index, int elem) {
    if(!is_full(list) && index < list->index) {
        for(int i = list->index - 1; i >= index; i--){
            list->items[i + 1] = list->items[i];
        }
        list->items[index] = elem;
        list->index++;
        return 1;
    }
    return 0;
}

int print_list(t_list *list) {
    if(!is_empty(list)) {
        for(int i = 0; i < list->index; i++) {
            printf("%d ", list->items[i]);
        }
        printf("\n");
        return 1;
    }
    return 0;
}

int update(t_list *list, int index, int element) {
    if(!is_empty(list) && index <= list->index) {
        list->items[index] = element;
        return 1;
    }
    return 0;
}

int remove_by_index(t_list *list, int index) {
    if(!is_empty(list) && index <= list->index) {
        for(int i = index; i < list->index; i++) {
            list->items[i] = list->items[i + 1];
        }
        list->index--;
        return 1;
    }
    return 0;
}

int remove_by_element(t_list *list, int element) {
    if(!is_empty(list)) {
        for(int i = 0; i < list->index; i++) {
            if(list->items[i] == element) {
                remove_by_index(list, i);
                return 1;
            }
        }
    }
    return 0;
}

int index_of(t_list *list, int element) {
    if(!is_empty(list)) {
        for (int i = 0; i < list->index; i++) {
            if(list->items[i] == element) {
                printf("\nIndex do elemento %d: %d\n", element, i);
                return i;
            }
        }
    }
    return 0;
}

int count(t_list *list, int element) {
    if(!is_empty(list)) {
        int count = 0; 
        for(int i = 0; i < list->index; i++){
            if(list->items[i] == element) count++;
        }
        printf("\n Quantidade de vezes em que %d aparece: %d\n", element, count);
        return 1;
    }
    return 0;
}

int clear(t_list *list) {
    list->index = 0;
    return 1; 
}