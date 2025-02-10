#include"Linkedlist.h"





class ProcessLinkedlist:public LinkedList<Process*>
{
public:
	int totalreqtime;


	ProcessLinkedlist():LinkedList<Process*>()
	{
	
	totalreqtime=0;
	}



	bool removeid(int id,Process*& frntEntry)
{
	
	
		Node<Process*>* curPtr ;
		Process*p;
		if(!isEmpty())
		{
			for(int i=1;i<=itemcount;i++)
			{
		curPtr=getNodeAt(i);
		p=curPtr->getItem();

		if(p->getID()==id)
		{
		remove(i,frntEntry);
		return true;

		}
		
			}

		}
		return false;
}

void print()
{
	Node<Process*>* p = Head;
	Process*q;
			
			if(p!=nullptr)
			{
				
	           q= p->getItem();
			   cout<<q->getID();
			p= p->getNext();
			}
			while(p!=nullptr)
			{
				 q= p->getItem();
			  
	 
	cout<<" , "<<q->getID();
	p= p->getNext();
			}
		

}



bool remove(int pos,Process*& frntEntry)
{
	bool ableToRemove = (pos > 0) && (pos <= itemcount);
	if (ableToRemove)
	{
		Node<Process*>* curPtr = nullptr;
		if (pos == 1)
		{
			curPtr = Head;
			Head = Head->getNext();
		}
		else
		{
			Node<Process*>* prevptr = getNodeAt(pos - 1);
			curPtr = prevptr->getNext();
			prevptr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		/*delete curPtr;
		
		curPtr = nullptr;*/
		frntEntry=curPtr->getItem();
		itemcount--;
	}
	return ableToRemove;
}


bool removefirst(Process*& frntEntry)
{
	Process* a;
	bool can=remove(1,a);
	frntEntry=a;
	return can;
}







};



