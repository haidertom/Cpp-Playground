//
//  bruch.cpp
//  Bruch
//
//  Created by Tom Haider on 05.05.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include "bruch.h"
#include <iostream>
#include "math.h"

using namespace std;

void Bruch::Set(int zaehler, int nenner)
{
    Zaehler = zaehler;
    Nenner = nenner;
}

void Bruch::Set(double zaehler, double nenner)
{
    int runderzaehler = (int)floor(zaehler+0.5);            //Funktion um double zahlen richtig zu runden--> dann in int
    int rundernenner = (int)floor(nenner+0.5);              // umwandeln
    Set(runderzaehler, rundernenner);
}

void Bruch::Set(const Bruch &bruch)
{
    Set(bruch.Zaehler, bruch.Nenner);                       //CopyConstructor erzeugt Kopie von Bruch mit dem Namen "bruch" und
}                                                           //den Elementen Zaehler und Nenner

void Bruch::Print()
{
    cout<<endl<<"("<<Zaehler<<"/"<<Nenner<<")"<<endl; //Ausgabe in Bruch-Schreibweise
}

void Bruch::Print(int nachkommastellen)
{
    cout<<(Zaehler/Nenner)<<".";                            //Berechnung des ganzzahligen Anteils
    
    int R= 0;
    
    R = (Zaehler%Nenner);                                   //Berechnung des Reste R
    
    int i;
    for(i=1; i<=nachkommastellen; i++)
    {
        cout<<((10*R)/Nenner);                              //Ausgabe und Berechnung der nächsten Dezimalstelle
        R = (10*R)%Nenner;                                  //Berchnung des Rest R für nächsten Durchlauf
    }
}

Bruch Bruch::Add(const Bruch &bruch)
{
    Bruch Addition;
    
    Addition.Zaehler = (Zaehler*bruch.Nenner)+(Nenner*bruch.Zaehler);   //jew. Zaehler mit Nenner des anderen Bruchs erweitern
    Addition.Nenner = Nenner*bruch.Nenner;                              //Nenner mulitplizieren
    
    return Addition;
}

Bruch Bruch::Mul(const Bruch &bruch)
{
    Bruch Multiplikation;
    Multiplikation.Zaehler = Zaehler * bruch.Zaehler;                  //Nenner und Zaehler jew. mulitiplizieren
    Multiplikation.Nenner = Nenner * bruch.Nenner;
    return Multiplikation;
}

int Bruch::Equal(const Bruch & bruch)
{
    if ((Zaehler*bruch.Nenner) == (Nenner*bruch.Zaehler))              //Zaehler auf gem. Nenner bringen und vergleichen
    {
        return 1;                                                      //gleich
    }

    return 0;                                                          //ungleich
}











