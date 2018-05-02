#ifndef _BINARY_H_
#define _BINARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "integer.h"
#include "unary.h"
#include "expression.h"

class Binary:public Expression
{
	char binaryType;
	Expression* left;
	Expression* right;
public:
	Binary(char x, Expression* a, Expression* b);
    ~Binary();
	void prettyprint();
	int evaluate();
};

#endif