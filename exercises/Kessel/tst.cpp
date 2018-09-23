#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"
#include "Kessel.h"

using namespace std;

Kessel k1(" Kessel1 ", 10, 10, 10, 30);
Kessel k2(" Kessel2 ", 10, 200, 10, 70);
Kessel k3(" Kessel3 ", 200, 10, 10, 70);

int LiterGewuenscht, TemperaturGewuenscht;

void VtlZyk(void)
{

}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{
if (48<key && key<58)                   // Ziffern
{
    LiterGewuenscht = 10 * (key-48);
}

else if (64<key && key<91)              //Großbuchstaben
{
    TemperaturGewuenscht = 5 * (key-64);
}

else if (96<key && key<100)             //Kleinbuchstaben a-c
{
    if (key == 97)
        k1.Fuellen(TemperaturGewuenscht, LiterGewuenscht);
    else if (key == 98)
        k2.Fuellen(TemperaturGewuenscht, LiterGewuenscht);
    else if (key == 99)
        k3.Fuellen(TemperaturGewuenscht, LiterGewuenscht);
}

}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    k1.Show();                                  //grafische Darstellung der Kessel
    k2.Show();
    k3.Show();
}

