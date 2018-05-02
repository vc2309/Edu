#include "makefile.h"
#include <iostream>
#include <string>
using namespace std;
// static variable which keeps track of global time
int Makefile::virtual_time = 0;
// constructor
Makefile::Makefile(ostream &out) : out{out} 
{
	bigArray_size = 0;
}
// destructor to dealloc each Target pointer in the bigArray
Makefile::~Makefile() 
{
	for (int x = 0; x < bigArray_size; ++x)
	{
		delete bigArray[x];
	}
}

// this function adds the dependancy to particular target and also stores
// it in the bigArray
void Makefile::addDepend(const string &t, const string &d) 
{
	int spacereqd = 0; // keeps track of space needed by the files
	bool isTarget = false;
	bool isDepend = false;
	int index_target = 0;
	int index_d = 0;
	for(int i = 0; i < bigArray_size; ++i)
	{
		if (bigArray[i]->name == t)
		{
			index_target = i; // stores index if target already exists
			isTarget = true; // flag saying target already exists
			++spacereqd;
		}
		else if(bigArray[i]->name == d) 
		{
			index_d = i; // stores index if dependancy already exists
			isDepend = true; // flag saying dependancy already exists
			++spacereqd;
		}
	}
	// ensures that the max number of targets have not been reached
	if ((2 - spacereqd) > (20 - bigArray_size))
	{
		out << "Max targets exceeded" << endl;
	}
	else
	{
		if(!isTarget)
		{
			Target* target = new Target(t, out); //new Target pointer to the heap
			bigArray[bigArray_size] = target;
			index_target = bigArray_size; // adds it to end of bigArray
			bigArray_size += 1;
		}
		if(!isDepend)
		{
			Target* depend = new Target(d, out); // new Target pointer to the heap
			bigArray[bigArray_size] = depend; // adds it to end of bigArray
			index_d = bigArray_size;
			bigArray_size += 1;
		} 
		bigArray[index_target]->addDepend(bigArray[index_d]); // makes call to add dependancy function 
	}

}


// this is the function which deals with the touch command
void Makefile::changeTarget(const string &t) 
{
	++virtual_time; // updates global clock regardless of success or failure
	for (int l = 0; l < bigArray_size; ++l)
	{
		if(bigArray[l]->name == t)
		{
			// call to Target function
			bigArray[l]->update(virtual_time);
		}
	}
}

// deals with the make call
void Makefile::rebuild(const string &t) 
{
	// loops through the big array and if found, makes a build call on
	// Target pointer
	for (int l = 0; l < bigArray_size; ++l)
	{
		if(bigArray[l]->name == t)
		{
			bigArray[l]->build(); //makes call to Target function	
		}
	}

}
