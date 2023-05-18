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
        Edge(int _firstNode, int _secondNode, float _weight);
        virtual ~Edge(){};

        void setFirstNode(int _firstNode) { firstNode = _firstNode; };
        int getFirstNode() const { return firstNode; };

        void setSecondNode(int _secondNode) { secondNode = _secondNode; };
        int getSecondNode() const { return secondNode; };

        void setWeight(float _weight) { weight = _weight; };
        float getWeight() const { return weight; };

        bool operator< (const Edge &other) const { return weight < other.getWeight(); }

    private:
        int firstNode = -1;
        int secondNode = -1;
        float weight;
};

Edge::Edge(int _firstNode, int _secondNode, float _weight)
{
    firstNode = _firstNode;
    secondNode = _secondNode;
    weight = _weight;
}


#endif // EDGE_H
 
