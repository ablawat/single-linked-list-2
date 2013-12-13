#ifndef LINKED_LIST_INT

    typedef struct linkedListInt
    {
        Value                   *value;
        struct linkedListInt    *next;
    }
    LinkedListInt;
    
    LinkedListInt ** LinkedListIntCreate();
    int  LinkedListIntAddFirst(LinkedListInt **list, Value *value);
    void LinkedListIntRemoveFirst(LinkedListInt **list);
    void LinkedListIntClear(LinkedListInt **list);
    void LinkedListIntSort(LinkedListInt **list);
    
    void LinkedListIntPrint(LinkedListInt **list);
    
    #define LINKED_LIST_INT

#endif
