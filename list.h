#ifndef LIST_H
#define LIST_H


typedef struct {
    int capacity;
    int index;
    int *items;
} t_list;

t_list* create_list(int max_capacity);
int destroy_list(t_list *list);
int size(t_list *list);
int is_full(t_list *list);
int is_empty(t_list *list);
int append(t_list *list, int elem);
int insert(t_list *list, int index, int elem);
int print_list(t_list *list);
int update(t_list *list, int element, int index);
int remove_by_index(t_list *list, int index);
int remove_by_element(t_list *list, int element);
int index_of(t_list *list, int element);
int get(t_list *list, int index);
int count(t_list *list, int element);
int clear(t_list *list);


#endif