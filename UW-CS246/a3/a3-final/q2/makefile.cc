#include "makefile.h"
#include <iostream>
#include <string>
using namespace std;
// static variable which keeps track of global time
int Makefile::time = 0;
// constructor
Makefile::Makefile(ostream &out) : out{out} 
{
	numT = 0;
}
// destructor to dealloc each Target pointer in the allT
Makefile::~Makefile() 
{
	for (int x = 0; x < numT; ++x)
	{
		delete allT[x];
	}
}

// this function adds the dependancy to particular target and also stores
// it in the allT
void Makefile::addDepend(const string &t, const string &d) 
{
	int numFiles = 0; // keeps track of space needed by the files
	bool isT = false;
	bool isD = false;
	int ti = 0;
	int id = 0;
	int ctr=0;
	while(ctr<numT)
	{
		if (allT[ctr]->name == t)
		{
			ti = i; // stores index if target already exists
			isT = true; // flag saying target already exists
			numFiles++;
		}
		else if(allT[ctr]->name == d) 
		{
			id = i; // stores index if dependancy already exists
			isD = true; // flag saying dependancy already exists
			numFiles++;
		}
		ctr++;
	}
	// ensures that the max number of targets have not been reached
	if ((2 - numFiles) > (20 - numT))
	{
		out << "Max targets exceeded" << endl;
	}
	else
	{
		if(!isT)
		{
			// Target* tg = new Target(t, out); //new Target pointer to the heap
			allT[numT] = new Target(t, out);
			ti = numT; // adds it to end of allT
			numT += 1;
		}
		if(!isD)
		{
			// Target* depend = new Target(d, out); // new Target pointer to the heap
			allT[numT] = new Target(d, out); // adds it to end of allT
			id = numT;
			numT += 1;
		} 
		allT[ti]->addDepend(allT[id]); // makes call to add dependancy function 
	}
	
}

// this is the function which deals with the touch command
void Makefile::changeTarget(const string &t) 
{
	
	for (int i = 0; i < numT; i++)
	{
		if(allT[i]->name == t)
		{
			// call to Target function
			allT[i]->update(time);
		}
	}
	time++; // updates global clock regardless of success or failure
}

void Makefile::rebuild(const string &t) 
{
	// loops through the big array and if found, makes a build call on
	// Target pointer
	for (int i = 0; i < numT; i++)
	{
		if(allT[i]->name == t)
		{
			allT[i]->build(); //makes call to Target function	
		}
	}

}
