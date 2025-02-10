#pragma once 
#include<iostream>

using namespace std;








class Process{
private:
int PID;
int ArrivalTime;
int CpuTime;

int IOcount;

//very important! Node* IOlist;
//Node*child; bool isparent;

int TerminationTime;
int FirstResponse;
/**/


friend ostream& operator<<(ostream&, Process*);

public:
	Process(){};
	Process(int ID,int arrival,int runtime,int IOnum=0)
	{
	PID=ID;
	ArrivalTime=arrival;
	CpuTime=runtime;
	IOcount=IOnum;
	
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
	int getTermination()
	{
	return TerminationTime;
	}
	void setTermination(int x)
	{
	TerminationTime=x;
	}

	
	~Process(void)
	{
		
	}


};

 