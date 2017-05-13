//
// Created by 박재영 on 2017. 5. 13..
//

#include "LogUtils.h"
#include <iostream>


using namespace std;


void nln() {
    cout << '\n';
}

void log(string s) {
    cout << s << '\n';
}

void log(string s1, string s2) {
    cout << s1 << " " << s2 << '\n';
}

void log(const char* s) {
    cout << s << '\n';
}

void log(const char* s1, const char* s2) {
    cout << s1 <<" " << s2<< '\n';
}

void log(std::string s, bool printFlag) {
    if(printFlag) {
        log(s);
    }
}

void log(const char* s, bool printFlag){
    if(printFlag) {
        log(s);
    }
}

void log(string s1, string s2, bool printFlag) {
    if(printFlag) {
        log(s1,s2);
    }
}

void log(const char* s1, const char* s2, bool printFlag) {
    if(printFlag) {
        log(s1,s2);
    }
}

template <typename T>
void loginfo(T a)
{
    cout << a << endl;
}

template <typename T1, typename T2>
void loginfo(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}
