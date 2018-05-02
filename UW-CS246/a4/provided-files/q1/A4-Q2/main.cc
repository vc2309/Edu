#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "expression.h"
#include "integer.h"
#include "unary.h"
#include "binary.h"

using namespace std;

int main()
{
	vector<Expression*>stackVector;
	cin.exceptions(ios::eofbit|ios::failbit);
	string readIn;
	while(true)
	{
		try
		{
			cin >> readIn;
			cin.exceptions(cin.eofbit);
			if(readIn == "+" || readIn == "-" || readIn == "*" || readIn == "/")
			{
				Expression* left = stackVector.back();
				stackVector.pop_back();
				Expression* right = stackVector.back();
				stackVector.pop_back();
                istringstream a{readIn};
                char z;
                a >> z;
                Expression* x = new Binary{z, left, right};
				stackVector.emplace_back(x);
			}
			else if(readIn == "ABS" || readIn == "NEG")
			{
				Expression* p = stackVector.back();
                Expression* x = new Unary{readIn, p};
				stackVector.emplace_back(x);
			}
			else
			{
				istringstream ss{readIn};
				int o;
				ss >> o;
                Expression* x = new Integer{o};
				stackVector.emplace_back(x);
			}
		}
		catch(ios::failure&)
		{
			break;
		}
	}
    Expression* eval = stackVector.back();
    eval->prettyprint();
    cout << endl;
    cout << "=" << ' ' << eval->evaluate() << endl;
	delete eval;
}