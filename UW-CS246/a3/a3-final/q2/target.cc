#include "target.h"
#include <string>
using namespace std;

int Target::statT = 0; //This is the static time variable

//Parameterized constructor
Target::Target(const string &name, ostream &out) : out{out}, name{name}, numD{0}, time{0} {}

bool Target::isLeaf() const 
{
	return (numD == 0); //If no dependencies are attached, it is a leaf
}

void Target::addDepend(Target *d)  //Adds a new dependency file
{
	bool exists = false; 
	for (int i = 0; i < numD; ++i) 
	{
		if(d->name == allD[i]->name)
		{
			exists = true;	//If the file is already part of the targets dependency list
		}
	}
	if (numD < 10 ) 	//Check to see if another dep can be added
	{
		if (!exists)
		{
			allD[numD] = d;
			++numD;
		}
	}
	else
	{
		if (!exists)	//If the dependency is already there, we dont print error
		{
			out << "Max dependencies exceeded"<<endl;
		}
	}
}

void Target::update(int t) 
{
	statT = t; 
	if(numD>0) //check for non-leaf target
	{
		out << "Cannot update non-leaf object" << endl;
	}
	else
	{
		time = statT; 
		out << name << " updated at time " << statT << endl;
	}
	
}

int Target::lastUpdated() const
{
	return time;
}

int Target::buildHelper(Target* t) //Recursive helper fxn to explore dependency graph
{
	//This fxn goes down all dependency paths in a recursive manner to make 
	//sure any updates in a dependency are acknowledged and build the file again
	if(t->numD==0)
	{
		return t->time;
	}

	for (int i = 0; i < t->numD; ++i)
	{
		// out<<(t->allD[i])->name<<endl;
		if(buildHelper(t->allD[i]) > t->time) //If target is not up to date
		{
			t->time = statT;
			out << "Building " << t->name << endl;
			return t->time;
		}
			
	}

	return 0;
}

void Target::build() 
{
	// out<<name<<endl;
	// out << "Building " << name << endl;
	this->buildHelper(this);
}
