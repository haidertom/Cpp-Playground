//
//  main.cpp
//  Buchladen
//
//  Created by Tom Haider on 12.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
using namespace std;

#define max(x,y) ((x)>(y)) ? (x):(y)

class box
{
private:
    double x,y,z;
public:
    box();
    box(const box & B);
    
    box(double w, double h, double t);
    box operator +(box b);
    
    friend int operator >(box a, box b);
    void print();
};

box::box(const box & B)
{}

box::box(): x(0), y(0), z(0)
{
//    x=0;
//    y=0;
//    z=0;
    cout<<x<<y<<z<<endl;
}

box::box(double w, double h, double t)
{
    x = w;
    y = h;
    z = t;
}



box box::operator +(box b)
{
    // Rumpf der Methode hier implementieren
   
    box neu;        //dadurch dass neue box beschireiben wird, bleiben die alten so erhalten wie sie sind
    
    if(x<b.x)
        neu.x=b.x;
    else
        neu.x=x;
    if(y<b.y)
        neu.y=b.y;
    else
        neu.y=y;
    
    neu.z = z + b.z ;

    return neu;
}

void box::print()
{
    cout<<x<<endl<<y<<endl<<z<<endl;
}

int operator >(box a, box b)
{
    if(a.x > b.x && a.y > b.y &&  a.z>b.z)
        return 1;
    else
        return 0;
}

int main()
    {
        box b1(10,20,2);
        box b2(15,20,3);
        box b3(15,25,1);
        box b4(100,2,10);

        box b=b1+b2+b3;
        
        b.print();
        
        box * bneu = new box();
        
        *bneu = (b1+b2);
        
        
        b1.print();
        b2.print();
        cout<<"neue";
        bneu->print();
        
        
        cout<<"flacher Copy Konsturktor";
        box kopiert(b1);
        
        kopiert.print();
        
        // Bücher b1,b2,b3 stapeln
        // Maße x,y,z ausgeben: 15 25 6
        
        
        // Vergleichsoperator > zum Test, ob eine Versandbox groß genug ist
    
    
    box s(20,30,5);
        cout<<"Box s: ";

    if(s>b)
        cout<<"Passt\n";
    else
        cout<<"zu klein\n"; // Zu klein
    
    box z(20,30,7);
        cout<<"Box z: ";
        
    if(z>b)
        cout<<"Passt\n"; // Passt
    else
        cout<<"zu klein\n";

    }