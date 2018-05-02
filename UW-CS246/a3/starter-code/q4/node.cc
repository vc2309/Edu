#include <iostream>
#include "node.h"
using namespace std;

Node::Node():data{0}, next{nullptr}, owner{nullptr} {}
Node::Node(int d, Node *nxt): data{d}, next{nxt}, owner{nullptr} {}
Node::Node(int d, Node *nxt, Node *onr): data{d}, next{nxt}, owner{onr} {}

Node::~Node()
{
	owner=nullptr;
	if (next->owner==this)
	{
		delete next;
	}
	
}

Node & Node::operator=(const Node &other)
{
	data=other.data;
	next=other.next;
	owner=other.next;
}

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
		// cout<<curr->data<<endl;
		
	}
	// cout<<size<<"sz"<<endl;
	Node *n=new Node{data,curr,nullptr};
	if(curr->owner==nullptr)
	{
		headArray[head]=n;
		curr->owner=n;
	}
	else
	{
		headArray[size]=n;
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
		delete headArray[i];
	}
	delete[] headArray;
}
