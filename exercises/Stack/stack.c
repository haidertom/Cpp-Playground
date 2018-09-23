#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_elem.h"

struct Stack * Stack_new (
                          void * (* data_new) (void * data),
                          void (* data_delete) (void * data),
                          void (* data_print) (void * data)
                          )
{
    struct Stack * nStack = NULL;       //neuen Stack erstellen und diesen Null setzen

    nStack = (struct Stack *) malloc(sizeof(struct Stack));
    if(nStack==NULL)
    {
        fprintf(stderr,"FeHlEr");
        exit(1);
    }
    nStack->size = 0;
    nStack->first = NULL;
    nStack->data_new = data_new;
    nStack->data_delete = data_delete;
    nStack->data_print = data_print;

    return(nStack);
}

void Stack_delete (struct Stack * l)                            //Löscht den gesamten Stack
{
    if (l)
    {
        free(l);
    }
}

void Stack_print (struct Stack * l)                             //Gibt alle Elemente imStack aus
{
    if(l && l->first)
    {
        struct Stack_Elem * a = NULL;

        printf ("[size = %d, first = %p, data_new = %p, data_delete = %p, data_print = %p]:\n",
                l->size, l->first, l->data_new, l->data_delete, l->data_print);
        if(l->data_print)
        {
            a = l->first;
            while (a->next != NULL)
            {
                Stack_Elem_print(a);
                l->data_print (a->data);
                a = a->next;
            }
        }
    }
}

int Stack_sizeof (struct Stack * l)                         //liefert die Anzahl der Elmente auf dem Stack
{
    if(!l)
    {
        return (-1);
    }else{
        return (l->size);
    }
}

void Stack_push(struct Stack * l, void * data)              //Legt ein neues Element auf den Stapel indem es vorne in die verkette Liste eingefügt wird
{
    if( !l )
    {
        return;
    }

	struct Stack_Elem* Ret = NULL;
	void* Tmp = data;

	if( l->data_new )
	{
		Tmp = l->data_new( data );
	}
	Ret = Stack_Elem_new( l->first, Tmp );
	l->first = Ret;
	l->size++;


	return;
}

void* Stack_pop( struct Stack* l )                          //Liefert einen Pointer auf die Nutzdaten des zuletzt in den Stack eingefügten Elements zurück und entfernt das Element aus
                                                            //der verketteten Liste und löscht es (Speicherfreigabe).Das bisher zweite Element in der Liste soll dabei das neue erste Element werden.
{
	if( !l )
		return NULL;


	void* data = NULL;
	struct Stack_Elem* second_elem = l->first->next;

	data = Stack_Elem_delete( l->first );
	l->first = second_elem;
	l->size--;

	return data;
}

struct Stack_Elem * Stack_first (struct Stack * l)          //Liefert einen Pointer auf das erste Element imStack
{
    if (!l)
        return (NULL);

    return (l->first);
}

struct Stack_Elem * Stack_next (struct Stack_Elem * i)      //Liefert einen Pointer auf das (nach dem als Parameter übergebenen Element) nächste Element.
{
    if(!i)
        return (NULL);

    return (i->next);
}

void Stack_swap (struct Stack_Elem * a, struct Stack_Elem * b) // Vertauscht die beiden per Pointer übergebenen Stack_Elem-Elemente in der verketteten Liste, indem die beiden Pointeraddressen, welche auf die Nutzdaten zeigen ausgetauscht werden.
{
    if ( a && b)
       {
        void * temp = NULL;

        temp = a->data;
        a->data = b->data;
        b->data = temp;
       }
}



