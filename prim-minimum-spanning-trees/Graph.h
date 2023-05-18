//
//    Title: Homework 06 - Prim's algorithm for Minimum Spanning Trees.
//    Description: Header code for the Graph class.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 6th, 2021.



#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include <algorithm>
#include <queue>

#include "Edge.h"
#include "EdgeComparator.h"

class Graph
{
    public:
        Graph(){};
        virtual ~Graph(){};

        void addEdge(Edge& newEdge);
        void addEdgePrim(Edge& newEdge, int unreached);
        void addEdge(int firstNode, int secondNode, float weight) { this->addEdge(*new Edge(firstNode, secondNode, weight)); };
        void addEdgePrim(int firstNode, int secondNode, float weight, int unreached) { this->addEdgePrim(*new Edge(firstNode, secondNode, weight), unreached); };
        void addEdgeOneNode(int firstNode);

        std::vector<Edge> getEdges() { return edges; };

        void printEdges();
        
        bool isNodeIn(int node);
        void addNode(int node);

        std::vector<int> getNodes() { return nodes; };

        void changeFirstNodeAt(int index, int node) { edges.at(index).setFirstNode(node); this->addNode(node); };
        void changeSecondNodeAt(int index, int node) { edges.at(index).setSecondNode(node); this->addNode(node); };
        void changeWeightAt(int index, float weight) { edges.at(index).setWeight(weight); };

        void removeLastEdge() { edges.pop_back(); };

        void sortEdges() { std::sort(edges.begin(), edges.end()); };

        int findElementSubset(int i);
        void subsetUnion(int x, int y);
        bool isCycle();
        void kruskalsAlgorithm();
        
        void addAdjacentEdges(int node);
        void initializePrim(int node) { nodes.push_back(node); };
        void primsAlgorithm();

        int numberOfNodes() { return nodes.size(); };
        void copyFromGraph(Graph* otherGraph);

    private:
        std::vector<Edge> edges;
        std::vector<int> nodes;
        std::vector<int> parent;            // Used only for the Kruskal's algorithm.
        std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> adjacentEdges;    // Used only for the Prim's algorithm.
};


void Graph::addEdge(Edge& newEdge)
{
    edges.push_back(newEdge);

    if (newEdge.getFirstNode() != -1) {
        this->addNode(newEdge.getFirstNode());
    }

    if (newEdge.getSecondNode() != -1) {
        this->addNode(newEdge.getSecondNode());
    }
}

void Graph::addEdgePrim(Edge& newEdge, int unreached)
{
    edges.push_back(newEdge);
    
    if (unreached == 1)
        this->addNode(newEdge.getFirstNode());
    else
        this->addNode(newEdge.getSecondNode());
}


void Graph::addEdgeOneNode(int firstNode)
{
    Edge* newEdge = new Edge;
    newEdge->setFirstNode(firstNode);

    this->addEdge(*newEdge);
}

void Graph::printEdges()
{
    for (int i = 0; i < edges.size(); i++) {
        std::cout << edges.at(i).getFirstNode() << ' ' << edges.at(i).getSecondNode() << ' ' << edges.at(i).getWeight() << std::endl;
    }
}

bool Graph::isNodeIn(int node)
{
    if (std::find(nodes.begin(), nodes.end(), node) == nodes.end())
        return false;
    return true;
}

void Graph::addNode(int node)
{
    if (!this->isNodeIn(node))
        nodes.push_back(node);
}

int Graph::findElementSubset(int i)
{
    if (parent.at(i) == -1)
        return i;

    return findElementSubset(parent.at(i));
}

void Graph::subsetUnion(int x, int y)
{
    parent.at(x) = y;
}

bool Graph::isCycle()
{
    parent.assign(*max_element(nodes.begin(), nodes.end())+1, -1);

    int* x = new int;
    int* y = new int;

    for (int i = 0; i < edges.size(); i++) {
        *x = this->findElementSubset(edges.at(i).getFirstNode());
        *y = this->findElementSubset(edges.at(i).getSecondNode());

        if (*x == *y)
            return true;

        this->subsetUnion(*x, *y);
    }

    return false;
}

void Graph::kruskalsAlgorithm()
{
    this->sortEdges();

    Graph* result = new Graph;

    for (int i = 0; i < edges.size(); i++) {
        result->addEdge(edges.at(i));

        if (result->isCycle()) {
            result->removeLastEdge();
        }
    }

    this->copyFromGraph(result);
    delete result;
}

void Graph::addAdjacentEdges(int node)
{

    for (auto edge : edges) {
        
        if (edge.getFirstNode() == node || edge.getSecondNode() == node) {
            adjacentEdges.push(edge);
        }
    }
}

void Graph::primsAlgorithm()
{
    std::vector<int> visitedNodes;
    
    // this->sortEdges();
    
    Edge* currentEdge = new Edge;

    Graph* result = new Graph;
    result->initializePrim(edges.at(0).getFirstNode());

    this->addAdjacentEdges(edges.at(0).getFirstNode());


    while (!adjacentEdges.empty()) {
        
        *currentEdge = adjacentEdges.top();
        adjacentEdges.pop();
        
        
        if (result->isNodeIn(currentEdge->getFirstNode())) {
            
            if (!result->isNodeIn(currentEdge->getSecondNode())) {
                result->addEdgePrim(currentEdge->getFirstNode(), currentEdge->getSecondNode(), currentEdge->getWeight(), 2);
                this->addAdjacentEdges(currentEdge->getSecondNode());
            }

        } else {
            
            if (result->isNodeIn(currentEdge->getSecondNode())) {
                result->addEdgePrim(currentEdge->getFirstNode(), currentEdge->getSecondNode(), currentEdge->getWeight(), 1);
                this->addAdjacentEdges(currentEdge->getFirstNode());
            }
        }
    }
    
    result->sortEdges();
    this->copyFromGraph(result);
}

void Graph::copyFromGraph(Graph* otherGraph)
{
    edges = otherGraph->getEdges();
    nodes = otherGraph->getNodes();
}

#endif // GRAPH_H
 
