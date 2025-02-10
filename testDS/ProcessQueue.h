#pragma once
#include"LinkedQueue.h"

class ProcessQueue :public LinkedQueue<Process*>
{
public:
	void print()
	{
	Node<Process*>* p = frontPtr;
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


};
