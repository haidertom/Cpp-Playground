#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"
#include "Kessel.h"
#include "HzBrenn.h"

using namespace std;

Kessel k1(" Kessel1 ", 10, 10, 10, 30);
Kessel k2(" Kessel2 ", 200, 10, 10, 70);
Kessel k3(" Kessel3 ", 400, 10, 10, 70);

HzBrenner b1(" Brenner 1", 10, 10 , &k1 );
HzBrenner b2(" Brenner 2", 200, 10 , &k2 );
HzBrenner b3(" Brenner 3", 400, 10 , &k3 );

int LiterGewuenscht, TemperaturGewuenscht;

void VtlZyk(void)
{

}

void VtlMouse(int X, int Y)
{
    if (10<= X && 110>=X && 165<= Y && 265>=Y)
        b1.Spritzufuhr(0.01);
    else if (200<= X && 300>=X && 165<= Y && 265>=Y)
        b2.Spritzufuhr(0.01);
    else if (400<= X && 500>=X && 165<= Y && 265>=Y)
        b3.Spritzufuhr(0.01);
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

else if(key == 'x')
    k1.Waermezufuhr(1000);

else if(key == 'y')
    k2.Waermezufuhr(1000);

else if(key == 'z')
    k3.Waermezufuhr(1000);


else if(key == '\001')
    b1.Spritzufuhr(0.01);
else if(key == '\002')
    b2.Spritzufuhr(0.01);
else if(key == '\003')
    b3.Spritzufuhr(0.01);
}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
    k1.Show();                                  //grafische Darstellung der Kessel
    k2.Show();
    k3.Show();

    b1.Show ();
    b2.Show ();
    b3.Show ();
}

