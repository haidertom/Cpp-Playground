//
//  bruch.h
//  Bruch
//
//  Created by Tom Haider on 05.05.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#ifndef bruch_h
#define bruch_h

class Bruch
{
    private:
        int Zaehler, Nenner;
    
    public:
        void Set(const int zaehler = 0, const int nenner = 1);
        void Set(double zahler, double nenner = 1);
        void Set(const Bruch & bruch);
    
        void Print();
        void Print(int nachkommastellen);
    
        Bruch Add(const Bruch & bruch);
        Bruch Mul(const Bruch & bruch);
    
        int Equal(const Bruch & bruch);
};




#endif /* bruch_h */
