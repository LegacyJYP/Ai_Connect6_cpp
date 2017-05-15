//
// Created by 박재영 on 2017. 5. 15..
//

#include <cstdlib>
#include "NodeListMap.h"
#include "../../../test/utils/LogUtils.h"


map<int,map<string,Node*>>* NODE_LIST_MAP = new map<int,map<string,Node*>>();

Node* addNode(Node* mother, vector<vector<int>> stonePair, int stoneType, int depth) {
    Node* nodePtr;

        map<string, Node *> nodeList;

        map<int,map<string,Node*>>::iterator it = NODE_LIST_MAP->find(depth);
        if(it == NODE_LIST_MAP->end()){ // not exist depthmap
            pair<int, map<string, Node*>> depthMap(depth, map<string,Node*>());
            NODE_LIST_MAP->insert(depthMap);
            nodeList = depthMap.second;
        }
        else {
            nodeList = NODE_LIST_MAP->find(depth)->second;
        }
        string hashKey = "a";

//        string myHashKey = mother->getMyHashKey();
//        string notMyHashKey = mother->getNotMyHashKey();
//        if(stoneType == MY) {
//            myHashKey += stones2hash(stonePair);
//        } else {
//            notMyHashKey += stones2hash(stonePair);
//        }

        map<string,Node*>::iterator jt = nodeList.find(hashKey);
        if(jt != nodeList.end()) { // exist hashKey
            nodePtr = jt->second; // existNode
        } else
        {
            nodePtr = new Node(mother, stonePair);
            pair<string, Node *> nodePair(hashKey, nodePtr);
            nodeList.insert(nodePair);

//            loginfo("NodeListMap","Node* ","nodeList.insert, size=",nodeList.size());
        }

    return nodePtr;
}

void removeNodes(int nTurns) {
    bool printFlag = false;

    Node* nodePtr;

    map<string, Node *> nodeList;

    map<int,map<string,Node*>>::iterator it = NODE_LIST_MAP->find(nTurns);
    if(it == NODE_LIST_MAP->end()){ // not exist depthmap
        loginfo("NodeListMap","remoteNodes","not exist depthmap",printFlag);
    }
    else {
        nodeList = it->second;

        for(auto node : nodeList) {
            free(node.second);
        }
        nodeList.clear();
    }
}

Node* addNode(vector<vector<int>> board, int stoneType,int nTurns) { // root change
    bool printFlag = false;

    Node* nodePtr;

    map<string, Node *> nodeList;

    map<int,map<string,Node*>>::iterator it = NODE_LIST_MAP->find(nTurns);
    if(it == NODE_LIST_MAP->end()){ // not exist depthmap
        pair<int, map<string, Node*>> depthMap(nTurns, map<string,Node*>());
        NODE_LIST_MAP->insert(depthMap);
        nodeList = depthMap.second;
    }
    else {
        nodeList = NODE_LIST_MAP->find(nTurns)->second;
    }
    string hashKey = "a";

    map<string,Node*>::iterator jt = nodeList.find(hashKey);
    // todo findByBoard()
    if(jt != nodeList.end()) { // exist hashKey
        nodePtr = jt->second; // existNode
    } else
    {
        nodePtr = new Node(board, stoneType, nTurns);
        pair<string, Node *> nodePair(hashKey, nodePtr);
        nodeList.insert(nodePair);

        loginfo("NodeListMap","Node* ","nodeList.insert, size=",nodeList.size(), printFlag);
    }

    return nodePtr;
}