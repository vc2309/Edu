#include <iostream>
using namespace std;

void pointers()
{
	int a=0;
	int *p=&a;
	cout<<p<<endl;
	p=&p; //Results in error because we can't have an int pointer point to a pointer, we need an int **, to point to a pointer
	cout<<p;
}
int main()
{
	pointers();
}