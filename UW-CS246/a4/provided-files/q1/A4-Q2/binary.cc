#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "integer.h"
#include "binary.h"
#include "unary.h"
#include "expression.h"

using namespace std;



Binary::Binary(char x, Expression* a, Expression* b): binaryType{x}, left{a}, right{b} {}

Binary::~Binary()
{
	delete left;
	delete right;
}


int Binary::evaluate()
{
	if(binaryType == '+')
	{
		return left->evaluate() + right->evaluate();
	} 
	else if(binaryType == '-')
	{
		return right->evaluate() - left->evaluate();
	}
	else if(binaryType == '/')
	{
		return right->evaluate() /  left->evaluate();
	}
	else
	{
		return left->evaluate() * right->evaluate();
	}
}


void Binary::prettyprint()
{
	cout << "(";
    right->prettyprint();
    cout << ' ' << binaryType << ' ';
    left->prettyprint();
    cout << ')';
}

