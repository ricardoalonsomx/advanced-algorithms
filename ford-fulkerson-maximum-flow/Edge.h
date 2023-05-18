//
//    Title: Homework 07 - Floyd-Warshall for finding the shortest path.
//    Description: Header code for the Edge class.
//    Author: Aldo Ricardo Alonso Arostegui - A01029011.
//    Proffesor: Leonardo Chang Fernández.
//    First release: October 21st, 2021.



#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(){};
    Edge(int _firstNode, int _secondNode, int _weight, Edge* _residualEdge = nullptr, bool _residual = false);
    virtual ~Edge(){};

    void setFirstNode(int _firstNode) { firstNode = _firstNode; };
    int getFirstNode() const { return firstNode; };

    void setSecondNode(int _secondNode) { secondNode = _secondNode; };
    int getSecondNode() const { return secondNode; };

    void setWeight(int _weight) { weight = _weight; };
    int getWeight() const { return weight; };
    
    void setAsResidual() { residual = true; };
    bool isResidual() { return residual; };
    
    void setResidualEdge(Edge* _residualEdge) { residualEdge = _residualEdge; };
    Edge* getResidualEdge() { return residualEdge; };

    bool operator< (const Edge &other) const { return weight < other.getWeight(); }

private:
    int firstNode = -1;
    int secondNode = -1;
    int weight;
    Edge* residualEdge = nullptr;
    bool residual = false;
};

Edge::Edge(int _firstNode, int _secondNode, int _weight, Edge* _residualEdge, bool _residual)
{
    firstNode = _firstNode;
    secondNode = _secondNode;
    weight = _weight;
    residualEdge = _residualEdge;
    residual = _residual;
}


#endif // EDGE_H
 
