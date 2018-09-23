#ifndef HZBRENN_H
#define HZBRENN_H


#include "kessel.h"


class HzBrenner
{
    private:
    //------Attribute------

        char *Name;                                         //string nicht möglich??
        int XKoord;
        int YKoord;
        Kessel * Kess;
        double LiterVerbraucht;

    public:
    //------Methoden------

        HzBrenner (const char*Name, int X, int Y, Kessel*Kess);     //kein string!!
        void Spritzufuhr(double Menge);
        void Show();
        int Contains(int X, int Y);
};


#endif // HZBRENN_H
