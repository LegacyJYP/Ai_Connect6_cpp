//
// Created by 박재영 on 2017. 5. 13..
//

#include "TimeUtils.h"
#include "PrintUtils.h"
#include "LOG_BY_EACHFUNCTION.h"
#include "LogUtils.h"
#include <iostream>
#include <map>
//#include<chrono>

using namespace std;
using namespace chrono;

static time_point<system_clock> start;

static map<int, time_point<system_clock>> START_TIMES;


void tic(){
    start = system_clock::now();
}

void tic(int key) {
    map<int, time_point<system_clock>>::iterator it = START_TIMES.find(key);
    if (it == START_TIMES.end()) { // element not found
        START_TIMES.insert(pair<int, time_point<system_clock>>(key, system_clock::now()));
//        log("tic START_TIMES insert");
    } else {
        it->second = system_clock::now();
//        log("tic START_TIMES update");
    }
}

double toc() {
    time_point<system_clock> end = system_clock::now();

    duration<double> elapsed_seconds = end - start;

    return elapsed_seconds.count();
}

double toc(int key) {
    time_point<system_clock> end = system_clock::now();

    time_point<system_clock> startByKey = START_TIMES.find(key)->second;

    duration<double> elapsed_seconds = end - startByKey;

    return elapsed_seconds.count();
}

void printToc() {
    cout << toc();
    nln;
}

void printToc(int key) {
    cout << toc(key);
    nln;
}