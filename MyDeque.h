/***************************************************************************
* AUTHOR			: TALON BAKER
* ASSIGNMENT # 4	: QUEUE DEQUE & VECTOR
* CLASS				: CS1D
* SECTION			: TTH - 5:30PM
* DUE DATE			: 2/17/15
**************************************************************************/
#ifndef MyDeque_H_
#define MyDeque_H_

#include <iostream>
using namespace std;

template <typename T>
struct node{
	T data;
	node<T> *next;
	node<T> *back;
};

//CLASS DEFINITION///////////////////////////////////////////////////////////
template <class T>
class MyDeque {
public:

//MUTATORS///////////////////////////////////////////////////////////////////

	//default constructor
	MyDeque();
	//default destructor
	virtual ~MyDeque();
	//pushes one item onto the inked list stack
	void insertBack(T data);
	//erases the first item on the queue
	void eraseFront();

//ACCESSORS//////////////////////////////////////////////////////////////////

	//return true if linked list is empty
	bool empty() const;
	//returns a string with every item in the linked list
	void print() const;
	//returns the item in the front of the list
	T front() const;
	//returns the current size of the linked-list
	int  size() const;
	//Add element at the end
	void push_back(T data);
	//Delete last element
	void pop_back();
	//Return iterator to beginning of the list
	T* begin() const;
	//Return iterator to the end of the list
	T* end() const;
//WRAPPERS///////////////////////////////////////////////////////////////////

	//wrapper for enqueue Queue method
	void enqueue(T data);
	//wrapper for dequeue Queue method
	void dequeue();

private:

	node<T> *head;		//holding the head of the deque
	node<T> *tail;		//holding the tail of the deque
	int dequeSize;		//holding the total number of nodes in the deque
	node<T> *iterator;	//holding the pointer to itorate through the list
};//end - class MyDeque

//METHOD DEFINITIONS/////////////////////////////////////////////////////////

//default constructor
template <typename T>
MyDeque<T>::MyDeque()
{
	head = NULL;
	tail = NULL;
	dequeSize = 0;
	iterator = NULL;
}//end - default construstor

//default destructor
template <typename T>
MyDeque<T>::~MyDeque() {}

//returns true if the linked list is empty
template <typename T>
bool MyDeque<T>::empty() const
{
	return head == NULL;
}//end - empty

//pushes one item onto the linked list
template <typename T>
void MyDeque<T>::insertBack(T item)
{
    node<T> *tempPtr;
    node<T> *newnode;

    tempPtr = head;

    newnode = new node<T>;
    newnode->data = item;
    newnode->next = NULL;
    newnode->back = NULL;

    //if list is empty, newnode is the only node
    if(empty())
    {
    	head = newnode;
    	tail = newnode;
    }
    //if list only has one node in it
    else if(tempPtr->next == NULL)
    {
    	head->next = newnode;
    	newnode->next = NULL;
    	newnode->back = head;
    	tail = head->next;
    }//END - else
    //if list has more than one node in it
    else
    {
    	tail->next = newnode;
    	newnode->back = tail;
    	newnode->next = NULL;
    	tail = tail->next;
    }

    dequeSize++;
}//END - push

//prints the contents of the deque
template <typename T>
void MyDeque<T>::print() const
{
	node<T> *current = head;
	if(empty())
	{
		cout << "The list is currently empty\n";
	}
	else
	{

		while(current != NULL)
		{
			//output data within set notation
			while(current != NULL)
			{
				cout << current->data;

				cout << endl;

				current = current->next;
			}
		}
	}
}//END - print

//returning the total number of nodes in the deque
template <typename T>
int MyDeque<T>::size() const
{
	return dequeSize;
}//end - size

//erasing the item in the front of the list
template <typename T>
void MyDeque<T>::eraseFront()
{
	node<T> *tempPtr = head;
	T dataReturn;

	if(!empty())
	{

		//if one node is on the stack
		if(tempPtr == tail)
		{
			delete tempPtr;
			head = NULL;
			tail = NULL;
		}//end - if
		else
		{
			node<T> *currPtr = head->next;
			dataReturn = tempPtr->data;
			delete tempPtr;
			head = currPtr;
			currPtr->back = NULL;
		}//end - else
	}//end - if
	else
	{
		cout << "Nothing to eraseFront\n\n";
	}

	dequeSize--;
}//end - eraseFront

//calling insert Back method
template <typename T>
void MyDeque<T>::enqueue(T data)
{
	insertBack(data);
}//enqueue

//calling erase front method
template <typename T>
void MyDeque<T>::dequeue()
{
	eraseFront();
}//end - dequeue

//returning the item in the front of the list
template<typename T>
T MyDeque<T>::front() const
{
	try
	{
		if(empty())throw true;

		return head->data;
	}
	catch(bool e)
	{
		return "Nothing in list. Nothing to return\n";
	}

}//end - front

//Add element at the end
template<typename T>
void MyDeque<T>::push_back(T data)
{
	insertBack(data);
}//end - push_back

//Delete last element
template<typename T>
void MyDeque<T>::pop_back()
{
	if(empty())
	{
		cout << "Nothing on the list to pop_ back\n\n";

	}
	else
	{
		if(head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			node<T> *holdPtr = tail->back;
			delete tail;
			tail = holdPtr;
			holdPtr->next = NULL;
		}
	}

}//end - pop_back

//Return iterator to beginning of the list
template<typename T>
T* MyDeque<T>::begin() const
{
	node<T> *headPtr = head;
	return headPtr;
}//end - begin

//Return iterator to the end of the list
template<typename T>
T* MyDeque<T>::end() const
{
	node<T> *tailPtr = tail;
	return tailPtr;
}//end - end

#endif /* MyDeque_H_ */
