// We can use multi level exits by making use of label variables to mark  exit points. 
// This can show the system the exit points at compile time.

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i=0;
	L1: i+=1;
	L2: if(i<=3){
		cout<<"Less"<<endl;
		goto L1;
	};
	cout<<"More"<<endl;
	return 0;
}

//Routine scope, cannot override by using same name for variables anywhere in the routine
