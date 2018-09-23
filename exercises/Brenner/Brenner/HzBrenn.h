#ifndef HZBRENN_H
#define HZBRENN_H


#include "kessel.h"


class HzBrenner
{
    private:
    //------Attribute------

        char *Name;
        int XKoord;
        int YKoord;
        Kessel * Kess;
        double LiterVerbraucht;

    public:
    //------Methoden------

        HzBrenner (const char*Name, int X, int Y, Kessel*Kess);
        void Spritzufuhr(double Menge);
        void Show();
};


#endif // HZBRENN_H
