#pragma once 
#include<iostream>
#include"defs.h"
#include "Pairs.h"
#include "LinkedQueue.h"
using namespace std;








class Process{
private:
int PID;
int ArrivalTime;
int CpuTime;
int totalexcuted;
int IOneeded ;
int IOcount;
int firsttimeCPU;
LinkedQueue<Pairs> IOprocess;
//very important! Node* IOlist;

int TerminationTime;
int FirstResponse;
int TRT;
int WT; 
int TotalIOD;
bool firsttime;
/**/
ProcessState State;

friend ostream& operator<<(ostream&, Process*);
//abd elrahman ahmed variables
Process* child;
Process* parent;
bool forkedBefore;
//end of abd elrahman variables
public:
	Process(){};
	Process(int ID,int arrival,int runtime,int IOnum=0)
	{
		PID=ID;
		ArrivalTime=arrival;
		CpuTime=runtime;
		IOcount=IOnum;
		totalexcuted = 0;
		forkedBefore = false;
		FirstResponse = -1;
		TerminationTime = -1;
		TRT = -1;
		WT = -1;
		TotalIOD = 0;
		firsttime = true;
		child = nullptr;
		parent = nullptr;
		firsttimeCPU = 0;
	}
	int getID()
	{
		return PID;
	}

	int getArrivalTime()
	{
		return ArrivalTime;
	}


	int getCpuTime()
	{
		return CpuTime;
	}


	int getIOcount()
	{
		return IOcount;
	}

	int getIOneeded()
	{
		return IOneeded;
	}

	int getTermination()
	{
		return TerminationTime;
	}
	ProcessState getProcessState()
	{
		return State;
	}

	void setIOneeded(int x)
	{
		IOneeded = x;
	}

	void setTermination(int t)
	{
		TerminationTime = t;
		TRT = t - ArrivalTime;
		WT = TRT - CpuTime;
	}

	void setFirstResponse(int t)
	{
		FirstResponse = t;
	}

	void incrementexcuted()
	{
		totalexcuted++;
	}

	int getexcuted()
	{
		return totalexcuted;
	}

	void setPair(int f, int s)
	{
		IOprocess.enqueue(Pairs(f, s));
	}

	int getRemainingTime()
	{
		return CpuTime - totalexcuted;
	}

	int needio(int& neededio)
	{
		if (!IOprocess.isEmpty())
		{
			Pairs p;
			IOprocess.peek(p);

			if (totalexcuted == p.getfirst())
			{
				IOprocess.dequeue(p);
				neededio = p.getsecond();
				return neededio;
			}
		}

		return -1;
	}
	

	void incrementIOD(int IOD)
	{
		TotalIOD = TotalIOD + IOD;
	}
	int getTotalIOD()
	{
		return TotalIOD;
	}

	void setfirsttimeCPU(int CPU)
	{
		firsttimeCPU = CPU;
	}
	int getfirsttimeCPU()
	{
		return firsttimeCPU;
	}
	void setfirsttime()
	{
		firsttime=false;
	}
	int getfirsttime()
	{
		return firsttime;
	}
	~Process(void)
	{
	}
	//abd elrahman ahmed functions
	bool getForkedBefore()
	{
		return forkedBefore;
	}

	void setForkedBefore()
	{
		forkedBefore = true;
	}

	Process* getChild()
	{
		return child;
	}

	void setChild(Process* ForkedChild)
	{
		child=ForkedChild;
	}

	Process* getParent()
	{
		return parent;
	}

	void setParent(Process* Parent)
	{
		parent = Parent;
	}
	bool isParent()
	{
		if (child != nullptr)
			return true;
		return false;
	}
	//end of abd elrahman functions
};

 