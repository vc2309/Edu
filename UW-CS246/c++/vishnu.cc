#include <iostream>
using namespace std;

struct vishnu
{
	int a=12;
	int b;
	vishnu(int x=10,int y=0){a=x;b=y;}
};

int main(int argc, char const *argv[])
{
	vishnu v;
	cout<<v.a<<endl;
	v.a=52;
	cout<<v.a<<endl;
	return 0;
}