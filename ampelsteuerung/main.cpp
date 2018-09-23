//
//  main.cpp
//  ampelsteuerung
//
//  Created by Tom Haider on 30.06.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;



class Ampel
{
public:
    
    string Ampel1;
    string Ampel2;
    
    struct Ampel * next;
public:
    Ampel();

};


class durchlauf
{
private:
    Ampel * first;
    
public:
    durchlauf();

    durchlauf (string a1, string a2);
    void neuerZustand(string a1, string a2);
    void ausgeben() const;
};


Ampel::Ampel()
{

}

durchlauf::durchlauf()
{
    first = 0;
}

durchlauf::durchlauf(string a1, string a2)
{
    first = 0;
    neuerZustand(a1, a2);
}

void durchlauf::neuerZustand(string a1, string a2)
{
    if(first == 0)
    {
        first = new Ampel;
        first->Ampel1 = a1;
        first->Ampel2 = a2;
        first->next = first;
    }
    
    else
    {
        Ampel *temp;

        temp = first;
        
        while(temp->next != first)
        {
            temp = temp->next;
        }
    
        temp->next = new Ampel;
        
        temp = temp->next;
        
        temp->Ampel1 = a1;
        temp->Ampel2 = a2;
        
        temp->next = first;
    }
}

void durchlauf::ausgeben() const
{
    Ampel *temp = first;
    char c;
    int i = 1;
    
    cout<<"'n' für nächsten Zustand drücken!";

    while(1)
    {
        
        cin>>c;
        
        if(c == 'n')
        {
            cout<<"Zustand"<<i<<": ";
            cout<<temp->Ampel1;
            cout<<temp->Ampel2<<endl;
            temp = temp->next;
            i++;
            if(i>=7)
                i = 1;
        }
        else if(c == '+')
        {
            cout<<"Anzuhängendes Array eingeben"<<endl;
            string s1, s2;
            cin>> s1>>s2;
            temp->Ampel1 += s1;
            temp->Ampel2 += s2;
        }
        
        else
            cout<<"fehler";
    }
}


int main()
{
    durchlauf * pPoi = new durchlauf("Rot", "Gelb");
    pPoi->neuerZustand("Grün", "Blau");
    
    pPoi->ausgeben();
    
    return 0;
}