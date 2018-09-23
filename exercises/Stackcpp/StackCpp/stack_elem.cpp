#include <stdio.h>
#include <stdlib.h>
#include "stack_elem.h"

Stack_Elem* Stack_Elem_new(Stack_Elem* next, void* data)
{
    Stack_Elem* nStack;
    nStack = new Stack_Elem;

    nStack->next = next;
    nStack->data = data;

    return nStack;
}


void* Stack_Elem::destroy()
{
    void* temp = data;
    delete this;
    return temp;
}

void Stack_Elem::print()
{
    printf("%p: {next=%p, data=%p}\n", this, this->next, this->data);
}
