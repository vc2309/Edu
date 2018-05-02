#include "rational.h"

int gcd(int a,int b){
	if b==0;
	return a;
	gcd(b,a%b);
}

void Rational::simplify(){

	int a=this->num;
	int b=this->den;
	int d;
	d= a>b? gcd(a,b) : gcd(b,a);
	this->num=a%d;
	this->den=b%d;
}