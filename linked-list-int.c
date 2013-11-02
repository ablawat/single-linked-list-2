#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

// Tworzy listę dowiązaniową
// -------------------------
LinkedListInt ** LinkedListIntCreate()
{
    LinkedListInt **list = malloc(sizeof(LinkedListInt *));
    list[0] = NULL;
    
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
            free(list[0]);
            list[0] = NULL;
        }
        else
        {
            tmpValue = list[0] -> next;
            free(list[0]);
            list[0] = tmpValue;
        }
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
        free(toRemove);
    }
    
    list[0] = NULL;
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
}
