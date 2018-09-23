//
//  header.h
//  class_wunderschoen
//
//  Created by Tom Haider on 11.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef header_h
#define header_h

#include <iostream>
#include <cstring>

using namespace std;

class Einzeldatum
{
private:
    int Jahr;
    int Tag;
    string Monat;
    
    string Ereignis;
    
    Einzeldatum * next;
    Einzeldatum * prev;
    Einzeldatum * actu;
    
public:
    Einzeldatum();
    Einzeldatum(int j, int t, string monat, string ereignis);//Konstruktor für das erste Element
    
   Einzeldatum(const Einzeldatum & E);
    
    void durckeDatum();
    void neuesDatum(Einzeldatum * newData);
    void Ausgeben();
    void AllesAusgeben();
};


class Kalender
{
private:
    string name;
    Einzeldatum * pFirst;
    
public:
    Kalender();
    Kalender(const Kalender & K);
    Kalender(string n, ifstream & Eingabe);
    
    void ersteAdresse();
    void neuesEinzeldatum(int jahr, int tag,string monat, string ereignis);
    void AllesAusgeben();
    
    void operator += (const Kalender & K);
};

#endif /* header_h */

class Error
{
private:
    int Jahr;
    string Fehler;
public:
    Error(string fehler);
    void FehlerAusgabe();
};
