//
//  main.cpp
//  VerketteListeNEU
//
//  Created by Tom Haider on 22.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct messpunkt
{
    int x;
    int y;
    char array[20];
    
    double s;
    struct messpunkt* next;
    struct messpunkt* act;
    struct messpunkt* prev;
};

class verketteteListe
{
public:
    struct messpunkt * Anfang;
    
    verketteteListe()
    {
        Anfang = 0;
    }
    verketteteListe(const verketteteListe &quelle)          //Copy Konstruktor erzeugt tiefe Kopie vom Quellobjekt
    {
        cout<<"Konstruktor startet hier"<<endl;
        
        Anfang = 0;                                         //Anfang für Objekt (Liste 3) Null setzen
        messpunkt * Laufzeiger = quelle.Anfang;             //Laufzeiger auf den ersten Wert des Quellobjektes
        
        while (Laufzeiger)                                  //Attribute des Quellobjektes an Fkt. AmEndeEinfuegen uebergeben
        {                                                   //dadurch wird jedes Objekt kopiert
            AmEndeEinfuegen(Laufzeiger->x, Laufzeiger->y, Laufzeiger->s);
            Laufzeiger = Laufzeiger->next;                  // Laufzeiger auf nächstes Objekt zeigen lassen
        }
    }
    
    //Operator soll tiefe Kopie der Liste erzeugen
    verketteteListe operator +=(const verketteteListe r) //Operator mit Rückgabewert 'verketteteListe' und Token '='
    {
        // zunächst alle Einträge in der Liste löschen!
        messpunkt * Laufzeiger = Anfang;
        while (Laufzeiger)
        {
            messpunkt * Laufzeiger_alt = 0;
            Laufzeiger_alt = Laufzeiger;
            Laufzeiger = Laufzeiger_alt->next;
            delete Laufzeiger_alt;
        }
        Anfang = 0;
        //  jetzt tiefe Kopie erzeugen
        Laufzeiger = r.Anfang;
        while (Laufzeiger)
        {
            AmEndeEinfuegen(Laufzeiger->x, Laufzeiger->y, Laufzeiger->s);
            Laufzeiger = Laufzeiger->next;
        }
        return *this;
    }
    ~verketteteListe();
    
    void AmEndeEinfuegen(int x_neu, int y_neu, double s_neu);
    void AmEndeEinfuegen(int x, const char *a, double s); //überladen für array
    void listeAusgeben();
    void listeAusgeben(int i);
    void listeAusgeben(char c);
};

void verketteteListe::AmEndeEinfuegen(int x, int y, double s)
{
    if (Anfang == 0)
    {
        //Liste war bisher leer
        Anfang = new struct messpunkt; //(...) vor malloc ist ein Typecast der in cpp notwendi ist
        Anfang->prev=NULL;
        Anfang->act=Anfang;
        Anfang->x= x;
        Anfang->y= y;
        Anfang->s= s;
        Anfang->next=0;
        
    }
    else
    {
        // Liste war bisher nicht leer...
        // Ende der Liste suchen...
        struct messpunkt * Laufzeiger = Anfang;
        while(Laufzeiger->next != 0)
        {
            Laufzeiger = Laufzeiger->next;
        }
        Laufzeiger->next = (struct messpunkt *) malloc(sizeof(struct messpunkt));
        
        struct messpunkt * temp = Laufzeiger;           //Adresse von Laufzeigers ist hier noch die Adresse des vorheriges Elementes; Zwischenspeichern in temp
        
        Laufzeiger = Laufzeiger->next;             //laufzeiger jetzt auf nächstes Element zeigen lassen
        Laufzeiger->prev=temp;                     //die in temp gespeicherte Adresse nun ins aktuelle Objekt schreiben
        Laufzeiger->act= Laufzeiger;
        Laufzeiger->x= x;
        Laufzeiger->y= y;
        
        Laufzeiger->s= s;
        Laufzeiger->next=0;
    }
}

//überladen für char
void verketteteListe::AmEndeEinfuegen(int x, const char *a, double s)
{
    if (Anfang == 0)
    {
        //Liste war bisher leer
        Anfang = new struct messpunkt; //(...) vor malloc ist ein Typecast der in cpp notwendi ist
        Anfang->prev=NULL;
        Anfang->act=Anfang;
        Anfang->x= x;
        strcpy(Anfang->array, a);
        Anfang->s= s;
        Anfang->next=0;
        
    }
    else
    {
        // Liste war bisher nicht leer...
        // Ende der Liste suchen...
        struct messpunkt * Laufzeiger = Anfang;
        while(Laufzeiger->next != 0)
        {
            Laufzeiger = Laufzeiger->next;
        }
        Laufzeiger->next = (struct messpunkt *) malloc(sizeof(struct messpunkt));
        
        struct messpunkt * temp = Laufzeiger;           //Adresse von Laufzeigers ist hier noch die Adresse des vorheriges Elementes; Zwischenspeichern in temp
        
        Laufzeiger = Laufzeiger->next;             //laufzeiger jetzt auf nächstes Element zeigen lassen
        Laufzeiger->prev=temp;                     //die in temp gespeicherte Adresse nun ins aktuelle Objekt schreiben
        Laufzeiger->act= Laufzeiger;
        Laufzeiger->x= x;
        strcpy(Laufzeiger->array, a);
        Laufzeiger->s= s;
        Laufzeiger->next=0;
    }
}

void verketteteListe::listeAusgeben(int i)
{
    struct messpunkt* Hilfspointer = 0;
    Hilfspointer = Anfang;
    while (Hilfspointer != 0)
    {
        printf("Prev: %p act: %p x=%i, y=%i, Staerke=%lf, next: %p\n",
               Hilfspointer->prev, Hilfspointer->act, Hilfspointer->x, Hilfspointer->y, Hilfspointer->s, Hilfspointer->next
               );
        Hilfspointer = Hilfspointer->next;
    }
}



void verketteteListe::listeAusgeben()
{
    struct messpunkt* Hilfspointer = 0;
    Hilfspointer = Anfang;
    while (Hilfspointer != 0)
    {
        cout<<"Prev: "<<Hilfspointer->prev;
        cout<<" ACT: "<< Hilfspointer->act;
        cout<<"  x: "<<Hilfspointer->x;
        if(Hilfspointer->y)
            cout<<"  y: "<< Hilfspointer->y;
        if(Hilfspointer->array);
        cout<<"  text: "<<Hilfspointer->array;
        cout<<"  next: "<< Hilfspointer->next<<endl;
        
        
        Hilfspointer = Hilfspointer->next;
    }
}



verketteteListe::~verketteteListe()
{
    messpunkt * Laufzeiger = 0;
    Laufzeiger = Anfang;
    while (Laufzeiger)
    {
        messpunkt * Laufzeiger_alt = 0;
        Laufzeiger_alt = Laufzeiger;
        Laufzeiger = Laufzeiger_alt->next;
        delete Laufzeiger_alt;
    }
}

verketteteListe irgendeineFunktion(verketteteListe input) //global definierte Funktion
{
    //verketteteListe Ergebnis;                              // WO WIRD INPUT VERWENDET???
    
    input.AmEndeEinfuegen(42, 251, 3.14);
    
    return input;
}

int main()
{
       //------------dynamische Erzeugung-----------------
    verketteteListe * p_test = 0;
    p_test = new verketteteListe;
    
    printf("\n------------Test mit dynamischer Erzeugung------\n");
    p_test->AmEndeEinfuegen(42, 21, 3.14);
    p_test->AmEndeEinfuegen(42, 21, 24.42);
    p_test->AmEndeEinfuegen(42, 21, 123.456);
    p_test->listeAusgeben(1);
    printf("-----------------------------------------\n");
    
    
     //------------Normale Erzeugung-----------------
    verketteteListe MeineListe;
    printf("\n------------Test mit normaler Erzeugung-------------------\n");
    MeineListe.listeAusgeben(1);
    MeineListe.AmEndeEinfuegen(42, 21, 3.14);
    printf("-------------------------------\n");
    MeineListe.listeAusgeben(1);
    MeineListe.AmEndeEinfuegen(1, 3, 14.3);
    printf("-------------------------------\n");
    MeineListe.listeAusgeben(1);
    MeineListe.AmEndeEinfuegen(2, 2, 42.1);
    printf("-------------------------------\n");
    MeineListe.listeAusgeben(1);
    MeineListe.AmEndeEinfuegen(3, 1, 4.8);
    printf("-------------------------------\n");
    MeineListe.listeAusgeben(1);
    
    cout<<"----versuch----"<<endl;
    MeineListe.AmEndeEinfuegen(3, "Hans", 4.8);
    MeineListe.listeAusgeben();
    cout<<"----versuch----"<<endl;
    
    
     //------------Kopien von Meine Liste erzeugen-----------------
    printf("----------Tiefe Kopie von MeineListe---------------------\n");
    verketteteListe Liste2 = (MeineListe);
    Liste2.listeAusgeben(1);
    
    verketteteListe Liste3 = irgendeineFunktion(MeineListe); //neues Objekt erstellen und beim Erstellen das Ergebnis übergeben, dass irgendeineFunktion(MeineListe) liefert -> Copy Konstruktor wird verwendet
   
    printf("----------Tiefe Kopie von MeineListe mit Zusätzlichem Element---------------------\n");
    Liste3.listeAusgeben(1);
    printf("-------------------------------\n");
    
    verketteteListe Liste4;
    
    printf("----------Tiefe Kopie von MeineListe mit Operator---------------------\n");
    Liste4+=Liste3;
    Liste4.listeAusgeben(1);
    return 0;
}
