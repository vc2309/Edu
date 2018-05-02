#ifndef _INTEGER_H_
#define _INTEGER_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "binary.h"
#include "unary.h"
#include "expression.h"

class Integer:public Expression
{
	int value;
public:
	Integer(int value);
	~Integer();
	void prettyprint() override;
    int evaluate() override;
};

#endif
