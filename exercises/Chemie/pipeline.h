#ifndef PIPELINE_H
#define PIPELINE_H
#include "Kessel.h"

class Pipeline
{
public:
    //------Attribute------
    Kessel * Quelle;
    Kessel * Ziel;

    //------Methoden------
    Pipeline(Kessel*Quelle, Kessel*Ziel);
    void Pumpen(double Menge);
    void Show();
    int Contains(int X, int Y);
};
#endif // PIPELINE_H
