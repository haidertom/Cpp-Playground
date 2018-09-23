//
//  abel.cpp
//  abschluss
//
//  Created by Tom Haider on 13.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include "abel.hpp"

inter::inter()
{
}

inter::inter(string t)
{
    titel = t;
    first = NULL;
}

inter::~inter()
{
    delete first;
}

inter::inter(const inter & I)
{
    first = new concrete(*(I.first));
    titel = I.titel;
}

void inter::add(string mar, string ty, double pr)
{
    concrete * pTemp = new concrete(mar, ty, pr);
    
    if(first==0)
        first = pTemp;
    
    else
        first->anfuegenElement(pTemp);
    
}

void inter::allout()
{
    if(first)
    {
        cout<<titel<<endl;
    cout<<setw(10)<<"marke"
    <<setw(10)<<"typ"
    <<setw(10)<<"preis"
    <<setw(15)<<"prev"
    <<setw(15)<<"this"
    <<setw(15)<<"next"
    <<endl;
    
    first->allOut();
    }
    else
        cout<<"Keine Kleiderstücke vorhanden";
}


concrete::concrete():next(0), prev(0)
{
}

concrete::concrete(string mar, string ty, double pr, concrete * ne)
{
    marke = mar;
    typ = ty;
    preis = pr;
    next = ne;
    prev = 0;
}

concrete::concrete(const concrete & C)
{
    marke = C.marke;
    typ = C.typ;
    preis = C.preis;
    prev = 0;
    
    if(C.next)
    {
        next=new concrete(*(C.next));
        next->prev = this;
    }
}

concrete::~concrete()
{
    
}

void concrete::anfuegenElement(concrete * newEle)
{
    if(next!= 0)
        next->anfuegenElement(newEle);
    else
    {
        next = newEle;
        next->prev = this;
    }
}

void concrete::ausgeben()
{
    cout<<setw(10)<<marke
        <<setw(10)<<typ
        <<setw(10)<<preis
        <<setw(15)<<prev
        <<setw(15)<<this
        <<setw(15)<<next
        <<endl;
}

void concrete::allOut()
{
    ausgeben();
    if(next!= 0)
    {
        
        next->allOut();
    }
}

void inter::operator += (const inter I)
{
    first = NULL;
    first = new concrete(*I.first);
}
