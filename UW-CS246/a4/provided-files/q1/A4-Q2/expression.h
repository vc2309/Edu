#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
class Expression
{
public:
	virtual void prettyprint()=0;
	virtual int evaluate()=0;
	virtual ~Expression(){};
};
#endif