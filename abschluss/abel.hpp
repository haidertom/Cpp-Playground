//
//  abel.hpp
//  abschluss
//
//  Created by Tom Haider on 13.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef abel_hpp
#define abel_hpp

#include <iostream>
#include <iomanip>

using namespace std;



class concrete
{
private:
    string marke;
    string typ;
    double preis;
    
    concrete * next;
    concrete * prev;
    
public:
    concrete();
    ~concrete();
    concrete(string ma, string ty, double pr, concrete * ne = 0);
    concrete(const concrete & C);
    void anfuegenElement(concrete * neuesElement);
    void ausgeben();
    void allOut();
    
};

class inter
{
private:
    string titel;
    concrete * first;
    
    
public:
    inter();
    inter(string t);
    inter(const inter & I);
    ~inter();
    
    void add(string mar, string ty, double pr);
    void ausgeben();
    
    void allout();
    
    void operator +=(const inter I);
    
};


#include <stdio.h>

#endif /* abel_hpp */
