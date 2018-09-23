#ifndef STACK_ELEM_H
#define STACK_ELEM_H
#pragma GCC diagnostic ignored "-Wformat"

struct Stack_Elem
{
    struct Stack_Elem * next;
    void * data;
};

struct Stack_Elem* Stack_Elem_new( struct Stack_Elem* element, void* data );
void* Stack_Elem_delete( struct Stack_Elem* element );
void Stack_Elem_print( struct Stack_Elem* element );

#endif
