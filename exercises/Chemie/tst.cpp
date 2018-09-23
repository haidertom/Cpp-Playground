#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include "WinAdapt.h"
#include "Kessel.h"
#include "HzBrenn.h"
#include "pipeline.h"

using namespace std;

Kessel k1(" Kessel1 ", 10, 10, 10, 30);
Kessel k2(" Kessel2 ", 300, 300, 10, 70);
Kessel k3(" Kessel3 ", 600, 10, 10, 70);

HzBrenner b1(" Brenner 1", 10, 10 , &k1 );
HzBrenner b2(" Brenner 2", 300, 300 , &k2 );
HzBrenner b3(" Brenner 3", 600, 10 , &k3 );

Pipeline p12(&k1, &k2);
Pipeline p23(&k2, &k3);

int LiterGewuenscht, TemperaturGewuenscht;

void VtlZyk(void)
{

}

void VtlMouse(int X, int Y)
{
    if(b1.Contains(X, Y)==1)
        b1.Spritzufuhr(0.01);
    else if(b2.Contains(X, Y)==1)
        b2.Spritzufuhr(0.01);
    else if(b3.Contains(X, Y)==1)
        b3.Spritzufuhr(0.01);

    else if(p12.Contains(X, Y)==1)
        p12.Pumpen(1);
    else if(p23.Contains(X, Y)==1)
        p23.Pumpen(1);
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
    p12. Show ();
    p23. Show ();

    k1.Show();                                  //grafische Darstellung der Kessel
    k2.Show();
    k3.Show();

    b1.Show ();
    b2.Show ();
    b3.Show ();


}

