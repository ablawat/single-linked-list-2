#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

int main()
{
    Value *value1 = malloc(sizeof(Value));
    Value *value2 = malloc(sizeof(Value));
    Value *value3 = malloc(sizeof(Value));
    
    value1 -> number = 1;
    value2 -> number = 2;
    value3 -> number = 3;
    
    LinkedListInt **list = LinkedListIntCreate();
    
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value1);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value2);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value3);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntRemoveFirst(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value3);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value1);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntClear(list);
    LinkedListIntPrint(list);
    putchar(10);
    
    LinkedListIntAddFirst(list, value1);
    LinkedListIntPrint(list);
    putchar(10);
    
    return 0;
}
