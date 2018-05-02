#include <iostream>
#include "node.h"
using namespace std;

//Default constructor for a node
Node::Node():data{0}, next{nullptr}, owner{nullptr}, owns{nullptr} {}

//Basic constructor to facilitate initializations made through user input in main function
Node::Node(int d, Node *nxt): data{d}, next{nxt}, owner{nullptr}, owns{nullptr} {}

//More comprehensive constructor to initialize newly created Node before placement 
Node::Node(int d, Node *nxt, Node *onr): data{d}, next{nxt}, owner{onr}, owns{nullptr} {}

//Destructor
Node::~Node()
{
		//Freeing the associated pointers
		next=nullptr;	
		owner=nullptr;

		//Deletion only of node owned by this
		if (owns!=nullptr)
		{
			delete owns;
		}
	
}

//Assignment operator
Node & Node::operator=(const Node &other)
{
	data=other.data;
	next=other.next;
	owner=other.next;
	owns=other.owns;
}

//Standalone fxn to return current size of headArray for ease of computing
int getSize(Node **headArray)
{
	int i=0;
	while(true)
	{
		i++;
		if(headArray[i]==nullptr)
		{
			return i;
		}
	}
}

void attachNode(Node **headArray, int head, int index, int data)
{
	int size=getSize(headArray);
	if(size==10) //Size limit reached
	{
		cout<<"Invalid test case"<<endl;
		exit(-1);	
	}
	int i=0;
	while(i!=head)
	{
		if(headArray[i]==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(-1);	
		}
		i++;
	}
	
	int j=0;
	Node *curr;
	curr=headArray[i];
	
	while(true) //While loop to reach selected index of current head
	{
		
		if(curr==nullptr) 
		{
			cout<<"Invalid test case"<<endl;
			exit(-1);	
		}
		if(j==index)
		{
			break;
		}
		j++;
		curr=curr->next;
		
		
	}
	
	//Newly inserted node
	Node *n=new Node{data,curr,nullptr};

	if(curr->owner==nullptr) //Checks if node to point to has no current owner
	{
		headArray[head]=n; //Set new node as new head of this link
		curr->owner=n; //Set next nodes owner to new node
		n->owns=curr;// Set next node as owned node of new node
	}
	else
	{
		headArray[size]=n; //If node has an owner, new node is a new head for a new branch
		n->owns=nullptr; 
	}
	

}

void mutateNode(Node **headArray, int head, int index, int newValue)
{
	//Same logic applied to reach target node
	int size=getSize(headArray);
	if(size==10)
	{
		cout<<"Invalid test case"<<endl;
		exit(-1);	
	}
	int i=0;
	while(i!=head)
	{
		if(headArray[i]==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(-1);	
		}
		i++;
	}
	
	int j=0;
	Node *curr;
	curr=headArray[i];
	
	while(true)
	{
		
		if(curr==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(-1);	
		}
		if(j==index)
		{
			break;
		}
		j++;
		curr=curr->next;
		
	}
	
	//Data of target node is  modified
	curr->data=newValue;
}


void printNodes(std::ostream &out, Node **headArray, int head)
{
	int size=getSize(headArray);
	if (head>=size) //If an invalid head is requested
	{
		cout<<"Invalid test case"<<endl;
		exit(-1);
	}

	
	Node *curr=headArray[head];
	while(curr!=nullptr)
	{
		out<<curr->data<<" ";
		curr=curr->next;
	}
	out<<""<<endl;
}

void freeLists(Node **headArray)
{
	int size=getSize(headArray);

	for (int i = 0; i < size; ++i)
	{
		//Deleting each Node
		delete headArray[i];
	}
	
}

