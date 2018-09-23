#include <iostream>
#include <cstdio>
#include <cmath>
#include "WinAdapt.h"
#include "pipeline.h"
#include "Kessel.h"

#define RADIUS 30


Pipeline::Pipeline(Kessel*Quelle, Kessel*Ziel)
{
    Pipeline::Quelle = Quelle;
    Pipeline::Ziel = Ziel;
}
void Pipeline::Pumpen(double Menge)
{
    double EntnahmeTemperatur = 0, EntnahmeMenge = 0;
    Quelle ->Entnahme(Menge, &EntnahmeTemperatur, &EntnahmeMenge);
    Ziel ->Fuellen(EntnahmeTemperatur, EntnahmeMenge);
}
void Pipeline::Show()
{
    //------Linie------
    int Xquelle = Quelle->XKoord+BREITE/2;
    int Yquelle = Quelle->YKoord+HOEHE/2;
    int Xziel = Ziel->XKoord+BREITE/2;
    int Yziel = Ziel->YKoord+HOEHE/2;

    Line(Xquelle, Yquelle, Xziel, Yziel);

    //------Kreis------
   int mX = (Xquelle+Xziel)/2;
   int mY = (Yquelle+Yziel)/2;

   int LX1 = mX-RADIUS;
   int LY1 = mY+RADIUS;
   int LX2 = mX+RADIUS;
   int LY2 = mY-RADIUS;

   Elli(LX1, LY1, LX2, LY2);
}
int Pipeline::Contains (int X, int Y)
{
    int Xquelle = Quelle->XKoord+BREITE/2;
    int Yquelle = Quelle->YKoord+HOEHE/2;
    int Xziel = Ziel->XKoord+BREITE/2;
    int Yziel = Ziel->YKoord+HOEHE/2;

    int mX = (Xquelle+Xziel)/2;
    int mY = (Yquelle+Yziel)/2;


    if(((X-mX)*(X-mX))+((Y-mY)*(Y-mY))<(RADIUS*RADIUS))
        return 1;
    else
        return 0;
}
