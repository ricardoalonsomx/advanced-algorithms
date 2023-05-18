//
//    Title: Homework 07 - Floyd-Warshall for finding the shortest path.
//    Description: Main code for the Homework 07 algorithms test-cases.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 21st, 2021.

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, const char * argv[]) {

    DirectedGraph* activityGraph = new DirectedGraph;
    int* edgesSize = new int(atoi(argv[1]));
    
    for (int i = 2; i < *edgesSize+2; i++) {
        activityGraph->addEdge(atoi(argv[i]), atoi(argv[i+*edgesSize]), atoi(argv[i+*edgesSize*2]));
    }
    
    activityGraph->floyd_warshall_algorithm();
    activityGraph->floyd_warshall_algorithm_search_print(atoi(argv[*edgesSize*3+2]), atoi(argv[*edgesSize*3+3]));
    
    return 0;
}
