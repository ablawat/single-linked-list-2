#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

int ValueCompare(const void *value1, const void *value2);

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

// Sortuje elementy listy
// ----------------------
void LinkedListIntSort(LinkedListInt **list)
{
    LinkedListInt *tmpValue;
    Value **listVector;
    
    unsigned int listCount;
    unsigned int i;

    listCount = 0;
    tmpValue = list[0];

    while (tmpValue != NULL)
    {
        listCount += 1;
        tmpValue = tmpValue -> next;
    }

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
}

int ValueCompare(const void *value1, const void *value2)
{
    int result;
    
    int number1 = ((Value *)value1) -> number;
    int number2 = ((Value *)value2) -> number;
    
    if (number1 < number2)
        result = -1;
    else if (number1 == number2)
        result = 0;
    else
        result = 1;

    return result;
}
