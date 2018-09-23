//
//  class.cpp
//  class_wunderschoen
//
//  Created by Tom Haider on 11.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include "header.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;

Einzeldatum::Einzeldatum()
{
    next = 0;
}

Einzeldatum::Einzeldatum(int jahr, int tag, string monat, string ereignis)
{
//    try
//    {
    Jahr = jahr;
    Tag = tag;
    Monat = monat;
    Ereignis = ereignis;
    next = 0;
    prev = 0;
    
        
//        if(Jahr<1900)
//            throw jahr;
//    }
//    catch(int cjahr)
//    {
//        cout<<"Das kannn doch gar nicht sein"<<endl;
//        cout<<2016-cjahr<<" Jahre, so Alt ist doch kein Mensch!!"<<endl;
//        
//        throw Error(ereignis);
//    }
}



void Einzeldatum::neuesDatum(Einzeldatum * newData)
{
    //first ist aktuelles Objekt
    
    if(next == 0)
    {
        next = newData;
        next->prev = this;
    }
    else
    {
        next->neuesDatum(newData);
    }
    

}

void Einzeldatum::AllesAusgeben()
{
    Ausgeben();
    
    if(next != 0)
    {
        next->AllesAusgeben();
    }
}

void Einzeldatum::Ausgeben()
{
    cout<<setw(20)<< Ereignis;
    cout<<setw(3)<<"|";
    cout<<setw(10)<< Tag;
    cout<<setw(3)<<"|";
    cout<<setw(10)<< Monat;
    cout<<setw(3)<<"|";
    cout<<setw(10)<< Jahr;
    
    cout<<setw(3)<<"|prev";
    cout<<setw(13)<< prev;
    cout<<setw(3)<<"|this";
    cout<<setw(13)<< this;
    cout<<setw(3)<<"|next";
    cout<<setw(13)<< next<<endl;
    
}

//schwierig!!!!!!

Einzeldatum::Einzeldatum(const Einzeldatum & K)
{
    Jahr = K.Jahr;
    Tag = K.Tag;
    Monat = K.Monat;
    Ereignis = K.Ereignis;
    
    if(K.next != 0 )
    {
        next = new Einzeldatum(*(K.next));
    }
    else
    {
        next = 0;
    }
}

//------------------------------------------------------------------

Kalender::Kalender(string n, ifstream & Eingabe)
{
    name = n;
    pFirst = 0;
    
    int jahr;
    int tag;
    string monat;
    string ereignis;
    
    while(1)
    {
        Eingabe >> ereignis >> tag >> monat >> jahr;
        neuesEinzeldatum(jahr, tag, monat, ereignis);
        if(Eingabe.eof())
            break;
    }
}

void Kalender::neuesEinzeldatum(int jahr, int tag, string monat, string ereignis)
{
    Einzeldatum * pTemp = new Einzeldatum(jahr, tag, monat, ereignis);
    
    if (pFirst == 0)
    {
        pFirst = pTemp;
    }
    else
    {
        pFirst->neuesDatum(pTemp);
    }
}

void Kalender::ersteAdresse()
{
    cout<<endl<<"ErsteAdresse: "<<pFirst<<endl;
}

void Kalender::AllesAusgeben()
{
    cout<<name<<endl;
    cout<<setiosflags(ios::left);
    for(int i = 0; i<60; i++)
    {
        cout<<"-";
    }
    
    cout<<endl<<setw(23)<<"Ereignis"<<setw(13)<<"Tag"<<setw(13)<<"Monat"<<setw(13)<<"Jahr"<<endl;
    
    for(int i = 0; i<60; i++)
    {
        cout<<"-";
    }
    
    cout<<endl;
    
    if(pFirst != 0)
        pFirst->AllesAusgeben();

    else
        cout<<"Fehler";
    
    for(int i = 0; i<60; i++)
    {
        cout<<"-";
    }
    cout<<endl<<endl;
}

Kalender::Kalender(const Kalender & K)
{
    name = "Kopie mit CopyKonstruktor von " + K.name;
    
    pFirst = new Einzeldatum(*(K.pFirst));
}

void Kalender::operator += (const Kalender & K)
{
    name = "Kopie mit Operator von " + K.name;
    
    pFirst = new Einzeldatum(*(K.pFirst));
}


//------------------------------------------------------------------


Error::Error(string fehler)
{
    Fehler = fehler;
}

void Error::FehlerAusgabe()
{
    cout<<Fehler <<" ist fehlerhaft"<<endl;
}


