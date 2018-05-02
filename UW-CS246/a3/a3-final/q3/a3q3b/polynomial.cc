#include "polynomial.h"
#include <iostream>
#include <sstream>
using namespace std;

//Default constructor
Polynomial::Polynomial() 
{
	
	capacity=-1;
}

//Destructor
Polynomial::~Polynomial()
{
	if(capacity>-1)	//Checks if space has been allocated to the object's array
	{
		delete [] coeffs;
	}
}

//Copy constructor
Polynomial::Polynomial(const Polynomial &other): capacity{other.capacity}, coeffs{new Rational[capacity]}
{
	for (int i = 0; i < capacity; ++i)
	{
		coeffs[i]=other.coeffs[i];
	}
}

//Move constructor
Polynomial::Polynomial(Polynomial &&other): capacity{other.capacity}, coeffs{other.coeffs}
{
	other.coeffs=nullptr;	
}

//Copy assignment operator
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

//Move assignment operator
Polynomial &Polynomial::operator=(Polynomial &&other)
{
	swap(capacity,other.capacity);
	swap(coeffs,other.coeffs);
	return *this;
}

//Monomial constructor
Polynomial::Polynomial(const Rational &coeff, int exp): capacity{exp+1}, coeffs{new Rational[exp+1]}
{
	coeffs[0]=coeff;
}

//Multiplication operator
Polynomial Polynomial::operator*(const Polynomial &rhs) const
{
	int cap=(this->capacity)+rhs.capacity-1; //Calculates the maximum required exponent and capacity for product
	
	Polynomial prod;	//Object for product
	prod.capacity=cap;
	prod.coeffs=new Rational[cap];	
	
	int lcap=this->capacity;	//LHS capacity
	int rcap=rhs.capacity;		//RHS capacity
	
	for(int x=0;x<cap;x++)		//Initializing each coefficient to 0
	{
		Rational z{0,1};
		prod.coeffs[x]=z;
	}

	int exp=0;
	for (int x = 0; x < lcap; x++)
	{	
		for (int j = 0; j < rcap; j++)
		{
			exp=(cap-((lcap-x-1)+(rcap-j-1))-1);					//Calculating exponent of calculated term		
			(prod.coeffs[exp])+=(this->coeffs[x])*(rhs.coeffs[j]);	//Incrementing the coefficient of the current exponent
		}

	}

	return prod;

}

Polynomial Polynomial::operator/(const Polynomial &rhs) const
{
	Polynomial quot;	//Object for the quotient
	Rational fact;		//Object to calculate the multiplying factor at each iteration
	Polynomial div;		//Object to store dividend
	div=*this;

	while(div.capacity>=rhs.capacity) //Loop keeps dividing while the degree of the divisor is >= the degree of the dividend (avoids negative exponent)
	{
		fact=((div.coeffs)[0]/(rhs.coeffs)[0]);	//Calculate multiplying factor
		int exp=div.capacity-rhs.capacity;		//Calculate next highest exponent
		Polynomial pfact{fact,exp};				//Create a monomial for operations
		quot=quot+pfact;						//Increment quotient
		div=div-(pfact*rhs);					//Update dividend
	}
	
	return quot;
}

//The modulo operator
Polynomial Polynomial::operator%(const Polynomial &rhs) const
{
	Polynomial q;
	q=(*this)/rhs;		//Uses the divide operator to get quotient
	return ((*this)-(q*rhs));	//Returns the remainder
}

//The addition operator
Polynomial Polynomial::operator+(const Polynomial &rhs) const
{
	int cap= this->capacity >= rhs.capacity ? this->capacity : rhs.capacity;
	//The maximum degree for the sum Polynomial will be max(lhs degree, rhs degree)

	Polynomial sum;
	sum.coeffs = new Rational[cap];
	sum.capacity=cap;


	int dif=cap;// Difference in degrees

	for(int i=0;i<cap;i++)
	{
		dif=cap-i;

		//the following logic decides how to calculate the coefficient of the current exponent
		//depending on whether the rhs and lhs have coefficients corresponding to the current
		//degree

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
		else
		{
			sum.coeffs[i]=0;
		}	
	}
	
	//Following logic is used to resize the sum object's array if the degree exponent has 
	// a coefficient of O
	int j=0;
	while((sum.coeffs[j]).num==0)
	{
		j++;	//Increments until the first non-zero coefficient is found
	}


	if(j>0)
	{
		sum.capacity=sum.capacity-j;
		Polynomial tmp;
		tmp.capacity=sum.capacity;
		tmp.coeffs=new Rational[tmp.capacity];	//New object of updated capacity

		for (int i = 0; i < tmp.capacity; i++)
		{
			cout<<sum.coeffs[j+i]<<endl;
			tmp.coeffs[i]=sum.coeffs[j+i];
		}
		delete [] sum.coeffs;	//Free memory pointed to by original object
		sum=tmp;
		
	}
	return sum;

}

//The subtraction operator uses the same logic as the addition operator
//however the addition is replaced with subtraction
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

//Input operator
std::istream& operator>>(std::istream& in, Polynomial &poly)
{
  	Rational *temp;
	string inp;
	getline(in,inp);
	
	int cap=0;	//Variable to store capacity of Polynomial
	int i=0;

	int num,den;
	num=den=0;		//Variables to store numerator and denominators of coeffs

	bool sized=false;	//Flag variable to indicate whether the array has been allocated space
	
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
		if(!sized)		//This block takes in the first term (coefficient and exponent)
		{
			if(inp[i]=='-')		//If exponent is negative
			{
				i++;
				while(inp[i]!='/' && i<inp.length())	//Separator between numerator and denominator
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				num=-num;
				i++;
				
		
			}
			else
			{	
				//Loop to obtain numerator
				while(inp[i]!='/' && i<inp.length())	//Separator between numerator and denominator
				{
					num=(num*10)+(inp[i]-'0');
					i++;
				}
				
				i++;
				
			}
			//Loop to obtain denominator
			while(inp[i]!=' ' && i<inp.length())
			{
				den=(den*10)+(inp[i]-'0');
				i++;
			}
			i++;

			//Loop to obtain exponent
			while(inp[i]!=' ' && i<inp.length())
			{
				
				exp=(exp*10)+(inp[i]-'0');
				i++;
			}
			cap=exp+1;
			exp=cap;
			
			poly.capacity=cap;			//Set the capacity of the object
			temp=new Rational[cap];		//The object array is initialized
			sized=true;					//Flag is set
		}

		//The same logic is applied for the remaining terms after the array has been allocated
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
				
				exp=(exp*10)+(inp[i]-'0');
				i++;
			}
			exp++;
		}
		i++;
		//New Rational object is created
		Rational rat{num,den};
		//Object is inserted into array
		temp[cap-exp]=rat;
		
	}
	
	poly.coeffs=temp; //The poly objects array is assigned with the temp array
	return in;
}

//Output operator
std::ostream& operator<<(std::ostream& out, const Polynomial &poly)
{
	int cap=poly.capacity;
	if(cap==-1)
	{
		out<<0;	//For a zero polynomial
	}

	for(int i=0;i<(cap);i++)
	{
		if ((poly.coeffs[i]).num!=0)
		{
			
			if (i!=0)	//Non first term
			{
				out<<" + ";
			}
			out<<"("<<poly.coeffs[i]<<")";
			
			if(cap-i>2)	// x^i printed for all exponents greater than 1
			{
				out<<"x^"<<(cap-(i+1));
				
			}
			else if (cap-i==2) // x is printed instead of x^1
			{
				out<<"x";
				
			}
		}	
			
	}
	return out;
}
