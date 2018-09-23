//
//  einzelergebnis.cpp
//  klausurverwaltung
//
//  Created by Tom Haider on 24.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#include "einzelergebnis.hpp"

Einzelergebnis::Einzelergebnis()
{
    Name = "0";
    Note = 0;
    Punkte = 0;
    next = NULL;
}

Einzelergebnis::Einzelergebnis(const Einzelergebnis & s)
{
    Name = s.Name;
    Note = s.Note;
    Punkte = s.Punkte;
    
    if(s.next)
    {
        next = new Einzelergebnis(*(s.next));
    }
    else
    {
        next = 0;
    }
}


Einzelergebnis::Einzelergebnis(string Name, int Punkte, int Note, Einzelergebnis * next)
{
    Einzelergebnis::Name = Name;
    Einzelergebnis::Punkte = Punkte;
    Einzelergebnis::Note = Note;
    Einzelergebnis::next = NULL;
}


void Einzelergebnis::anfuegenElement(Einzelergebnis * ElementNeu)       // erstes Element der Liste wird übergeben
{                                                                       // Objekte werden so lange durchgegangen, bis next=NULL
    if(next == NULL)                                                 // an dieser Stelle wird next als Attribut gespeichert
        next = ElementNeu;
    else
        next->anfuegenElement(ElementNeu);
}



void Einzelergebnis::ausgeben(ostream & out) const //void Einzelergebnis::ausgeben(ostream & out) const
{
    //Konsolenausgabe
    cout<<" Name: "   <<setw(25)<<Name;
    cout<<"; Punkte:" <<setw(5)<<Punkte;
    cout<<"; Note: "  <<setw(3)<<Note<<endl;
    //cout.setf(ios::fixed); cout.precision(1); cout<<setw(3)<<Note<<endl;

//    //Dateiausgabe
//    out<<" Name: "   <<setw(25)<<Name;
//    out<<"; Punkte:" <<setw(5)<<Punkte;
//    out<<"; Note: "  <<setw(3)<<Note<<endl;
//    //cout.setf(ios::fixed); cout.precision(1); cout<<setw(3)<<Note<<endl;
}


void Einzelergebnis::allesAusgeben(ostream & out, int lfdNummer) const
{
    cout<<"Nr."<<setw(3)<<lfdNummer;
    ausgeben(out);
    if(next)
    {
        lfdNummer++;
        next->allesAusgeben(out, lfdNummer);
    }
}

Einzelergebnis* Einzelergebnis::sortieren(int & counter)
{
    
    Einzelergebnis * pZwischen;
    
    if(!next)
    {
        return 0;
    }
    pZwischen = next ->sortieren(counter);
    if(pZwischen)
    {
        next = pZwischen;
    }
    if (Name < next->Name)
    {
        return 0;
    }
    else                            //Bildlich: Objekt0->Objekt1->Objekt2->Objekt3
    {                               //vertausche Objekt1 mit Objekt 2
        
        counter ++;                 //counter inkrementieren
        pZwischen = next;           //Zeiger auf Objekt 2 speichern
        next = next->next;          //Objekt1->next auf Objekt 3 zeigen lassen
        pZwischen ->next = this;    //nun Objekt 2 auf Objekt 1 zeigen lassen
        
        return pZwischen;           //Objekt 2 zurückgeben = neuer Nachbar
    }
}
