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
	if(size==10)
	{
		cout<<"Invalid test case"<<endl;
		exit(0);	
	}
	int i=0;
	while(i!=head)
	{
		if(headArray[i]==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(0);	
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
			exit(0);	
		}
		if(j==index)
		{
			break;
		}
		j++;
		curr=curr->next;
		
		
	}
	
	Node *n=new Node{data,curr,nullptr};
	if(curr->owner==nullptr)
	{
		headArray[head]=n;
		curr->owner=n;
		n->owns=curr;
	}
	else
	{
		headArray[size]=n;
		
		n->owns=nullptr;
	}
	

}

void mutateNode(Node **headArray, int head, int index, int newValue)
{
	int size=getSize(headArray);
	if(size==10)
	{
		cout<<"Invalid test case"<<endl;
		exit(0);	
	}
	int i=0;
	while(i!=head)
	{
		if(headArray[i]==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(0);	
		}
		i++;
	}
	// cout<<"head is at "<<(headArray[i])->data<<endl;
	int j=0;
	Node *curr;
	curr=headArray[i];
	// cout<<<<endl;
	while(true)
	{
		// cout<<"h"<<endl;
		if(curr==nullptr)
		{
			cout<<"Invalid test case"<<endl;
			exit(0);	
		}
		if(j==index)
		{
			break;
		}
		j++;
		curr=curr->next;
		// 
	}
	// cout<<curr->data<<endl;	
	curr->data=newValue;
}


void printNodes(std::ostream &out, Node **headArray, int head)
{
	int size=getSize(headArray);
	if (head>=size)
	{
		cout<<"Invalid test case"<<endl;
		exit(0);
	}

	// int i=0;
	// cout<<"here";
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
		// cout<<"deleting head "<<(headArray[i])->data<<endl;
		// Node *curr=headArray[i];
		// while(curr->next!=nullptr)
		// {
		// 	cout<<curr->data<<" ";
		// 	curr=curr->next;
		// }
		// cout<<""<<endl;
		// delete curr;
		delete headArray[i];
	}
	// delete[] headArray;
}
