//
//    Title: Homework 07 - Floyd-Warshall for finding the shortest path.
//    Description: Header code for the Edge class.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 21st, 2021.



#ifndef EdgeComparator_h
#define EdgeComparator_h

#include "Edge.h"

class EdgeComparator
{
    public:
        bool operator()(Edge &e1, Edge &e2) { return e1.getWeight() > e2.getWeight(); }
};

#endif /* EdgeComparator_h */
