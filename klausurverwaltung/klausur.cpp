//
//  klausur.cpp
//  klausurverwaltung
//
//  Created by Tom Haider on 24.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "klausur.hpp"

Klausur::Klausur(string t)
{
    Titel = t;
    myroot = NULL;
}

Klausur::~Klausur()
{
    delete myroot;
}

Klausur::Klausur(const Klausur &s)
{
    Titel = s.Titel;
    
    if(s.myroot)
    {
        myroot = new Einzelergebnis(*s.myroot);
    }
    
    else
        myroot = 0;
}


void Klausur::add(string Teilnehmername, int Punkte, int Note)
{
    //neues Objekt anlegen
    
    Einzelergebnis * pTemp = new Einzelergebnis (Teilnehmername, Punkte, Note);
    
    //Prüfe Anfang
    if(myroot == 0)             //prüfe ob myroot bereits auf ein Objekt zeigt, wenn nicht, gerade erstelltes Objekt = 1.Objekt
    {
        myroot = pTemp;
        
    }
    //Element einfügen          //myroot zeigt bereits auf ein objekt, neues Objekt muss am Ende eingefügt werden
    else
    {
        myroot->anfuegenElement(pTemp);
            //Übergabe des ersten Elements der Liste
    }
}


void Klausur::einlesen(std::ifstream & eingabe)
{
//     für if stream objekt
    string name;
    int punkte;
    int note;
    while(1)
    {
        eingabe>> name >> punkte >> note;
        add(name, punkte, note);
        if(eingabe.eof())
        {
            break;
        }
    }
}


void Klausur::ausgeben(ostream & out) const
{
    cout<<"Sortierte Klausurergebnisse der Prüfung "<<Titel<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    
    Einzelergebnis * pLauf = myroot;
    if(pLauf)
        pLauf->allesAusgeben(out);
    cout<<"---------------------------------------------------------------"<<endl;
}


void Klausur::sortieren()
{
    int counter = 0;
    if(myroot)
    {
        Einzelergebnis * pTemp = myroot->sortieren(counter);
        if( pTemp != 0)
        {
            myroot = pTemp;
        }
    }
    
    if (counter == 0) return;
    else sortieren();
}

void Klausur::operator<<(ostream & out)
{
   Titel =  "\nOperator Kopie " + Titel;
    cout<<endl<<"operator start"<<endl;
    
    ausgeben(out);
    
}
