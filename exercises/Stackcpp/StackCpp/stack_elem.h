#pragma GCC diagnostic ignored "-Wformat"

# ifndef STACK_ELEM_H
# define STACK_ELEM_H

class Stack_Elem{public: Stack_Elem* next;
                         void* data;
                         void* destroy();
                         void print();
                };

Stack_Elem* Stack_Elem_new(Stack_Elem* next, void* data);

# endif

