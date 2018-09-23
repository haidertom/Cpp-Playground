//
//  main.cpp
//  klausurverwaltung
//
//  Created by Tom Haider on 24.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#include "klausur.hpp"
#include "einzelergebnis.hpp"

int main()
{
    Klausur * MeinePruefung;
    MeinePruefung = new Klausur ("Info 2");
    
    //Eingabe
    ifstream Klausurdaten("klausur.txt");
    
        if (!Klausurdaten.is_open())
        {
        cout<<"can not open code file ";
        throw 42;
        }
    
    MeinePruefung->einlesen(Klausurdaten);
    
    
    //Ausgabe
    ofstream DieKlausur("klausur_sortiert.txt");
    
    if (!Klausurdaten.is_open())
    {
        cout<<"can not open code file ";
        throw 42;
    }
    
    MeinePruefung->sortieren();
    
    //Ohne Operator
    
    MeinePruefung->ausgeben(DieKlausur);
    
   // Mit Operator 
    
   *MeinePruefung << DieKlausur;

    


}
