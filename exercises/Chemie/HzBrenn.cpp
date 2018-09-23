#include <iostream>
#include <cstdio>

#include "WinAdapt.h"
#include "Kessel.h"
#include "HzBrenn.h"

#define TEXTOFFSET_X 2
#define TEXTOFFSET_Y 160
#define FELDOFFSET 155

using namespace std;

HzBrenner::HzBrenner(const char *Name, int X, int Y, Kessel*Kess)
{
    HzBrenner::Name = new ( char[ strlen( Name )+1 ] );         // warum so??
    strcpy(HzBrenner::Name, Name);
    XKoord = X;
    YKoord = Y;
    HzBrenner::Kess = Kess;                                     // mit :: wenn Attribut und Übergabeparameter gleichen Namen haben!
    LiterVerbraucht = 0;
}

void HzBrenner::Spritzufuhr(double Menge)
{
    LiterVerbraucht = LiterVerbraucht + Menge;
    Kess->Waermezufuhr(10200*Menge);                            // über Pointer ein Element der Klasse Kessel verändern

//    if(Kess->KesselInhalt <= 0)                               //zustäzlich falls Menge von Kessel abgezogen wird
//    {
//        Kess->KesselTemperatur = 0;
//        Kess->KesselInhalt = 0;
//    }
//    else
//        Kess->KesselInhalt = Kess->KesselInhalt - Menge;
}

void HzBrenner::Show()
{
    Rect(XKoord, YKoord+FELDOFFSET, XKoord + 150, YKoord + 100+FELDOFFSET);

    Text ( XKoord+TEXTOFFSET_X ,YKoord + TEXTOFFSET_Y , Name);

    char TextBuffer [128];
    sprintf(TextBuffer, "%0.2f Liter Verbraucht", LiterVerbraucht);
    Text(XKoord +TEXTOFFSET_X, YKoord + 50+ TEXTOFFSET_Y, TextBuffer );
}

int HzBrenner::Contains(int X, int Y)
{
    if (XKoord<= X && (XKoord+BREITE)>=X && (YKoord+FELDOFFSET)<= Y && (YKoord+FELDOFFSET+HOEHE)>=Y)
        return 1;
    return 0;
}
