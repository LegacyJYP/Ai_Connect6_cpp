//
// Created by 박재영 on 2017. 5. 14..
//

#ifndef AI_CONNECT6_NODE_H
#define AI_CONNECT6_NODE_H

#include <vector>
#include <list>
#include <string>


using namespace std;

class Node {
private:
    string hashKey;
    bool isExtended;
    Node* mother;
    list<Node*> children;
    bool isMother;
    vector<vector<int>> stonePair;
    int stoneType;
    int depth;
public:
    Node(vector<vector<int>> board, int stoneType, int depth) : isMother(true), isExtended(false),
                                                                stoneType(stoneType), depth(depth)
    {
        setState(board, true);
    };

    Node(Node* node, vector<vector<int>> stonePair) : isMother(false), mother(node),
                                                      isExtended(false), stonePair(stonePair),
                                                      depth(getMother()->getDepth()+1)
    {
        setState(stonePair);
        setStoneTypeByMother();
    };

    void extend(vector<vector<vector<int>>>);
    void addChild(Node* child);
    Node* getMother();
    list<Node*> getChildren();
    int getDepth();
    int getStoneType();
    void setState(vector<vector<int>> stonePair);
    void setState(vector<vector<int>> board, bool isRoot);
    double getEvaluation();
    void setStoneTypeByMother();
};



#endif //AI_CONNECT6_NODE_H
