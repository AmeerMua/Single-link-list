#include"Linklist.h"
#include<iostream>

using namespace std;
//////////////////////////////////////////// Node Class ////////////////////////////////////////////

Node::Node()
{
	data=-1;
	next=NULL;
	

}
Node::Node(int data)
{
	this-> data= data;
	next=NULL;
	

}
void Node::setData(int Data)
{
	this-> data= data;
}
void Node::setNext(Node *next )
{
	this-> next= next;
}

int Node::getData(){

		return data;
}

Node* Node::getNext(){

		return next;
}
//...........................Link list imp.......................................

Linklist::Linklist()
{
	head=NULL;
	tail=NULL;

}
bool Linklist::isEmpty()
{
	if (head== NULL)
	{
		return true;
	
	}
	else
	{
		return false;
	
	}

}
void Linklist::insertAtTail(int data)
{
	if (isEmpty())
	{ // new banane ka liye
		Node *temp= new Node(data);
		head= temp;
		tail= temp;
	}
	else
	{ //insert karna ka liye
		Node *temp= new Node(data);
		tail->setNext (temp);
		tail= temp;
	}

}
void Linklist::insertAtHead(int data)
{
	if (isEmpty())
	{ 
		insertAtTail(data);
	}
	// create new node "Temp" in head
	else
	{
		Node* temp = new Node(data);
		temp->setNext (head);
		head = temp;

	}

}
void Linklist::display()
{
	Node* temp= head;
	
	while (temp != NULL)
	{
		cout<<temp->getData()<<"\t";
		temp = temp->getNext();
	}

}
Node* Linklist::searchtarget(int toFind )
{
	Node* temp = head;
	// ager for loop sa karna ha to
	//for (temp ; temp!=NULL ; temp= temp->getNext())
	while ( temp !=NULL)
	{
		if (temp->getData() == toFind)
		{
			return temp;
		
		}
	        temp = temp->getNext();
	}
	return NULL;
}
void Linklist::insertAtTarget(int target ,int value)
{
	
	if (isEmpty())
		
	{
		cout <<"List is empty"<<endl;
		return;
	}
	else
	{
		Node* targetNode = searchtarget(target);
		if (targetNode==NULL)
		{
			cout<<"Not found"<<endl;
			return;
		}
		else
		{
			if( targetNode == tail)
			{
				insertAtTail(value);
			}
			else
			{
			Node* temp = new Node(value);
			temp->setNext (targetNode ->getNext());
			targetNode->setNext(temp);			
			}
		}
	}

}
void Linklist::removeNode (int Delete)
{
	Node* targetNode = head;
	Node* prev = NULL;

	while(targetNode != NULL)	
	{
		if (targetNode->getData() == Delete)
		{
			break;
		}
	else
		{
			prev= targetNode;
			targetNode = targetNode->getNext();

		}
	}
	if (targetNode== NULL)
	{
		cout<<"NOT found"<<endl;
		return;
	}
	else
	{
	if (targetNode == head)
	{
		head = head ->getNext();
		targetNode ->setNext (NULL); // yeh wali line delink kare giy
		delete targetNode;
	}
	else if (targetNode == tail)
	{
		tail = prev;
		tail->setNext(NULL);
		delete targetNode;
	
	}
	else
	{
		prev ->setNext(targetNode->getNext());
		targetNode->setNext(NULL);
		delete targetNode;
		
	}
}

}
