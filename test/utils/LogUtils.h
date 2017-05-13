//
// Created by 박재영 on 2017. 5. 13..
//

#include <string>

#ifndef AI_CONNECT6_LOGUTILS_H
#define AI_CONNECT6_LOGUTILS_H

#endif //AI_CONNECT6_LOGUTILS_H

using  namespace std;

void log(std::string s);
void log(const char* s);
void log(string s1, string s2);
void log(const char* s1, const char* s2);
void log(std::string s, bool printFlag);
void log(const char* s, bool printFlag);
void log(string s1, string s2, bool printFlag);
void log(const char* s1, const char* s2, bool printFlag);
void nln();