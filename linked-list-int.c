#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

int ValueCompare(const void *value1, const void *value2)
{
    int result;
    
    Value **a1 = (Value **)value1;
    Value **a2 = (Value **)value2;
    
    int number1 = (*a1) -> number;
    int number2 = (*a2) -> number;
    
    if (number1 < number2)
        result = -1;
    else if (number1 == number2)
        result = 0;
    else
        result = 1;
    
    return result;
}

// Tworzy listę dowiązaniową
// -------------------------
LinkedListInt ** LinkedListIntCreate()
{
    LinkedListInt **list = malloc(2 * sizeof(LinkedListInt *) + sizeof(unsigned long));
    list[0] = NULL;
    list[1] = 0;
    
    return list;
}

// Dodaje element na początek listy
// --------------------------------
int LinkedListIntAddFirst(LinkedListInt **list, Value *value)
{
    LinkedListInt *newValue = malloc(sizeof(LinkedListInt));
    int result;
    
    if (newValue != NULL)
    {
        newValue -> value = value;
        
        if (list[0] == NULL)
        {
            newValue -> next = NULL;
            list[0] = newValue;
        }
        else
        {
            newValue -> next = list[0];
            list[0] = newValue;
        }
        
        list[1] = (LinkedListInt *)((unsigned long)list[1] + 1);
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    
    return result;
}

// Usuwa element z początku listy
// ------------------------------
void LinkedListIntRemoveFirst(LinkedListInt **list)
{
    LinkedListInt *tmpValue;
    
    if (list[0] != NULL)
    {
        if (list[0] -> next == NULL)
        {
            free(list[0] -> value);
            free(list[0]);
            list[0] = NULL;
        }
        else
        {
            tmpValue = list[0] -> next;
            free(list[0] -> value);
            free(list[0]);
            list[0] = tmpValue;
        }
        
        list[1] = (LinkedListInt *)((unsigned long)list[1] - 1);
    }
}

// Usuwa wszystkie elementy listy
// ------------------------------
void LinkedListIntClear(LinkedListInt **list)
{
    LinkedListInt *tmpValue = list[0];
    LinkedListInt *toRemove;
    
    while (tmpValue != NULL)
    {
        toRemove = tmpValue;
        tmpValue = tmpValue -> next;
        free(toRemove -> value);
        free(toRemove);
    }
    
    list[0] = NULL;
    list[1] = 0;
}

// Sortuje elementy listy
// ----------------------
void LinkedListIntSort(LinkedListInt **list)
{
    LinkedListInt *tmpValue;
    Value **listVector;
    
    unsigned long listCount;
    unsigned int i;

    listCount = (unsigned long)list[1];

    listVector = malloc(sizeof(Value *) * listCount);

    i = 0;
    tmpValue = list[0];

    while (tmpValue != NULL)
    {
        listVector[i] = tmpValue -> value;

        i += 1;
        tmpValue = tmpValue -> next;
    }

    qsort(listVector, listCount, sizeof(Value *), ValueCompare);

    i = 0;
    tmpValue = list[0];

    while (tmpValue != NULL)
    {
        tmpValue -> value = listVector[i];

        i += 1;
        tmpValue = tmpValue -> next;
    }

    free(listVector);
}

// Wyświetla zawartość listy
// -------------------------
void LinkedListIntPrint(LinkedListInt **list)
{
    LinkedListInt *tmpValue = list[0];
    
    printf("L");
    
    while (tmpValue != NULL)
    {
        printf("-|");
        printf("%d", tmpValue -> value -> number);
        printf("|");
        tmpValue = tmpValue -> next;
    }
    
    printf(" Count = %lu", (unsigned long)list[1]);
}
