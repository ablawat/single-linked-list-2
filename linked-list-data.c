#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "linked-list-int.h"

// Tworzy listę dowiązaniową
// -------------------------
linked_list_data_t ** linked_list_data_create()
{
    linked_list_data_t **list = malloc(sizeof(linked_list_data_t *) * 2);
    list[0] = NULL;
    list[1] = NULL;
    
    return list;
}

// Dodaje element na początek listy
// --------------------------------
int linked_list_data_add_first(linked_list_data_t **list, data_t *value)
{
    linked_list_data_t *new_value = malloc(sizeof(linked_list_data_t));
    int result;
    
    if (new_value != NULL)
    {
        new_value -> value = value;
        
        if (list[0] == NULL)
        {
            new_value -> next = NULL;
            list[0] = new_value;
            list[1] = new_value;
        }
        else
        {
            new_value -> next = list[0];
            list[0] = new_value;
        }
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    
    return result;
}

// Dodaje element na koniec listy
// --------------------------------
int linked_list_data_add_last(linked_list_data_t **list, data_t *value)
{
    linked_list_data_t *new_value = malloc(sizeof(linked_list_data_t));
    int result;
    
    if (new_value != NULL)
    {
        new_value -> value = value;
        new_value -> next  = NULL;
        
        if (list[0] == NULL)
        {
            list[0] = new_value;
            list[1] = new_value;
        }
        else
        {
            list[1] -> next = new_value;
            list[1] = new_value;
        }
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    
    return result;
}

// Usuwa wszystkie elementy listy
// ------------------------------
void linked_list_data_clear(linked_list_data_t **list)
{
    linked_list_data_t *tmp_value = list[0];
    linked_list_data_t *to_remove;
    
    while (tmp_value != NULL)
    {
        to_remove = tmp_value;
        tmp_value = tmp_value -> next;
        free(to_remove -> value);
        free(to_remove);
    }
    
    list[0] = NULL;
    list[1] = NULL;
}

// Wyświetla zawartość listy
// -------------------------
void linked_list_data_print(linked_list_data_t **list)
{
    linked_list_data_t *tmp_value = list[0];
    
    printf("L");
    
    while (tmp_value != NULL)
    {
        printf("-|");
        printf("%d", tmp_value -> value -> value1);
        printf(",");
        printf("%d", tmp_value -> value -> value2);
        printf("|");
        tmp_value = tmp_value -> next;
    }
}
