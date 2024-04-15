
#ifndef INPOST_H
#define INPOST_H

#include <iostream>
using namespace std;

//function prototypes
string convert(const string& infix);
int precedence(char x);
bool isOperator(char x);

#endif
