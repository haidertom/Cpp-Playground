#include <iostream>
#include "bruch.h"

using namespace std;

int main(int argc, char *argv[]){

    cout<<"**Test: Verwendung von Set, und Print\n";
    Bruch b;
    b.Set(); b.Print();
    b.Set(1,-2); b.Print();
    cout<<"\n(0/1)(1/-2) = Zeile darueber\n\n";

    cout<<"**Test: Ueberladene Set Methode mit double Argumenten\n";
    cout<<"  Fehlerhaft ohne die fuer double ueberladene Set Methode!\n";
    b.Set(2.99, 1.01); b.Print();
    cout<<"\n(3/1) = Zeile darueber\n\n";

    b.Set( 2.99,  2.01); b.Print();
    b.Set( 2.99, -2.01); b.Print();
    b.Set(-2.99,  2.01); b.Print();
    b.Set(-2.99, -2.01); b.Print();
    cout<<"\n(3/2)(3/-2)(-3/2)(-3/-2) = Zeile darueber\n\n";

    Bruch a;

    cout<<"**Test: Ueberladene Set Methode mit Bruch Referenz als Argument\n";
    b.Set(1,2); b.Print();
    a.Set(b); a.Print();
    b.Set(-3,4); b.Print();
    a.Set(b); a.Print();
    cout<<"\n(1/2)(1/2)(-3/4)(-3/4) = Zeile darueber\n\n";



    cout<<"**Test: Ueberladene Print Methode\n";
    b.Set( 2,  2); b.Print(2); cout<<" ";
    b.Set( 2, -2); b.Print(2); cout<<" ";
    b.Set(-2,  2); b.Print(2); cout<<" ";
    b.Set(-2, -2); b.Print(2); cout<<" ";
    cout<<"\n1.00 -1.00 -1.00 1.00 = Zeile darueber\n\n";

    b.Set(17, 7); b.Print(20);
    cout<<"\n2.42857142857142857142 = Zeile darueber\n\n";
    b.Set(1727, 1773); b.Print(50);
    cout<<"\n0.97405527354765933446136491821771009588268471517202 = Zeile darueber\n\n";


    cout<<"**Test: Rechnen mit Bruechen\n";
    Bruch s, p;
    a.Set(1, 2); b.Set(1, 3);
    s.Set(a.Add(b));s.Print();
    p.Set(a.Mul(b));p.Print();
    cout<<"\n(5/6)(1/6) = Zeile darueber\n\n";



    cout<<"**Test: Vergleich von Brüchen\n";
    a.Set(1727, 3729); b.Set(1727, 3728);
    cout<<a.Equal(a)<<b.Equal(b)<<" ";
    cout<<a.Equal(b)<<b.Equal(a)<<" ";
    cout<<"\n11 00 = Zeile darueber\n\n";


    return 0;
}


