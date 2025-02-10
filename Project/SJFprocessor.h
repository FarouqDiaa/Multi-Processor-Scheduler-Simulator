#pragma once
#include"Processor.h"
#include"Scheduler.h"
#include"Process.h"
#include"defs.h"
#include"SJFQueue.h"
class SJFprocessor:public Processor
{
private:
	SJQueue rdylist;
	//SJQueue temp;
public:
SJFprocessor(Scheduler* sh):Processor(sh)
{
	setType(SJF);
}

void addprocess(Process* p)
{
	if(p!=nullptr)
	{
	rdylist.enqueue(p);

	rdylist.totalreqtime+=p->getCpuTime()-p->getexcuted();

	readynum++;
	}
}

void peek(Process*& p)
{
	rdylist.peek(p);
}

void printRdyList()
{
	rdylist.print();
}


 void ScheduleAlgo()
{
	
	
	if(Running!=nullptr)
	{
		incrementbusy();
		Running->incrementexcuted();
		if (Running->getexcuted() == Running->getCpuTime())
		{
			psh->Completed(Running);

		}
		else if (Running->needio(neededio) != -1)
		{
			psh->IOHandling(Running, neededio);
		}
	}




	Process*p;
	if(Running==nullptr)
	{
		incrementidle();
		if(!rdylist.isEmpty())
		{
			rdylist.peek(p);
			if(p!=nullptr)
			{
	p=dequeueprocess();
	Running=p;
	if (p->getfirsttime())
	{
		p->setfirsttimeCPU(psh->gettime());
		p->setfirsttime();
	}
	
			}
		}
	
	}

	




};

 int  gettotalreq()
 {
 
 return rdylist.totalreqtime;
 
 }

Process* dequeueprocess()
{
	Process*p;
	rdylist.dequeue(p);
	rdylist.totalreqtime-=p->getCpuTime()-p->getexcuted();
	readynum--;
	return p;
}

bool removebyid(int id, Process*& p)
{
	return false;
}

void storeForked(Process* p)
{
	/*
	Process* q;

	this->dequeueprocess();
	temp.enqueue(p);
	this->peek(q);
	if (q && q->getForkedBefore())
		storeForked(q);
		*/
}

void restoreForked()
{
	/*
	Process* p = this->dequeueprocess();
	while (p)
	{
		temp.enqueue(p);
		p = this->dequeueprocess();
	}

	while (!temp.isEmpty())
	{
		temp.dequeue(p);
		this->addprocess(p);
	}
	*/
}

void incrementbusy()
{
	busytime++;
}
int getbusy()
{
	return busytime;
}

void incrementidle()
{
	idletime++;
}
int getidle()
{
	return idletime;
}
bool getpointerto(int id, Process*& p)
{
	return false;
}
bool TestingProbability()
{
	return false;
}
};