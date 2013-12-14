#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

int main()
{
    Value *value;
    
    LinkedListInt **list = LinkedListIntCreate();
    
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 1;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 2;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 3;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 3;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 1;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntClear(list);
    LinkedListIntPrint(list);
    putchar(10);

    value = malloc(sizeof(Value));
    value -> number = 4;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);

    value = malloc(sizeof(Value));
    value -> number = 6;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);

    value = malloc(sizeof(Value));
    value -> number = 2;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 5;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);
    
    value = malloc(sizeof(Value));
    value -> number = 1;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);

    value = malloc(sizeof(Value));
    value -> number = 3;
    LinkedListIntAddFirst(list, value);
    LinkedListIntPrint(list);
    putchar(10);

    LinkedListIntSort(list);
    LinkedListIntPrint(list);
    putchar(10);

    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);

    return 0;
}
