//Tom H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "stack_elem.h"


Stack* neu(
                    void * (*data_new) (void *data),
                    void (*data_delete) (void *data),
                    void (*data_print) (void *data))
{
    Stack *nStack;
    nStack = new Stack;                     //= malloc(sizeof(struct Stack));
     if(nStack==NULL)
    {
        fprintf(stderr,"FEHLER");
        exit(1);
    }
    nStack->first = NULL;
    nStack->size = 0;
    nStack->data_new = data_new;
    nStack->data_delete = data_delete;
    nStack->data_print = data_print;

    return nStack;
}

void Stack::destroy()
{
    delete this;
}


void Stack::print()
{
    printf ("[ size =%d, first =%p, data_new =%p, data_delete =%p, data_print =%p ]:\n",
            size , first , data_new , data_delete , data_print );

    Stack_Elem* hStack;

    hStack=first;

    while(hStack != NULL)
    {
        hStack->print();
        hStack = hStack->next;
    }
}

int Stack::getsize()
{
    return size;
}

Stack_Elem* Stack::push(void *data)
{
    Stack_Elem* Ret;

    data=data_new(data);
    Ret=Stack_Elem_new(first, data);
    first=Ret;
    size++;
    return Ret;
}

void* Stack::pop()
{
    Stack_Elem *RET;

    RET = first;
    first = RET->next;
    size = size -1;

    return RET->destroy();
}

Stack_Elem* Stack::getfirst()
{
    return first;
}

Stack_Elem* Stack::getnext(Stack_Elem *next)
{
    return next->next;
}

void Stack::swap(Stack_Elem* temp1, Stack_Elem* temp2)
{
    void* pPoint;
    pPoint = temp1->data;
    temp1->data = temp2->data;
    temp2->data = pPoint;
}

void Stack::reverse()
{
    first = invertlist(first);
}

Stack_Elem* Stack::invertlist(Stack_Elem *pListe)
{
    if(pListe==NULL || pListe->next==NULL)
    {
        return pListe;
    }

    else
    {
        Stack_Elem *pTail;
        pTail = pListe->next;
        Stack_Elem* pRet;
        pRet = invertlist(pTail);
        pTail->next = pListe;
        pListe->next = NULL;
        return pRet;
    }
}
