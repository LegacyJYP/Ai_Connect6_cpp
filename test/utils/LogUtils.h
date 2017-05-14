//
// Created by 박재영 on 2017. 5. 13..
//


#ifndef AI_CONNECT6_LOGUTILS_H
#define AI_CONNECT6_LOGUTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include "../../consts/CONFIG.h"

using namespace std;

template <typename T>
void loginfo(T a)
{
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << endl;
        }
}

template <typename T>
void loginfo(T a, bool isPrint)
{
    if(isPrint) {
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << endl;
        }
    }
}

template <typename T1, typename T2>
void loginfo(T1 a, T2 b)
{
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << endl;
        }
}

template <typename T1, typename T2>
void loginfo(T1 a, T2 b, bool isPrint)
{
    if(isPrint) {
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << endl;
        }
    }
}

template <typename T1, typename T2, typename T3>
void loginfo(T1 a, T2 b, T3 c)
{
        if (LOG_ON_FILE) {

            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << " " << c << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << " " << c << endl;
        }
}


template <typename T1, typename T2, typename T3>
void loginfo(T1 a, T2 b, T3 c, bool isPrint)
{
    if(isPrint) {
        if (LOG_ON_FILE) {

            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << " " << c << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << " " << c << endl;
        }
    }
}

template <typename T1, typename T2, typename T3, typename T4>
void loginfo(T1 a, T2 b, T3 c, T4 d, bool isPrint)
{
    if(isPrint) {
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << " " << c << " " << d << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << " " << c << " " << d << endl;
        }
    }
}

template <typename T1, typename T2, typename T3, typename T4>
void loginfo(T1 a, T2 b, T3 c, T4 d)
{
        if (LOG_ON_FILE) {
            ofstream stream(LOG_FILENAME,
                            ios_base::out |
                            ios_base::app);
            stream << a << " " << b << " " << c << " " << d << endl;
            stream.close();
        }
        if (LOG_ON_CONSOLE) {
            cout << a << " " << b << " " << c << " " << d << endl;
        }
}


#endif //AI_CONNECT6_LOGUTILS_H
