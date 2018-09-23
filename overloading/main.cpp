//
//  main.cpp
//  overloading
//
//  Created by Tom Haider on 20.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Header.h"

using namespace std;

A::A(char *t)
{
    strcpy(text, t);
}

void A::zeigeinhalt()
{
    cout<<endl<<"Inhalt von A: "<<text<<endl;
}

void A::operator +=(char *t)
{
    strcat(text, t);
}

B::B(int x, int y)
{
    _x = x;
    _y = y;
}

void B::zeigeinhalt()
{
    cout <<"Inhalt von B: "<<_x<<", "<<_y<<endl;
}

void operator +=(B &obj, int z) // Operator global definieren und mit friend funktion in Klasse inkludieren
{
    obj._x+=z;
    obj._y+=z;
}

int main()
{
    A a1("Text zum Testen"); //Objekte zum Testen erzeugen
    B b1(10, 20);
    
    a1.zeigeinhalt();
    b1.zeigeinhalt();
    
    a1+="und noch mehr";
    b1+=5;
    
    a1.zeigeinhalt();
    b1.zeigeinhalt();
    
    a1.operator+=(" Gummibaeren"); //a1.+= und a1.operator+= sind gleichwertig
    operator+=(b1, 10);            //b1+=... und operator+=(...) sind gleichwertig
    
    a1.zeigeinhalt();
    
    return 0;
}


// in c++ sind alle Operatoren als Funktionen definiert
// --> Funktionsname für den += Operator lautet also 'operator+='; der für den << Operator lautet 'operator<<'
// Algemeine Operatordefinition:
// <Rückgabetyp> operator <operator-token>(<Übergabeparameter>)
//