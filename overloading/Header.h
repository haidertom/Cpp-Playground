//
//  Header.h
//  overloading
//
//  Created by Tom Haider on 20.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef Header_h
#define Header_h

class A
{
public:
    A(char *t);
    void zeigeinhalt();
    void operator +=(char*t);       //Operator als Klassenmethode definieren
private:
    char text[51];
};

class B
{
    friend void operator +=(B &obj, int z); //&obj ist eine Referenz auf ein Objekt der Klasse B
public:
    B(int x, int y);
    void zeigeinhalt();
private:
    int _x;
    int _y;
};

#endif /* Header_h */
