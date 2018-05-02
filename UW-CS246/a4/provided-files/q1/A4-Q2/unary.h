#ifndef _UNARY_H_
#define _UNARY_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "integer.h"
#include "binary.h"
#include "expression.h"

class Unary:public Expression
{
    std::string unaryType;
	Expression* operation;
public:
	Unary(std::string s, Expression* x);
	~Unary();
	void prettyprint();
	int evaluate();
};
#endif