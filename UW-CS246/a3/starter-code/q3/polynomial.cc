#include "polynomial.h"
#include <iostream>
#include <sstream>
using namespace std;

Polynomial::Polynomial() 
{
	// coeffs=;
	capacity=-1;
}

Polynomial::~Polynomial()
{
	if(capacity>-1)
	{delete [] coeffs;
	}
}

Polynomial::Polynomial(const Polynomial &other): capacity{other.capacity}, coeffs{new Rational[capacity]}
{
	for (int i = 0; i < capacity; ++i)
	{
		coeffs[i]=other.coeffs[i];
	}
}

Polynomial::Polynomial(Polynomial &&other): capacity{other.capacity}, coeffs{other.coeffs}
{
	
	// for (int i = 0; i < capacity; ++i)
	// {
	// 	coeffs[i]=other.coeffs[i];
	// }
	other.coeffs=nullptr;
	// delete &other;
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
	if (this==&other)
	{
			return *this;
	}
	capacity=other.capacity;
	coeffs=new Rational[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		coeffs[i]=other.coeffs[i];
	}
}
Polynomial &Polynomial::operator=(Polynomial &&other)
{
	swap(capacity,other.capacity);
	swap(coeffs,other.coeffs);
	// delete &other;
	return *this;
}

Polynomial::Polynomial(const Rational &coeff, int exp): capacity{exp+1}, coeffs{new Rational[exp+1]}
{
	coeffs[0]=coeff;
}

Polynomial Polynomial::operator*(const Polynomial &rhs) const
{
	int cap=(this->capacity)+rhs.capacity-1;
	Polynomial prod;
	prod.capacity=cap;
	// delete []prod.coeffs;
	prod.coeffs=new Rational[cap];
	int lcap=this->capacity;
	int rcap=rhs.capacity;
	for(int x=0;x<cap;x++)
	{
		Rational z{0,1};
		prod.coeffs[x]=z;
	}
	int exp=0;
	for (int x = 0; x < lcap; x++)
	{	

		for (int j = 0; j < rcap; j++)
		{
			exp=(cap-((lcap-x-1)+(rcap-j-1))-1);
	
			
			(prod.coeffs[exp])+=(this->coeffs[x])*(rhs.coeffs[j]);
		}

	}

	return prod;

}

Polynomial Polynomial::operator/(const Polynomial &rhs) const
{
	Polynomial quot;
	Rational fact;
	Polynomial div;
	div=*this;
	while(div.capacity>=rhs.capacity)
	{
		fact=((div.coeffs)[0]/(rhs.coeffs)[0]);
		int exp=div.capacity-rhs.capacity;
		Polynomial pfact{fact,exp};
		quot=quot+pfact;
		div=div-(pfact*rhs);
	}
	// div.coeffs=nullptr;
	// delete &div;
	// delete &fact
	return quot;
}

Polynomial Polynomial::operator%(const Polynomial &rhs) const
{
	Polynomial q;
	q=(*this)/rhs;
	return ((*this)-(q*rhs));
}
Polynomial Polynomial::operator+(const Polynomial &rhs) const
{
	int cap= this->capacity >= rhs.capacity ? this->capacity : rhs.capacity;
	Polynomial sum;
	sum.coeffs = new Rational[cap];
	sum.capacity=cap;
	int dif=cap;
	for(int i=0;i<cap;i++)
	{
		dif=cap-i;
		if(dif<=(this->capacity) && dif<=(rhs.capacity))
		{
			sum.coeffs[i]=this->coeffs[(this->capacity)-dif] + rhs.coeffs[rhs.capacity-dif];
		}
		else if(dif<=(this->capacity) && dif>(rhs.capacity))
		{
			sum.coeffs[i]=this->coeffs[i];
		}
		else if(dif>(this->capacity) && dif<=(rhs.capacity))
		{
			sum.coeffs[i]=rhs.coeffs[i];
		}
		else{
			sum.coeffs[i]=0;
		}	
	}
	
	int j=0;
	while((sum.coeffs[j]).num==0)
	{
		j++;
	}
	if(j>0)
	{
		sum.capacity=sum.capacity-j;
		Polynomial tmp;
		tmp.capacity=sum.capacity;
		tmp.coeffs=new Rational[tmp.capacity];
		for (int i = 0; i < tmp.capacity; i++)
		{
			cout<<sum.coeffs[j+i]<<endl;
			tmp.coeffs[i]=sum.coeffs[j+i];
		}
		delete [] sum.coeffs;
		sum=tmp;
		// delete &tmp;
	}
	return sum;

}

Polynomial Polynomial::operator-(const Polynomial &rhs) const
{
	int cap= this->capacity >= rhs.capacity ? this->capacity : rhs.capacity;
	Polynomial sum;
	sum.coeffs = new Rational[cap];
	sum.capacity=cap;
	int dif=cap;
	for(int i=0;i<cap;i++)
	{
		dif=cap-i;
		if(dif<=(this->capacity) && dif<=(rhs.capacity))
		{
				sum.coeffs[i]=this->coeffs[(this->capacity)-dif] - rhs.coeffs[rhs.capacity-dif];
			
		}
		else if(dif<=(this->capacity) && dif>(rhs.capacity))
		{
			sum.coeffs[i]=this->coeffs[i];
		}
		else if(dif>(this->capacity) && dif<=(rhs.capacity))
		{
			sum.coeffs[i]=-rhs.coeffs[i];
		}
		else{
			sum.coeffs[i]=0;
		}
	}

	int j=0;
	
	while((sum.coeffs[j]).num==0)
	{
		j++;
	}
	if(j>0)
	{
		sum.capacity=sum.capacity-j;
		Polynomial tmp;
		tmp.capacity=sum.capacity;
		tmp.coeffs=new Rational[tmp.capacity];
		for (int i = 0; i < tmp.capacity; i++)
		{
			
			tmp.coeffs[i]=sum.coeffs[j+i];
		}
		delete [] sum.coeffs;
		sum=tmp;
		// delete &tmp;	
	}
	return sum;	
}

std::istream& operator>>(std::istream& in, Polynomial &poly)
{
  	Rational *temp;
	string inp;
	getline(in,inp);
	// cout<<inp<<endl;
	int cap=0;
	int i=0;
	int num,den;
	num=den=0;
	bool sized=false;
	int exp=0;
	while(i<inp.length())
	{
		exp=0;
		num=0;
		den=0;
		if(inp[i]==' ')
		{
			i++;
			continue;
		}
		if(!sized)
		{
			if(inp[i]=='-')
			{
				i++;
				while(inp[i]!='/' && i<inp.length())
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				num=-num;
				i++;
				// den=(inp[i]-'0');
		
			}
			else
			{	
				while(inp[i]!='/' && i<inp.length())
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				// num=inp[i]-'0';
				i++;
				
			}
			while(inp[i]!=' ' && i<inp.length())
			{
				den=(den*10)+(inp[i]-'0');
				i++;
			}
			i++;
			while(inp[i]!=' ' && i<inp.length())
			{
				// cout<<"its "<<inp[i];
				exp=(exp*10)+(inp[i]-'0');
				i++;
			}
			cap=exp+1;
			exp=cap;
			// cout<<"cap "<<cap<<endl;
			poly.capacity=cap;
			temp=new Rational[cap];
			sized=true;
		}

		else
		{
			if(inp[i]=='-')
			{
				i++;
				while(inp[i]!='/' && i<inp.length())
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				num=-num;
				i++;
			}
			else
			{	
				while(inp[i]!='/' && i<inp.length())
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				// num=inp[i]-'0';
				i++;
				
			}
			while(inp[i]!=' ' && i<inp.length())
			{
				den=(den*10)+(inp[i]-'0');
				i++;
			}
			i++;
			while(inp[i]!=' ' && i<inp.length())
			{
				// cout<<"its "<<inp[i];
				exp=(exp*10)+(inp[i]-'0');
				i++;
			}
			exp++;
		}
		i++;
		Rational rat{num,den};
		temp[cap-exp]=rat;
		// delete &rat;
	}
	// delete [] poly.coeffs;
	// poly.coeffs=new Rational[poly.capacity];
	poly.coeffs=temp;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial &poly)
{
	int cap=poly.capacity;
	if(cap==-1){
		out<<0;
	}
	for(int i=0;i<(cap);i++)
	{
		if ((poly.coeffs[i]).num!=0)
		{
			
			if (i!=0)
			{
				out<<" + ";
			}
			out<<"("<<poly.coeffs[i]<<")";
			
			if(cap-i>2)
			{
				out<<"x^"<<(cap-(i+1));
				
			}
			else if (cap-i==2)
			{
				out<<"x";
				
			}
		}	
		// else if(cap==-1)
		// 	{
				
		// 		out<<0;
				
		// 	}	
	}
	return out;
}