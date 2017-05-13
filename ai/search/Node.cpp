//
// Created by 박재영 on 2017. 5. 14..
//

#include "Node.h"
#include "../heuristic/JYP/Evaluation_JYP.h"
#include "../../test/utils/LogUtils.h"
#include "../../test/utils/PrintUtils.h"
#include "../../consts/GAME_BOARD.h"


void Node::extend(vector<vector<vector<int>>> stonePairs) {
//    loginfo("Node","Node::extend");
    for (auto stonePair : stonePairs) {
        Node child = Node(this, stonePair);
        this->addChild(&child);
//        loginfo("Node","Node::extend","stonePair=below");
//        printStonePair(stonePair);
    }
}

void Node::addChild(Node *child) {
    this->children.push_back(child);
}

list<Node*> Node::getChildren() {
    return this->children;
}

double Node::getEvaluation() {
    return 0;
}

Node* Node::getMother() {
    return this->mother;
}

int Node::getDepth() {
    return this->depth;
}

int Node::getStoneType() {
    return this->stoneType;
}

void Node::setStoneTypeByMother() {
    this->stoneType = ENEMY_STONE(getMother()->getStoneType());
}

void Node::setState(vector<vector<int>> stonePair) {
//    getMothersStonePairs
//    devide black orwhite
//    sort -> hashKey
//
//    State* asdf = State(stonePair, this->depth, this->stoneType);
}

void Node::setState(vector<vector<int>> board, bool isRoot) {
    if(isRoot) {
//        string HashKey = "";
//        State* asdf = State(board, this->depth, this->stoneType);
//        Map<string,State>;
    } else {
        loginfo("Node","Node::setState","isRoot=",isRoot);
        this->setState(board);
    }
}

//string hashKey = stonePair;
//double eval = evaluation(putStonePoints(getBoard()));