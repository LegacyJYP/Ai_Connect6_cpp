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
#include "NodeListMap.h"

Node* ROOT_PTR = nullptr;

void Node::extend(vector<vector<vector<int>>> stonePairs) {
    loginfo("Node","Node::extend", false);
    for (auto stonePair : stonePairs) {
        Node* child = new Node(this, stonePair);
//        child->getDepth()
        this->addChild(child);
//        loginfo("Node","Node::extend","stonePair=below");
//        printStonePair(stonePair);
    }

//    int len = stonePairs.size();
//    loginfo("Node","Node::extend","len=",len);
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
        vector<vector<int>> board = this->getBoard();
        this->eval = evaluation(board, this->stoneType);
//        loginfo("Node","Node::getEvaluation","this->isEvaluated=",this->isEvaluated,true);
        loginfo("Node","Node::getEvaluation","board below", false);
        loginfo("Node","Node::getEvaluation","this->eval=",this->eval, false);
//        printBoard(board);
        this->isEvaluated = true;
    }

    return this->eval;
}

Node* Node::getMother() {
    return this->mother;
}

int Node::getnTurns() {
    return this->nTurns;
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

string Node::getHashKey() {
    vector<vector<vector<int>>> stoneList = this->getAllStones();
    vector<vector<int>> myStones = stoneList[0];
    vector<vector<int>> notMyStones = stoneList[1];


    for(auto stone : stoneList[0]) { // MY_STONE

    }
    for(auto stone : stoneList[1]) { // NOT_MY_STONE
        stone;
    }
}

vector<vector<vector<int>>> Node::getAllStones() {
    Node* node = this;
    vector<vector<vector<int>>> stoneList(2);

    if(node->isRoot) {
        return vector<vector<vector<int>>>(2);
    }

    while(true) {
        if (node->getStoneType() == MY_STONE) {
            stoneList[MY_STONE_LIST].push_back(node->getStones()[0]);
            stoneList[MY_STONE_LIST].push_back(node->getStones()[1]);
        } else {
            stoneList[NOT_MY_STONE_LIST].push_back(node->getStones()[0]);
            stoneList[NOT_MY_STONE_LIST].push_back(node->getStones()[1]);
        }
        if(node->getMother()->isRoot) {
            break;
        } else {
            node = node->getMother();
        }
    }

    loginfo("Node","Node::getAllStones","stoneList[MY_STONE] below");
    printStonePointList(stoneList[0]);
    loginfo("Node","Node::getAllStones","stoneList[NOT_MY_STONE] below");
    printStonePointList(stoneList[1]);

    return stoneList;
}

Node* getOrCreateRoot(vector<vector<int>> board, int stoneType) {
    bool printFlag = false;

    if (ROOT_PTR  == nullptr) {
        int nTurns = 0; // 흑이든 백이든 일단 0부터 시작.
        ROOT_PTR  = addNode(board,ENEMY_STONE(stoneType),nTurns);
        loginfo("Node","getOrCreateRoot","rootPtr isNull, createRoot", printFlag );
    } else {
        int nTurns = ROOT_PTR->getnTurns()+2;
        free(ROOT_PTR);

        removeNodes(nTurns-2);
        removeNodes(nTurns-1);

        ROOT_PTR  = addNode(board, ENEMY_STONE(stoneType), nTurns);
        loginfo("Node","getOrCreateRoot","rootPtr notNull",printFlag);
    }

    return ROOT_PTR ;
}

//string hashKey = stonePair;
//double eval = evaluation(putStonePoints(getBoard()));