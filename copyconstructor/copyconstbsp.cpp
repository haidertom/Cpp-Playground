//
//  copyconstbsp.cpp
//  Versuch Struct
//
//  Created by Tom Haider on 03.05.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>

#include <stdlib.h>

using namespace std;

class Line
{
public:
    int getLength( void );
    int *ptr;
    
    Line( int len );                // simple constructor
    Line( const Line &obj);         // copy constructor
    ~Line();                        // destructor
};

// Member functions definitions including constructor------------------------

Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Length of line : " << obj.getLength() <<endl;
}

// Main function for the program------------------------------------------
int main( )
{
    Line line1(10);
    
    Line line2 = line1; // This also calls copy constructor
    
    display(line1);
    display(line2);
    
    return 0;
}
