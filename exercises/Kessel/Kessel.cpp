#include <iostream>
#include <cstdio>
#include "WinAdapt.h"
#include "Kessel.h"

#define BREITE 150
#define HOEHE 150

using namespace std;

Kessel::Kessel(char * Name, int X, int Y, double Inhalt, double Temperatur)
{
    Kessel::Name = new char[ strlen( Name )+1 ] ;
    strcpy(Kessel::Name, Name);
    XKoord = X;
    YKoord = Y;
    KesselInhalt = Inhalt;
    KesselTemperatur = Temperatur;
}

Kessel::~Kessel()
{
    delete[] Name;      //Speicher Freigeben für Pointer
}

void Kessel::Fuellen(double Temperatur, double Volumen)
{
    KesselTemperatur = ((KesselInhalt*KesselTemperatur)+(Volumen*Temperatur))/(KesselInhalt+Volumen);
    KesselInhalt = KesselInhalt + Volumen;
}

void Kessel::Show()
{
    Rect(XKoord, YKoord, XKoord + BREITE, YKoord + HOEHE);
    Text(XKoord + 10, YKoord + 10, Name );

    char TextBuffer [128];
    sprintf(TextBuffer, "%f Liter", KesselInhalt);
    Text(XKoord + 10, YKoord + 50, TextBuffer );

    sprintf(TextBuffer, "%f Grad", KesselTemperatur);
    Text(XKoord + 10, YKoord + 90, TextBuffer );
}
