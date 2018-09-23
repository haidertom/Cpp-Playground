
#include <iostream>
#include <cstring>
#include "Header.h"

using namespace std;

//----------------outline Test------------------
Test::Test()
{
    cout<<"Konstruktor fuer Test."<<endl;
}
Test::~Test()
{
    cout<<"Destruktor fuer Test."<<endl;
}

//-----------------global----------------------
void funktion1()
{
    try
    {
        Test t;
        cout<<"Start funktion 1. Excepton 'Error' folgt"<<endl;
        
        cout<<endl<<"Geben sie eine Zahl zwischen [0 und 10] ein"<<endl;
        cin>>t.zahl;
        
        if (t.zahl>10)
        {
            throw Error("Falsche Eingabe");        //Ojekt der klasse Error wird mittels throw bei Exceptions im Progrmam übegeben
        }
    }
    catch(Error e)
    {
        cout<<"Start catch-Block in funktion1."<<endl;
        cout<<"Fehler in funktion1."<<endl;
        string fu = "FIUUUU";
        throw fu;
      
        //lokale Fehlerbehandlung: Fehler wird auf Funktionsebene behandelt und dann an übergeordnete Fehlerüberwachung weitergereicht
    }
}


//-----------------main----------------------
int main()
{
    cout<<"Programmstart."<<endl;
    try
    {
        cout<<"Start try-Block, 'funktion1' wird aufgerufen."<<endl;
        funktion1();                        //durch den Aufruf der Funktion wird ein Fehler erzeugt, dieser wird erst auf Funktionseben behandelt und dann an den nachfolgenden try-Block in main abgegebn
    }
    catch (Error e)                         //
    {
        cout<<"Start catch-Block fuer 'Error'-Objekte."<< endl;
        cout<<e.showMsg()<<endl;
    }
    catch(string str)
    {
        cout<<"Start catch-Block für Zeichenkette: "<<str<<endl;
    }
    cout<<"Wieder in 'main'. Programm wird beendet"<<endl;
    
    return 0;
}