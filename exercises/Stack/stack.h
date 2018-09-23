#ifndef STACK_H
#define STACK_H
#pragma GCC diagnostic ignored "-Wformat"

struct Stack_Elem;

struct Stack
{
    struct Stack_Elem * first;
    int size;
    void * (* data_new) (void * data);
    void (* data_delete) ( void * data );
    void (* data_print) ( void * data );
};

// neuen Stack erzeugen
struct Stack * Stack_new(void * (*data_new) (void *data),
                         void (*data_delete) (void *data),
                         void (*data_print) (void *data));

// Stack loeschen
void Stack_delete(struct Stack *l);

// Stack drucken
void Stack_print(struct Stack *l);

// Anzahl der Elemente
int Stack_sizeof(struct Stack *l);

// Element vorne einfuegen
void Stack_push(struct Stack *l, void *data);

// Element vorne loeschen
void * Stack_pop(struct Stack *l);

// Erstes Element
struct Stack_Elem * Stack_first(struct Stack *l);

// Naechstes Element
struct Stack_Elem * Stack_next(struct Stack_Elem *i);

// Elemente Tauschen
void Stack_swap(struct Stack_Elem *a, struct Stack_Elem *b);

#endif
