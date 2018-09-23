//
//  einzelergebnis.hpp
//  klausurverwaltung
//
//  Created by Tom Haider on 24.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef einzelergebnis_hpp
#define einzelergebnis_hpp

#include <stdio.h>


class Einzelergebnis
{
private:
    string Name;
    int Note;
    int Punkte;
    Einzelergebnis * next;
    
public:
    Einzelergebnis();
    Einzelergebnis(string Name, int Punkte, int Note, Einzelergebnis * next = 0);
    Einzelergebnis(const Einzelergebnis & s);
    
    void anfuegenElement(Einzelergebnis * ElementNeu);
    
    void ausgeben(ostream & out) const;
    
     void allesAusgeben (ostream & out, int lfdNummer = 1) const;
    
    Einzelergebnis* sortieren (int &counter);
};

#endif /* einzelergebnis_hpp */
