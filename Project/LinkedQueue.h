#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#pragma once

#include "Process.h"
#include "Node.h"

#include <vector>
using namespace std;


///////////////////////
template<class ItemType>
class QueueADT
{
public:
   /** Sees whether this queue is empty.
    @return  True if the queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the back of this queue.
    @post  If the operation was successful, newEntry is at the
       back of the queue.
    @param newEntry  The object to be added as a new entry.
    @return  True if the addition is successful or false if not. */
   virtual bool enqueue(const ItemType& newEntry) = 0;
   
   /** Copies the front item of the queue to the passed parameter and removes it from queue
    @post  If the operation was successful, the front of the queue
       would be copied to FrontEntry parameter and removed from the queue.
    @return  True if the removal is successful or false if not. */
   virtual bool dequeue(ItemType& FrontEntry) = 0;
   
   /** Copies the front item of the queue to the passed parameter without removing it from queue
    @pre  The queue is not empty.
    @post  The front of the queue has been copied to FrontEntry param , and the
       queue is unchanged.
    @return  The front of the queue. */
   virtual bool peek(ItemType& FrontEntry) const = 0;
   
   /** Destroys this queue and frees its memory. */
   virtual ~QueueADT() { }
}; // end QueueADT





#pragma once
////////////////////
template <typename T>
class LinkedQueue:public QueueADT<T>
{
protected :
	
	Node<T>* backPtr;
	 Node<T>* frontPtr;
public :
	LinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry)  const;	
	  void print();
	
	~LinkedQueue();


	//copy constructor
	LinkedQueue(const LinkedQueue<T> & LQ);
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr ;	
		
	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
/*
Function: destructor
removes all nodes from the queue by dequeuing them
*/
template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;
	
	//Free (Dequeue) all nodes in the queue
	while(dequeue(temp));	
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy, 
copy constructor is provided

Input: LinkedQueue<T>: The Queue to be copied
Output: none
*/

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T> & LQ)
{	
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}	
}



















#endif