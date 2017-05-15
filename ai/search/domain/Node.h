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
    bool extended;
    Node* mother;
    list<Node*> children;
    bool isRoot;
    vector<vector<int>> stonePair;
    int stoneType;
    int nTurns;
    double eval;
    bool isEvaluated=false;
    vector<vector<int>> board;
public:
    Node() {};

    Node(double eval) : eval(eval), extended(true) {}; // for test todo remote
    Node(double eval, bool isRoot) : eval(eval), isRoot(isRoot), extended(true) {}; // for test todo remote

    Node(vector<vector<int>> board, int stoneType, int nTurns) : isRoot(true), extended(false),
                                                                stoneType(stoneType), nTurns(nTurns)
    {
        setState(board, true);
    };

    Node(Node* node, vector<vector<int>> stonePair) : isRoot(false), mother(node),
                                                      extended(false), stonePair(stonePair),
                                                      nTurns(getMother()->getnTurns()+1)
    {
        setState(stonePair);
        setStoneTypeByMother();
    };

    void extend(vector<vector<vector<int>>>);
    void addChild(Node* child);
    Node* getMother();
    list<Node*> getChildren();
    int getnTurns();
    vector<vector<int>> getStones();
    string getHashKey();
    vector<vector<int>> getBoard();
    vector<vector<int>> getDiffBoard();
    int getStoneType();
    vector<vector<vector<int>>> getAllStones();
    void setState(vector<vector<int>> stonePair);
    void setState(vector<vector<int>> board, bool isRoot);
    double getEvaluation();
    void setStoneTypeByMother();
    bool isExtended();
};

Node* getOrCreateRoot(vector<vector<int>> board, int stoneType);


#endif //AI_CONNECT6_NODE_H
