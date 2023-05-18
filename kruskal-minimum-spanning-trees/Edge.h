#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        Edge(){};
        Edge(int _firstNode, int _secondNode, float _weight);
        virtual ~Edge(){};

        void setFirstNode(int _firstNode) { firstNode = _firstNode; };
        int getFirstNode() { return firstNode; };

        void setSecondNode(int _secondNode) { secondNode = _secondNode; };
        int getSecondNode() { return secondNode; };

        void setWeight(float _weight) { weight = _weight; };
        float getWeight() { return weight; };

        bool operator< (Edge &other) const { return weight < other.getWeight(); }

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
 
