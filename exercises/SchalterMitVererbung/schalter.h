#ifndef SCHALTER_H
#define SCHALTER_H
#include "WinAdapt.h"
#include "textbox.h"
#include "FarbRect.h"


class Schalter : public FarbRect
{
private:
    //------Attribute------
    int Zustand;
    TextBox *TxEin, *TxAus, *TxZust;     //Variablen mit dem Rückgabewerte TextBox, erzeugen jeweils neues Objekt der Klasse Textbox und zeigen darauf

public:
    //------Methoden------

    int GetZust()
    {
        return Zustand;
    }
    void SetX(int X)
    {
        FarbRect::SetX(X);              // Position des gesamten Schalters setzen

        TxEin->SetX(X+4);             // Position der Einzelfelder setzen
        TxAus->SetX(X+30+4);
        TxZust->SetX(X+60+4);
    }
    void SetY(int Y)
    {
        FarbRect::SetY(Y);

        TxEin->SetY(Y+4);
        TxAus->SetY(Y+4);
        TxZust->SetY(Y+4);
    }
    void SetZust(int Zust)          // Zustand des Schalters Bestimmen
    {
        Zustand = Zust;

        if (Zust == 1)
        {
        TxZust->SetText("1");
        }
        else if (Zust == 0)
        {
        TxZust->SetText("0");
        }
    }

    Schalter();
    Schalter(char *Ein, char *Aus, int X, int Y);
    Schalter(const Schalter&s);
    ~Schalter();

    void Set(const Schalter &s);

    void Show();

    void Mouse(int X, int Y);
};

#endif // SCHALTER_H
