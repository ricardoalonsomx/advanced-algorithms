//
//  DirectedGraph.h
//  Homework_07
//
//  Created by Aldo Ricardo Alonso Arostegui on 20/10/21.
//

#ifndef DirectedGraph_h
#define DirectedGraph_h

#include <limits>

#include "Graph.h"

class DirectedGraph : public Graph
{
public:
    DirectedGraph() : Graph() {};
    DirectedGraph(int number_of_edges) : Graph(number_of_edges) {};
    
    void floyd_warshall_algorithm(bool inverse = false);
    std::vector<Edge> floyd_warshall_algorithm_search(int firstNode, int secondNode);
    void floyd_warshall_algorithm_search_print(int firstNode, int secondNode);
    
    void ford_fulkerson_agorithm(int originNode, int destinationNode);
    
private:
    std::vector<std::vector<int>> dist;
    std::vector<std::vector<int>> next;
};

void DirectedGraph::floyd_warshall_algorithm(bool inverse)
{
    dist.clear();
    next.clear();
    
    dist.assign(nodes.size(), std::vector<int>(nodes.size(), std::numeric_limits<int>::max()/2));
    next.assign(nodes.size(), std::vector<int>(nodes.size(), -1));
    
    if (inverse) {
        for (auto edge : edges) {
            
            if (edge.getWeight() > 0)
                dist.at(edge.getFirstNode()).at(edge.getSecondNode()) = 1000 / edge.getWeight();
            else
                dist.at(edge.getFirstNode()).at(edge.getSecondNode()) = 0;
                
            next.at(edge.getFirstNode()).at(edge.getSecondNode()) = edge.getSecondNode();
        }
    } else {
        for (auto edge : edges) {
            dist.at(edge.getFirstNode()).at(edge.getSecondNode()) = edge.getWeight();
            next.at(edge.getFirstNode()).at(edge.getSecondNode()) = edge.getSecondNode();
        }
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

void DirectedGraph::ford_fulkerson_agorithm(int originNode, int destinationNode)
{
    std::vector<Edge> path;
    int* bottleneck = new int;
    int* newWeight = new int;
    int* currentIndex = new int;
    Edge* currentEdge = new Edge;
    
    bool running = true;
    
    while (running) {
        do {
            this->floyd_warshall_algorithm(true);
            
            try {
                path = this->floyd_warshall_algorithm_search(originNode, destinationNode);
            }
            catch (...) {
                running = false;
                break;
            }
            
            for (int i = 0; i < path.size(); i++) {
                path.at(i) =  edges.at(this->findEdgeIndex(path.at(i).getFirstNode(), path.at(i).getSecondNode()));
            }
            
            std::sort(path.begin(), path.end());

            *bottleneck = edges.at(this->findEdgeIndex(path.at(0).getFirstNode(), path.at(0).getSecondNode())).getWeight();
            
            if (*bottleneck <= 0) {
                edges.erase(edges.begin() + this->findEdgeIndex(path.back().getFirstNode(), path.back().getSecondNode()));
            }

        } while (*bottleneck <= 0);
        
        if (!running)
            break;
        
        Edge edge;
        for (auto edge : path) {
            *currentIndex = this->findEdgeIndex(edge.getFirstNode(), edge.getSecondNode());
            currentEdge = &edges.at(*currentIndex);
            
            *newWeight = currentEdge->getWeight() - *bottleneck;
            
            if (*newWeight > 0) {
                currentEdge->setWeight(*newWeight);
            } else {
                edges.erase(edges.begin() + *currentIndex);
            }
            
            if (currentEdge->getResidualEdge() == nullptr) {
                this->addEdge(*new Edge(currentEdge->getSecondNode(), currentEdge->getFirstNode(), 0));
                
                currentEdge->setResidualEdge(&edges.back());
                currentEdge->getResidualEdge()->setResidualEdge(currentEdge);
                currentEdge->getResidualEdge()->setAsResidual();
            }
            
            *newWeight = *newWeight >= 0 ? currentEdge->getResidualEdge()->getWeight() + *bottleneck : currentEdge->getResidualEdge()->getWeight() + *bottleneck + *newWeight;
            
            currentEdge->getResidualEdge()->setWeight(*newWeight);
        
        }
    }
    
    int flowSum = 0;
    
    for (auto edge : edges) {
        if (edge.getFirstNode() == destinationNode && edge.isResidual()) {
            flowSum += edge.getWeight();
        }
    }
    
    std::cout << flowSum;
}


#endif /* DirectedGraph_h */
