#include "target.h"
#include <string>
using namespace std;
// static variable to keep track of global time in class Target
int Target::globalTime = 0;

// function to check if Target is a leaf or not
bool Target::isLeaf() const 
{
	return size == 0;
}

// function to add dependancy to the dependancy array of the current Target object
void Target::addDepend(Target *d) 
{
	bool isPresent = false; // boolean flag to indicate whether dependancy already exists or not
	for (int i = 0; i < size; ++i) // checks for already exists
	{
		if(d->name == targetDepends[i]->name)
		{
			isPresent = true;
		}
	}
	if (size == 10 && !isPresent) //checks to ensure that no more than 10 dependancies are added to the target object
	{
		out << "Max dependencies exceeded"<<endl;
	}
	else
	{
		targetDepends[size] = d;
		++size;
	}
}

// constructor for Target object
Target::Target(const string &name, ostream &out) : out{out}, name{name} 
{
	size = 0;
	time = 0;
}

// handles function call made by makefile on touch command
void Target::update(int timex) 
{
	globalTime = timex; //sets Target global time to be equal to makefile global time
	if(this->isLeaf()) // checks if it can be validly touched and then prints requirede statement
	{
		time = globalTime; //Targets own time becomes equal to global time
		out << this->name << " updated at time " << globalTime << endl;
	}
	else
	{
		out << "Cannot update non-leaf object" << endl;
	}
}

int Target::lastUpdated() const // function simply returns Target's time without modifying any of its fields
{
	return time;
}

// recursive helper function to iterate over dependancies and recursively build/not build each Target
int Target::recursiveDepends(int last_time, Target* target)
{
	// base case, checkf or time difference if the Target is a leaf
	if(target->isLeaf())
	{
		// returns current objects time if the recursion reaches the base case
		return target->time;
	}
	else
	{
		// iterates through the dependancies of the Target at hand
		for (int i = 0; i < target->size; ++i)
		{
			// recursive call to check if the dependancies need to be built
			if(recursiveDepends(target->time, target->targetDepends[i]) > target->time)
			{
				out << "Building " << target->name << endl;
				target->time = globalTime;
				return target->time;
			}
			else
			{
				return target->time;
			}		
		}

	}
	return 0;
}




void Target::build() 
{
	this->recursiveDepends(time, this);

}
