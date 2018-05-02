#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "integer.h"
#include "binary.h"
#include "unary.h"

using namespace std;



Unary::Unary(string s, Expression* x): unaryType{s}, operation{x}{}
Unary::~Unary()
{
	delete operation;
}

int Unary::evaluate()
{
	if(unaryType == "ABS")
	{
		if(operation->evaluate() < 0)
		{
			return -(operation->evaluate());
		}
		else
		{
			return operation->evaluate();
		}
	}
	else
	{
		return -(operation->evaluate());
	}
}

void Unary::prettyprint()
{
	if(unaryType == "ABS")
	{
		cout << '|';
        operation->prettyprint();
        cout << '|';
	} 
	else
	{
		cout << '-';
        operation->prettyprint();
	}
}
