#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"
#include "linked-list-data.h"

void list_create_test()
{
    linked_list_data_t **list = linked_list_data_create();
    
    assert(list[0] == NULL);
    assert(list[1] == NULL);
}

void list_add_test()
{
    linked_list_data_t **list;
    
    data_t *data1;
    data_t *data2;
    
    data1 = malloc(sizeof(data_t));
    data1 -> value1 = 1;
    data1 -> value2 = 2;
    
    data2 = malloc(sizeof(data_t));
    data2 -> value1 = 3;
    data2 -> value2 = 4;
    
    
    list = linked_list_data_create();
    
    linked_list_data_add_first(list, data1);
    
    assert(list[0] == list[1]);
    assert(list[0] != NULL);
    assert(list[0] -> value == data1);
    assert(list[0] -> next  == NULL);
    
    assert(list[0] -> value -> value1 == 1);
    assert(list[0] -> value -> value2 == 2);
    
    linked_list_data_add_first(list, data2);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    assert(list[0] -> value == data2);
    assert(list[0] -> next  == list[1]);
    assert(list[1] -> value == data1);
    assert(list[1] -> next  == NULL);
    
    assert(list[0] -> value -> value1 == 3);
    assert(list[0] -> value -> value2 == 4);
    
    
    list = linked_list_data_create();
    
    linked_list_data_add_last(list, data1);
    
    assert(list[0] == list[1]);
    assert(list[0] != NULL);
    assert(list[0] -> value == data1);
    assert(list[0] -> next  == NULL);
    
    assert(list[0] -> value -> value1 == 1);
    assert(list[0] -> value -> value2 == 2);
    
    linked_list_data_add_last(list, data2);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    assert(list[0] -> value == data1);
    assert(list[0] -> next  == list[1]);
    assert(list[1] -> value == data2);
    assert(list[1] -> next  == NULL);
    
    assert(list[1] -> value -> value1 == 3);
    assert(list[1] -> value -> value2 == 4);
}

int main()
{
    list_create_test();
    list_add_test();
    
    return 0;
}
