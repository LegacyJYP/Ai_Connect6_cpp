//
// Created by 박재영 on 2017. 5. 13..
//

#include <string>
#include <iostream>

#ifndef AI_CONNECT6_LOGUTILS_H
#define AI_CONNECT6_LOGUTILS_H

#endif //AI_CONNECT6_LOGUTILS_H

using  namespace std;

//void log(std::string s);
//void log(const char* s);
//void log(string s1, string s2);
//void log(const char* s1, const char* s2);
//void log(std::string s, bool printFlag);
//void log(const char* s, bool printFlag);
//void log(string s1, string s2, bool printFlag);
//void log(const char* s1, const char* s2, bool printFlag);

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

template <typename T1, typename T2, typename T3>
void loginfo(T1 a, T2 b, T3 c)
{
    cout << a << " " << b  << " " << c << endl;
}

template <typename T1, typename T2, typename T3, typename T4>
void loginfo(T1 a, T2 b, T3 c, T4 d)
{
    cout << a << " " << b << " " << c << " " << d << endl;
}