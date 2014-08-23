#ifndef LINKED_LIST_DATA_H
#define LINKED_LIST_DATA_H

typedef struct linked_list_data
{
    data_t                   *value;
    struct linked_list_data  *next;
}
linked_list_data_t;

linked_list_data_t ** linked_list_data_create();

int   linked_list_data_add_first  (linked_list_data_t **list, data_t *value);
int   linked_list_data_add_last   (linked_list_data_t **list, data_t *value);

void  linked_list_data_clear      (linked_list_data_t **list);
void  linked_list_data_print      (linked_list_data_t **list);

#endif
