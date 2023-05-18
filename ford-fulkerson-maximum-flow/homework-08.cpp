//
//  main.cpp
//  Homework_08
//
//  Created by Aldo Ricardo Alonso Arostegui on November 10th 2021.
//

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, const char * argv[]) {
    
    DirectedGraph* activityGraph = new DirectedGraph;
    int* edgesSize = new int(atoi(argv[1]));
    
    for (int i = 2; i < *edgesSize+2; i++) {
        activityGraph->addEdge(atoi(argv[i]), atoi(argv[i+*edgesSize]), atoi(argv[i+*edgesSize*2]));
    }
    
    activityGraph->ford_fulkerson_agorithm(atoi(argv[*edgesSize*3+2]), atoi(argv[*edgesSize*3+3]));
    

    
    
    return 0;
}
