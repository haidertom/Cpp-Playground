#ifndef SCHALTER_H
#define SCHALTER_H
#include "WinAdapt.h"
#include "textbox.h"

class Schalter
{
private:
    //------Attribute------
    int X, Y;
    int Zustand;
    TextBox *TxEin, *TxAus, *TxZust;     //Variablen mit dem Rückgabewerte TextBox, erzeugen jeweils neues Objekt der Klasse Textbox und zeigen darauf

public:
    //------Methoden------
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetZust()
    {
        return Zustand;
    }
    void SetX(int X)
    {
        Schalter::X=X;              // Position des gesamten Schalters setzen
        TxEin->SetX(X);             // Position der Einzelfelder setzen
        TxAus->SetX(X+30);
        TxZust->SetX(X+60);
    }
    void SetY(int Y)
    {
        Schalter::Y=Y;
        TxEin->SetY(Y);
        TxAus->SetY(Y);
        TxZust->SetY(Y);
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
