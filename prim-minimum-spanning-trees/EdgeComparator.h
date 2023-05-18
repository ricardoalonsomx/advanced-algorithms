//
//    Title: Homework 06 - Prim's algorithm for Minimum Spanning Trees.
//    Description: Header code for the EdgeComparator class.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 6th, 2021.



#ifndef EdgeComparator_h
#define EdgeComparator_h

#include "Edge.h"

class EdgeComparator
{
    public:
        bool operator()(Edge &e1, Edge &e2) { return e1.getWeight() > e2.getWeight(); }
};

#endif /* EdgeComparator_h */
