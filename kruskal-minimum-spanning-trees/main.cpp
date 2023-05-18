/*
    Title: Homework 05 - Kruskal's algorithm for Minimum Spanning Trees.
    Description: Main code for the Homework 05 algorithms test-cases.

    Author: Aldo Ricardo Alonso Arostegui - A01029011

    Proffesor: Leonardo Chang Fernández
    First release: October 6th, 2021.
*/



#include <iostream>
#include "Graph.h"



int main(int argc, const char * argv[]) {
    
    Graph* activityGraph = new Graph;
    int* edgesSize = new int(atoi(argv[1]));
    
    for (int i = 2; i < *edgesSize+2; i++) {
        activityGraph->addEdge(atoi(argv[i]), atoi(argv[i+*edgesSize]), atoi(argv[i+*edgesSize*2]));
    }
    
    activityGraph->kruskalsAlgorithm();
    activityGraph->printEdges();
    
    return 0;
}

 
