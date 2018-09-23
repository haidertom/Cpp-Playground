#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"
#include "textbox.h"
#include "schalter.h"
#include "FarbRect.h"

using namespace std;

//TextBox t(" Test " ,400 ,400 ,60 ,30);

//Schalter s("On","Off" ,100 ,100);

FarbRect F(100, 100, 100, 100, 10, 200, 100);

Schalter s("On", "Off", 50, 50);
Schalter aSchalter [10];

Schalter KopieVersetzt (Schalter s, int nDx, int nDy)       // globale Funktion; Funktionswerte von Copykonstruktoren aufzeigen
{
    s.SetX(nDx);                                            // Position des Schalters s verändern
    s.SetY(nDy);
    return s;                                               // Schalter zurückgeben
}

void VtlZyk(void)
{

}

void VtlMouse(int X, int Y)
{
    for(int i=0; i<10; i++)
    {
        aSchalter[i].Mouse(X,Y);                //Funktion Mouse für Jeden Schalter des Arrays aufrufen
    }
}

void VtlKeyHit(int key)
{

}

void VtlInit(void)
{
    for(int i=0; i <10; i++)
    {
    aSchalter[i].Set(KopieVersetzt(s, 0, i*50));        // Schalter des Arrays erzeugen
    }
}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    // 2. Test Show () / Konstruktor
    //t.Show ();

    // 3. Test Copykonstruktor
    //TextBox tt(t);
    //tt. Show ();


    // 2. Test Show () / Konstruktor
    //s. Show ();

    // 3. Test Copykonstruktor
    // Schalter s2(s);
    // s2. Show ();

    // 4. Test Defaultkonstruktor / Set ()
//    Schalter s3;
//    s3.Set (s);
//    s3.Show ();

  for (int i=0; i<10; i++)                            // Schalter des Arrays zeichnen
    {
      aSchalter[i].Show();
    }

    F.Show();
}

