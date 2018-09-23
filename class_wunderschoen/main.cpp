//
//  main.cpp
//  class_wunderschoen
//
//  Created by Tom Haider on 11.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <fstream>

#include "header.h"

using namespace std;

int main()
{
    
    ifstream Eingabe("eingabe.txt");
    
    if(!Eingabe.is_open())
    {
        cout<<"Fehler beim Lesen der Datei";
        return 1;
    }
    
   
    Kalender *Toms = new Kalender("Toms Kalender", Eingabe);
    
    Toms->AllesAusgeben();
    
//    try
//    {
//    Toms->neuesEinzeldatum(1995, 23, "April" ,"Toms Geburstag");
//    Toms->neuesEinzeldatum(1994, 2, "Juni", "Martins Geburstag");
//    Toms->neuesEinzeldatum(1993, 6, "Februar", "Annas Geburstag");
//    Toms->neuesEinzeldatum(2000, 6, "Januar", "Hannas Geburstag");
//    Toms->neuesEinzeldatum(1060, 22, "August", "Michaels Geburstag");
//    }
//    
//    catch (Error e)
//    {
//        e.FehlerAusgabe();
//        cout<<"und wurde gestrichen!! \nMindestens Ein Geburstag Fehlerhaft"<<endl;
//        //return 1;
//    }
//    Toms->ersteAdresse();
//    Toms->AllesAusgeben();
//    
//    
//    Kalender * Kopie = new Kalender(*Toms);
//    
//    Kopie->ersteAdresse();
//    Kopie->AllesAusgeben();
//    
//    Kalender * Okopie = new Kalender("WirdKopiert");
//    
//    *Okopie += *Toms;
//    
//    Okopie->AllesAusgeben();
//    
//    return 0;
//    
    
}


