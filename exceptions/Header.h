//
//  Header.h
//  exceptions
//
//  Created by Tom Haider on 23.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>

using namespace std;

class Error
{
private:                    //Klasse enhält private Fehlertext
    string msg;
public:
    Error(string m)    //Objekte werden über Konstruktor initilaisiert
    {
        msg = m;
    }
    ~Error()
    {
    }
    string showMsg() const     //Fehlerausgabe
    {
        return msg;
    }
};

class Test
{
public:
    int zahl;
    
public:
    Test();
    ~Test();
};


#endif /* Header_h */
