#include "rational.h"
#include <iostream>
#include <sstream>
using namespace std;

Rational::Rational(int num, int den): num{num}, den{den} {}

int gcd(int a,int b)
{
	if (b==0) 
	{
		return a;
	}
	gcd(b,a%b);
}

void Rational::simplify()
{
	int a=this->num;
	int b=this->den;
	a=a<0? -a : a;
	b=b<0? -b : b;
	int d;
	d= a>b? gcd(a,b) : gcd(b,a);
	a= this->num/d;
	b= this->den/d;
	if((a<0 && b<0) || b<0){
		a=-a;
		b=-b;
	}
	
	this->num=a;
	this->den=b;
}

Rational Rational::operator+(const Rational &rhs) const{
	int n,d;
	n=d=0;
	d=this->den*rhs.den;
	n=this->num*rhs.den + this->den*rhs.num;
	Rational sum{n,d};
	sum.simplify();
	return sum;
}

Rational Rational::operator-(const Rational &rhs) const
{
	int n,d;
	n=d=0;
	d=this->den*rhs.den;
	n=this->num*rhs.den - this->den*rhs.num;
	Rational diff{n,d};
	diff.simplify();
	return diff;
}

Rational Rational::operator*(const Rational &rhs) const
{
	int n,d;
	n=d=0;
	d=this->den*rhs.den;
	n=this->num*rhs.num;
	Rational prod{n,d};
	prod.simplify();
	return prod;
}

Rational Rational::operator/(const Rational &rhs) const
{
	Rational reci{rhs.den,rhs.num};
	Rational lhs{this->num,this->den};
	return (lhs*reci);
}

Rational & Rational::operator+=(const Rational &rhs)
{
	int n,d;
	n=d=0;
	d=this->den*rhs.den;
	n=this->num*rhs.den + this->den*rhs.num;
	this->num=n;
	this->den=d;
	simplify();
}

Rational Rational::operator-() const
{   
	Rational neg{-(this->num),this->den};
	neg.simplify();
	return neg;
}

int Rational::getNumerator() const
{
	return this->num;
}

int Rational::getDenominator() const
{
	return this->den;
}

bool Rational::isZero() const
{
	return ((this->num)==0);
}

bool Rational::operator==(const Rational &rhs) const
{
	return((this->num==rhs.num)&&(this->den==rhs.den));
}

bool Rational::operator!=(const Rational &rhs) const
{
	return !((this->num==rhs.num)&&(this->den==rhs.den));
}

Rational & Rational::operator-=(const Rational &rhs)
{
	int n,d;
	n=d=0;
	d=this->den*rhs.den;
	n=this->num*rhs.den - this->den*rhs.num;
	this->num=n;
	this->den=d;
	simplify();
}




std::ostream &operator<<(std::ostream &out, const Rational &rat)
{	
	if (rat.num==0)
	{
		out<<0;
	}
	else if(rat.den==1)
	{
		out<<rat.num;
	}
	else
	{	
		out<<rat.num<<"/"<<rat.den;
	}		
	return out;
}

std::istream &operator>>(std::istream &in, Rational &rat)
{
	int num; int den;char c;
	in>>num>>c>>den;
	rat.num=num;
	rat.den=den;
	rat.simplify();
	return in;
}

