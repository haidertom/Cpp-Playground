#ifndef KESSEL_H
#define KESSEL_H

class Kessel
{
    //------Elemente------
private:
    double KesselTemperatur;
    double KesselInhalt;
    int XKoord;
    int YKoord;
    char* Name;


    //------Methoden------
public:

    Kessel(char * Name, int X, int y, double Inhalt = 0, double Temperatur = 0);        //Konstruktor
    ~Kessel();                                                                          //Destruktor

    void Fuellen(double Temperatur, double Volumen);

    void Show();

    void Waermezufuhr(double Waermemenge);
};


#endif // KESSEL_H_
