#pragma once
#include "Node.h"
#include"Process.h"
template <class T>
class LinkedList
{
protected:
	Node<T>* Head;

	int itemcount;
public:
	LinkedList();
	~LinkedList();
	bool insert(const T& newData,int pos);
	void insertlast(const T& newData);
	
	bool remove(int pos);
	bool isEmpty();
	Node<T>* getNodeAt(int pos)const;
	void print();
	Node<T>* removeid(int);
	

};

template<class T>
LinkedList<T> ::LinkedList()
{
	Head = nullptr;
	itemcount = 0;
}

template<class T>
Node <T>* LinkedList<T> ::getNodeAt(int pos) const
{
	if ((pos >= 1) && (pos <= itemcount))
	{
		Node<T>* cuptr = Head;
		for (int i = 1; i < pos; i++)
		{
			if(cuptr)
			{
			cuptr = cuptr->getNext();
			}
		}
		return cuptr;
	}
	return nullptr;
}

template<class T>
bool LinkedList<T>::insert(const T& newEntry, int pos)
{
	bool ableToInsert = (pos > 0) && (pos <= itemcount+1);
	Node<T>* newNodePtr = new Node<T>(newEntry);
	if (pos == 1)
	{
		newNodePtr->setNext(Head);
		Head = newNodePtr;
			itemcount++;
	}
	else if(ableToInsert)
	{
		Node<T>* prevptr = getNodeAt(pos - 1);
		newNodePtr->setNext(prevptr->getNext());
		//wrong
		
		prevptr->setNext(newNodePtr);
			itemcount++;
		
	}
	
	return ableToInsert;
}



template<class T>
bool LinkedList<T>::isEmpty()
{
	return(itemcount == 0);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	while (!isEmpty())
		remove(1);
}

template<class T>
bool LinkedList<T>:: remove(int pos)
{
	bool ableToRemove = (pos > 0) && (pos <= itemcount);
	if (ableToRemove)
	{
		Node<T>* curPtr = nullptr;
		if (pos == 1)
		{
			curPtr = Head;
			Head = Head->getNext();
		}
		else
		{
			Node<T>* prevptr = getNodeAt(pos - 1);
			curPtr = prevptr->getNext();
			prevptr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		delete curPtr;
		
		curPtr = nullptr;
		
		itemcount--;
	}
	return ableToRemove;
}




/*void insertlast(const T& newData);
	bool removefirst(T& frntEntry);*/
template<class T>
void LinkedList<T> ::insertlast(const T& newData) 
{
	
	insert(newData,itemcount+1);
}
/*template<class T>
void LinkedList<T> ::insertlast(const T& newData) 
{
	insert(newData,itemcount);
}*/
