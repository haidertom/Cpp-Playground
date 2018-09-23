#ifndef KESSEL_H
#define KESSEL_H

#define BREITE 150
#define HOEHE 150

class Kessel
{public:

    //------Elemente------

    double KesselTemperatur;
    double KesselInhalt;
    int XKoord;
    int YKoord;
    char* Name;


    //------Methoden------


    Kessel(char * Name, int X, int y, double Inhalt = 0, double Temperatur = 0);        //Konstruktor
    ~Kessel();                                                                          //Destruktor

    void Fuellen(double Temperatur, double Volumen);

    void Show();

    void Waermezufuhr(double Waermemenge);

    void Entnahme(double WunschMenge, double *EntnahmeTemperatur, double *EntnahmeMenge);
};


#endif // KESSEL_H_
