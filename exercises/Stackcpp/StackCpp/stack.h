#pragma GCC diagnostic ignored "-Wformat"
# ifndef STACK_H
# define STACK_H

struct Stack_Elem;

class Stack
{
public:
    Stack_Elem* first;
    int size;
    void * (*data_new) (void *data);
    void (*data_delete) (void *data);
    void (*data_print) (void *data);

    Stack_Elem* invertlist(Stack_Elem *pListe);

    void reverse();

// Stack loeschen
    void destroy();

// Stack drucken
    void print();

// Anzahl der Elemente
    int getsize();

// Element vorne einfuegen
    Stack_Elem* push(void *data);

// Element vorne loeschen
    void * pop();

// Erstes Element
    Stack_Elem* getfirst();

// Naechstes Element
    Stack_Elem* getnext(Stack_Elem *i);

// Elemente Tauschen
    void swap(Stack_Elem *a, Stack_Elem *b);
};

Stack* neu(void * (*data_new) (void *data),
                             void (*data_delete) (void *data),
                             void (*data_print) (void *data));
# endif
