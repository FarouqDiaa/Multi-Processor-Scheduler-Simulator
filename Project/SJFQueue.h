#include"ProcessQueues.h"


class SJQueue:public ProcessQueue
{

public:
	void enqueue( Process*& newEntry)
	{
	

	Node<Process*>* newNodePtr = new Node<Process*>(newEntry);

	Node<Process*>* prePtr=frontPtr;
	Node<Process*>* curPtr=frontPtr;


	// Insert the new node
	if (isEmpty())
		{//special case if this is the first node to insert
		frontPtr = newNodePtr; 
		backPtr = newNodePtr;
	}
	else
	{
		
		if((curPtr->getItem())->getCpuTime()>= (newNodePtr->getItem())->getCpuTime())
		{
			prePtr=frontPtr;
		frontPtr = newNodePtr;
			
			newNodePtr->setNext(prePtr);
		
		}
		else
		{
			curPtr=curPtr->getNext();
		while(curPtr)
		{
		if((curPtr->getItem())->getCpuTime()>= (newNodePtr->getItem())->getCpuTime())
		{
		prePtr->setNext(newNodePtr);
		newNodePtr->setNext(curPtr);
		return;
		
		}
		else
		{
		prePtr=prePtr->getNext();
		curPtr=prePtr->getNext();
		
		}
		
		}
		prePtr->setNext(newNodePtr);
		backPtr=newNodePtr;
		return;
		
		}
	
	}
		// New node is the last node now
	
} // end enqueue
	
	
	
	
	
	};


