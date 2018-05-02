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

Integer::Integer(int value):value{value}{}
Integer::~Integer(){}

int Integer::evaluate()
{
	return value;
}

void Integer::prettyprint()
{
	cout << value;
}

