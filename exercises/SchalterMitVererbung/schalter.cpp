#include <iostream>
#include "WinAdapt.h"
#include "schalter.h"
#include "textbox.h"
#include "FarbRect.h"

Schalter::Schalter()  : FarbRect (0, 0, 0, 0, 255, 255, 255)                          // Werte mit Null initialisieren, falls keine Parameter vorhanden sind
{
    FarbRect::SetX(0);
    FarbRect::SetY(0);

    Zustand = 9;
    TxEin = NULL;
    TxAus = NULL;
    TxZust = NULL;
}

Schalter::Schalter(char*Ein, char*Aus, int X, int Y) : FarbRect (X, Y, 90, 30, 200, 200, 200)   // Werte mit Parametern initialiserien
{
    FarbRect::SetX(X);
    FarbRect::SetY(Y);

    TxEin = new TextBox(Ein, X+3, Y+3, 22, 22);
    TxAus = new TextBox(Aus, X+30+3, Y+3, 22, 22);

    Zustand = 9;
    TxZust = new TextBox("0", X+60+3,Y+3, 22, 22);
}

Schalter::Schalter(const Schalter & s): FarbRect ( s.GetX (), s.GetY (),
                                                    s.GetW (), s.GetH (),
                                                    s.GetFarbeR (), s.GetFarbeG (),
                                                    s.GetFarbeB ())// Copy-Konstruktor
{
   // X=s.X;                                      //Tiefe Kopie
   // Y=s.Y;
    Zustand = s.Zustand;

    TxEin = new TextBox (*s.TxEin);
    TxAus = new TextBox (*s.TxAus);             //Warum dereferenzieren?
    TxZust = new TextBox (*s.TxZust);
}

Schalter::~Schalter()                           // Destruktio gibt Speicher wieder frei
{
    delete (TxEin);
    delete (TxAus);
    delete (TxZust);
}

void Schalter::Set(const Schalter&s)            // Schalter mit den Werten des Copy-Konstruktors beschreiben
{
    if(TxEin)
        delete (TxEin);
    if(TxAus)
        delete (TxAus);
    if(TxZust)
        delete (TxZust);

    //X=s.X;
    //Y=s.Y;

    FarbRect::SetX(s.GetX());
    FarbRect::SetY(s.GetY());
    SetW(s.GetW ());
    SetH(s.GetH ());
    SetFarbe(s.GetFarbeR (), s.GetFarbeG (), s.GetFarbeB ());

    Zustand = s.Zustand;

    TxEin = new TextBox (*s.TxEin);
    TxAus = new TextBox (*s.TxAus);
    TxZust = new TextBox (*s.TxZust);
}

void Schalter::Show()                        // Einzelfelder des Schalters ausgeben
{
    FarbRect::Show();
    TxEin->Show();
    TxAus->Show();

    if(Zustand==9)                             //Zustand am Anfang -> grau
    {
       TxZust->SetFarbe(180,180,180);
       TxZust->SetText("");                     //Text(0/1) für Zustand entfernen
    }

    if(Zustand==1)                              //Schalter ein -> grün
    {
       TxZust->SetFarbe(0,255,0);
       TxZust->SetText("");
    }
    if(Zustand==0)                              // Schalter aus ->rot
    {
       TxZust->SetFarbe(255,0,0);
       TxZust->SetText("");
    }
    TxZust->Show();
}

void Schalter::Mouse(int nX, int nY)        // Steuerung mit der Maus
{
    if(TxEin->Contains(nX, nY)==1)
        SetZust(1);
    else if(TxAus->Contains(nX, nY)==1)
        SetZust(0);
}
