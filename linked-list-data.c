#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "linked-list-data.h"

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
    linked_list_data_t *new_item = malloc(sizeof(linked_list_data_t));
    int result;
    
    if (new_item != NULL)
    {
        new_item -> value = value;
        
        if (list[0] == NULL)
        {
            new_item -> next = NULL;
            list[0] = new_item;
            list[1] = new_item;
        }
        else
        {
            new_item -> next = list[0];
            list[0] = new_item;
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
    linked_list_data_t *new_item = malloc(sizeof(linked_list_data_t));
    int result;
    
    if (new_item != NULL)
    {
        new_item -> value = value;
        new_item -> next  = NULL;
        
        if (list[0] == NULL)
        {
            list[0] = new_item;
            list[1] = new_item;
        }
        else
        {
            list[1] -> next = new_item;
            list[1] = new_item;
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
    linked_list_data_t *list_item = list[0];
    linked_list_data_t *to_remove;
    
    while (list_item != NULL)
    {
        to_remove = list_item;
        list_item = list_item -> next;
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
    linked_list_data_t *list_item = list[0];
    
    printf("L");
    
    while (list_item != NULL)
    {
        printf("-|");
        printf("%d", list_item -> value -> value1);
        printf(",");
        printf("%d", list_item -> value -> value2);
        printf("|");
        
        list_item = list_item -> next;
    }
}
