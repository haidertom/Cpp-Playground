#include <stdio.h>
#include <stdlib.h>
#include "stack_elem.h"
#include "stack.h"

struct Stack_Elem * Stack_Elem_new(
                                   struct Stack_Elem * element,
                                   void *data
                                   )
{
    struct Stack_Elem * Dyn = NULL;

                              //erzeugt einen dynamischen Speicher in den das neue Element und Daten geladen werden
    Dyn = (struct Stack_Elem *) malloc(sizeof(struct Stack_Elem));

     if(Dyn==NULL)
    {
        fprintf(stderr,"FeHlEr");
        exit(1);
    }
    Dyn->data = data;
    Dyn->next = element;
    return (Dyn);
}

void * Stack_Elem_delete(struct Stack_Elem * element)                   //gibt den Speicher der Elemenete frei
{
    if (element)
    {
        void* Dyn = element->data;
        free(element);
        return Dyn;
    }
    else
    {
        return (NULL);
    }
}

void Stack_Elem_print(struct Stack_Elem * element)
{
    printf(" %p: {next=%p, data=%p}", element, element->next, element->data);
}
