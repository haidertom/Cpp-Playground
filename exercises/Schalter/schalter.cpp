#include <iostream>
#include "WinAdapt.h"
#include "schalter.h"
#include "textbox.h"

Schalter::Schalter()                            // Werte mit Null initialisieren, falls keine Parameter vorhanden sind
{
    X = 0;
    Y = 0;
    Zustand = 0;
    TxEin = NULL;
    TxAus = NULL;
    TxZust = NULL;
}

Schalter::Schalter(char*Ein, char*Aus, int X, int Y)    // Werte mit Parametern initialiserien
{
    TxEin = new TextBox(Ein, X, Y, 30, 30);
    TxAus = new TextBox(Aus, X+30, Y, 30, 30);

    Zustand = 0;
    TxZust = new TextBox("0", X+60,Y, 30, 30);
}

Schalter::Schalter(const Schalter&s)            // Copy-Konstruktor
{
    X=s.X;                                      //Tiefe Kopie
    Y=s.Y;
    Zustand = s.Zustand;

    TxEin = new TextBox (*s.TxEin);
    TxAus = new TextBox (*s.TxAus);             //Warum dereferenzieren?
    TxZust = new TextBox (*s.TxZust);
}

Schalter::~Schalter()                           // Destruktio gibt Speicher wieder frei
{
    delete TxEin;
    delete TxAus;
    delete TxZust;
}

void Schalter::Set(const Schalter&s)            // Schalter mit den Werten des Copy-Konstruktors beschreiben
{
    delete TxEin;
    delete TxAus;
    delete TxZust;

    X=s.X;
    Y=s.Y;
    Zustand = s.Zustand;

    TxEin = new TextBox (*s.TxEin);
    TxAus = new TextBox (*s.TxAus);
    TxZust = new TextBox (*s.TxZust);
}

void Schalter::Show()                        // Einzelfelder des Schalters ausgeben
{
    TxEin->Show();
    TxAus->Show();
    TxZust->Show();
}

void Schalter::Mouse(int nX, int nY)        // Steuerung mit der Maus
{
    if(TxEin->Contains(nX, nY)==1)
        SetZust(1);
    else if(TxAus->Contains(nX, nY)==1)
        SetZust(0);
}
