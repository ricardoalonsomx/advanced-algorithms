//
//    Title: Homework 07 - Floyd-Warshall for finding the shortest path.
//    Description: Header code for the DirectedGraph class.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 21st, 2021.

#ifndef DirectedGraph_h
#define DirectedGraph_h

#include <limits>

#include "Graph.h"

class DirectedGraph : public Graph
{
public:
    void floyd_warshall_algorithm();
    std::vector<Edge> floyd_warshall_algorithm_search(int firstNode, int secondNode);
    void floyd_warshall_algorithm_search_print(int firstNode, int secondNode);
    
private:
    std::vector<std::vector<int>> dist;
    std::vector<std::vector<int>> next;
};

void DirectedGraph::floyd_warshall_algorithm()
{
    dist.clear();
    next.clear();
    
    dist.assign(nodes.size(), std::vector<int>(nodes.size(), std::numeric_limits<int>::max()/2));
    next.assign(nodes.size(), std::vector<int>(nodes.size(), -1));
    
    
    for (auto edge : edges) {
        
        dist.at(edge.getFirstNode()).at(edge.getSecondNode()) = edge.getWeight();
        next.at(edge.getFirstNode()).at(edge.getSecondNode()) = edge.getSecondNode();
    }
    
    for (auto node : nodes) {
        dist.at(node).at(node) = 0;
    }
    
    for (auto k : nodes) {
        for (auto i : nodes) {
            for (auto j : nodes) {
                if (dist.at(i).at(j) > dist.at(i).at(k) + dist.at(k).at(j)) {
                    dist.at(i).at(j) = dist.at(i).at(k) + dist.at(k).at(j);

                    next.at(i).at(j) = next.at(i).at(k);
                }
            }
        }
    }

}

std::vector<Edge> DirectedGraph::floyd_warshall_algorithm_search(int firstNode, int secondNode)
{
    std::vector<Edge> result;
    int* i = new int(firstNode);
    int* nextNode = new int;
        
    do {
        *nextNode = next.at(*i).at(secondNode);

        result.push_back(*new Edge (*i, *nextNode, dist.at(*i).at(*nextNode)));

        *i = *nextNode;
    } while (*i != secondNode);
    
//    delete i;
//    delete nextNode;
    
    return result;
}

void DirectedGraph::floyd_warshall_algorithm_search_print(int firstNode, int secondNode)
{
    std::vector<Edge> backup = edges;
    edges = this->floyd_warshall_algorithm_search(firstNode, secondNode);
    
    this->printEdges();
    
    edges = backup;
    backup.clear();
}



#endif /* DirectedGraph_h */
