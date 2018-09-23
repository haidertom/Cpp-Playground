/*
 * Generic Stacked List
 * Michael Farmbauer (C) 2015
 */

// Mit dem Testlevel wird festgelegt, was alles getestet werden soll.
// Der Wert muss immer weiter erhoeht werden, bis alle Tests durchgeführt wurden.
#define test_level 9

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stack_elem.h"

int usage_cnt_new=0;
int usage_cnt_delete=0;
int usage_cnt_print=0;

void *my_data_new(void *data)
{
    usage_cnt_new++;
    if (!data)
    {
        return NULL;
    }
    char * copy;
    copy=malloc(strlen(data)+1);
    strcpy(copy, data);
    return copy;
}

void my_data_delete(void *data)
{
    usage_cnt_delete++;
    if (data)
    {
        free(data);
    }
}

void my_data_print(void *data)
{
    usage_cnt_print++;
    if (!data)
    {
        printf ("NULL");
        return;
    }
    char *str=data;
    printf ("%s", str);
}

/* Diese Makrodefinition beinhaltet einen kleinen Codegenerator. Das Makro wird
 * mit zwei Parametern aufgerufen, nämlich der Bedingung, welche getestet werden soll, und
 * dem Text, der zur Erläuterung ausgegeben werden soll. Daraus wird dann je nach
 * Testergebnis eine Meldung ausgegeben und ggf. das Programm abgebrochen.
 */
#define test(cond, failure_message) {printf("Test: (%s) ... ",#cond);\
    if(cond) {printf("OK\n");} else {printf("%s\n", failure_message);abort();}}

int main()
{
    struct Stack_Elem * selem;

    char test_str[]="Erster Test von Stack Elem";
    void *data, *data_to_delete;
    // test fuer Stack_elem_new
    selem = Stack_Elem_new(NULL, my_data_new(test_str));
    printf( "\n\nFolgende Zeile muss folgendermassen aussehen:\n"
            " 0x........: {next=(nil)     , data=0x........}: Erster Test von Stack Elem\n");
    Stack_Elem_print(selem);
    my_data_print(selem->data);
    printf("\n");
    // test Stack_elem_delete
    data=selem->data;
    data_to_delete=Stack_Elem_delete(selem);
    test (data == data_to_delete, "Stack_elem_delete muss einen Zeiger auf die Nutzdaten zurueck geben.");
    my_data_delete(data);
    // remove NULL-Element
    Stack_Elem_delete(NULL);
    printf("\n\n Test Level 0 abgeschlossen.\n\n");

#if test_level >0

    struct Stack *stack;

    printf("Tests fuer Stack_new ...\n Aufruf: %s\n\n", "stack = Stack_new(my_data_new, my_data_delete, my_data_print);");
    stack = Stack_new(my_data_new, my_data_delete, my_data_print);
    test (stack->data_new == my_data_new, "Stack_new Funktionszeiger data_new nicht richtig initialisiert.");
    test (stack->data_delete == my_data_delete, "Stack_new Funktionszeiger data_delete nicht richtig initialisiert.");
    test (stack->data_print == my_data_print, "Stack_new Funktionszeiger data_print nicht richtig initialisiert.");
    test (stack->size == 0, "Stack_new size muss mit 0 initialisiert werden.");
    test (Stack_sizeof(stack) == 0, "Stack_sizeof() muss 0 liefern.");
    test (stack->first == NULL, "Stack_new first muss mit NULL initialisiert werden.");
    printf("\n\n Test Level 1 abgeschlossen.\n\n");
#endif

#if test_level >1
    // Tests fuer Stack_push
    char inhalte[6][10] = {"null", "eins", "zwei", "drei", "vier", "fuenf"};
    struct Stack_Elem *first, *second;
    void *returndata;

    printf("Tests fuer Stack_push ...\n Aufruf: %s\n\n","Stack_push(stack, fuenf);");
    Stack_push(stack, inhalte[5]);
    test (stack->first != NULL, "Stack_push setzt first im stack nicht.");
    test (stack->size == 1, "Stack_push erhoeht size nicht.");
    test (Stack_sizeof(stack) == 1, "Stack_sizeof() muss 1 liefern.");
    test (stack->first->next==NULL, "Stack_push setzt Verkettungsinformation nicht korrekt.");
    test (stack->first->data!=NULL, "Stack_push initialisiert data nicht richtig.");
    test (stack->first->data!=inhalte[5], "Stack_push ruft data_new nicht auf oder verwendet dessen Rueckgabewert nicht korrekt.");

    // Tests für Stack_pop
    printf("\nTests fuer Stack_pop ...\n Aufruf: %s\n\n","returndata = Stack_pop(stack);");
    returndata = Stack_pop(stack);
    test (strcmp(returndata, inhalte[5]) == 0, "Daten werden nicht korrekt zurueckgegeben.");
    test (stack->size == 0, "Stack_pop reduziert size nicht.");
    test (Stack_sizeof(stack) == 0, "Stack_sizeof() muss 0 liefern.");
    test (stack->first == NULL, "Stack_pop setzt first im stack nicht zurück.");
    printf("\n\n Test Level 2 abgeschlossen.\n\n");
#endif

#if test_level >2
    // Stack vorbereiten für folgende Tests
    {
    int i;
    for (i=0; i<6; i++)
    {
        printf("Tests fuer Stack_push ...\n Aufruf: Stack_push(stack, inhalte[%d]);\n\n", i, i);
        Stack_push(stack, inhalte[i]);
    }
    printf("\nTests fuer Stack_first ...\n Aufruf: %s\n\n","first = Stack_first(stack)");
    first = Stack_first(stack);
    test (first == stack->first, "Stack_first() funktioniert nicht richtig.");
    printf("\nTests fuer Stack_next ...\n Aufruf: %s\n\n","second = Stack_next(first);");
    second = Stack_next(first);
    //test (Stack_next(Stack_first(stack)) == NULL, "Stack_next() funktioniert nicht richtig.");
    test (second == first->next, "Stack_next() funktioniert nicht richtig.");
    printf("\nTests fuer Stack_swap ...\n Aufruf: %s\n\n","Stack_swap(first, second);");
    second = first->next;
    Stack_swap(first , second);
    test (strcmp(first->data, inhalte[4]) == 0, "Daten werden von Swap nicht korrekt vertauscht.");
    test (strcmp(second->data, inhalte[5]) == 0, "Daten werden von Swap nicht korrekt vertauscht.");
    printf("\n\n Test Level 3 abgeschlossen.\n\n");
    }
#endif

#if test_level >0
    printf("\n\nCleanup tests \n");
    printf("\nTest fuer Stack_print ...\n Aufruf: %s\n","Stack_print(stack);");
    Stack_print(stack);
    printf("\nTest fuer Stack_delete ...\n Aufruf: %s\n","Stack_delete(stack);");
    Stack_delete(stack);
    printf("\n\n Cleanup tests abgeschlossen.\n\n");
#endif

    return 0;
}
