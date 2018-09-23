//
//  klausur.hpp
//  klausurverwaltung
//
//  Created by Tom Haider on 24.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef klausur_hpp
#define klausur_hpp

#include <iostream>
#include <stdio.h>

#include "einzelergebnis.hpp"

class Klausur 
{
private:
    Einzelergebnis * myroot;
    string Titel;
    
public:
    Klausur(string t);
    Klausur(const Klausur &s);
    ~Klausur();
    
    void add(string Teilnehmername, int Punkte, int Note);
    
    void ausgeben(std::ostream & out) const;
    void sortieren();
    void einlesen(std::ifstream &eingabe);
    
    void operator<<(std::ostream & out);
    
};

#endif /* klausur_hpp */
