//
// Created by 박재영 on 2017. 5. 14..
//

#include "Node.h"
#include "../../heuristic/JYP/Evaluation_JYP.h"
#include "../../../test/utils/LogUtils.h"
#include "../../../test/utils/PrintUtils.h"
#include "../../../consts/GAME_BOARD.h"
#include "../../../test/Samples.h"
#include "../../utils/BoardUtils.h"
#include "../../heuristic/Evaluation.h"

Node root;
Node* rootPtr = nullptr;

void Node::extend(vector<vector<vector<int>>> stonePairs) {
    loginfo("Node","Node::extend");
    for (auto stonePair : stonePairs) {
        Node* child = new Node(this, stonePair);
        this->addChild(child);
//        loginfo("Node","Node::extend","stonePair=below");
//        printStonePair(stonePair);
    }
    this->extended = true;
}

void Node::addChild(Node *child) {
    this->children.push_back(child);
}

list<Node*> Node::getChildren() {
    return this->children;
}

vector<vector<int>> Node::getBoard() {
    if(this->isRoot) {
        return this->board;
    }
    else {
        vector<vector<int>> board = this->mother->getBoard();
        board = putStonePoints(board, this->stonePair, this->stoneType);
        return board;
    }

    return getSample(1); // replace stub -> 완료
}

vector<vector<int>> Node::getDiffBoard() {
    if(this->isRoot) {
        loginfo("Node","getDiffBoard","this is root!!(NoDifferences)");
        return this->board;
    }
    else {
        vector<vector<int>> board = this->mother->getBoard();
        board = putStonePointsForVisualize(board, this->stonePair, this->stoneType);
        return board;
    }

    return getSample(1); // replace stub -> 완료
}

double Node::getEvaluation() {
    if(this->isEvaluated) {
//        loginfo("Node","Node::getEvaluation","this->isEvaluated=",this->isEvaluated);
//        return this->eval; // replace stub -> 완료
    } else {
//        loginfo("Node","Node::getEvaluation","this->isEvaluated=",this->isEvaluated);
        vector<vector<int>> board = this->getBoard();
        this->eval = evaluation(board, this->stoneType);
        this->isEvaluated = true;
    }

//    loginfo("Node","Node::getEvaluation","this->eval=",this->eval);
    return this->eval;
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

bool Node::isExtended() {
    return this->extended;
}

vector<vector<int>> Node::getStones() {
    return this->stonePair;
}

void Node::setStoneTypeByMother() {
    this->stoneType = ENEMY_STONE(getMother()->getStoneType());
}

void Node::setState(vector<vector<int>> stonePair) {
    this->stonePair = stonePair;
//    getMothersStonePairs
//    devide black orwhite
//    sort -> hashKey
//
//    State* asdf = State(stonePair, this->depth, this->stoneType);
}

void Node::setState(vector<vector<int>> board, bool isRoot) {
    if(isRoot) {
        this->board = board;
//        string HashKey = "";
//        State* asdf = State(board, this->depth, this->stoneType);
//        Map<string,State>;
    } else {
        loginfo("Node","Node::setState","isRoot=",isRoot);
        this->setState(board);
    }
}

Node* getOrCreateRoot(vector<vector<int>> board, int stoneType) {
    int depth =0;
    if (rootPtr == nullptr) {
        root = Node(board,ENEMY_STONE(stoneType),depth);
        rootPtr = &root;
        loginfo("Node","getOrCreateRoot","rootPtr isNull, createRoot");
    } else {
        loginfo("Node","getOrCreateRoot","rootPtr notNull");
    }

    return rootPtr;
}

//string hashKey = stonePair;
//double eval = evaluation(putStonePoints(getBoard()));