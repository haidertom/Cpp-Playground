//
//  main.cpp
//  abschluss
//
//  Created by Tom Haider on 13.07.16.
//  Copyright © 2016 Tom Haider. All rights reserved.
//

#include <iostream>
#include "abel.hpp"

int main()
{
    inter * Kleiderschrank = new inter("Toms Kleiderschrank");

    Kleiderschrank->add("Hurley", "Hoodie", 33.50);
    Kleiderschrank->add("Nike", "T-Shirt", 15.90);
    Kleiderschrank->add("Hilfigher", "Jeans", 90.90);
    Kleiderschrank->add("GC", "Anzug", 500.0);
    
    Kleiderschrank->allout();
    
    inter * Kommode = new inter("Sepps Kleiderschrank") ;
   
    *Kommode += *Kleiderschrank;
    
    Kommode->allout();
    
    return 0;
}

