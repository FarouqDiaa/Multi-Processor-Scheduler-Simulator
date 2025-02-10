// test
// another
// gg
#pragma once
#include"Process.h"
#include"UserInterface.h"
#include"ProcessQueues.h"
class Processor;


class Scheduler{
private:
	int timestep;
	
	int Processorsnum;

	Processor** pros;
	int processnum;
	int BLKcount;
	int TRMcount;
	UserInterface Window;
	int fcfscount, sjfcount, rrcount, timeslice, rtf, maxW, stl;


	int MigRTF, MigMaxW, workstealper;

	
	ProcessQueue NEWlist;
	ProcessQueue BLKlist;
	ProcessQueue TRMlist;
	//abd elrahman ahmed variables
	LinkedQueue<Pairs> Sigkilllist;
	int forkprob;
	int Numberofkillsignals=0;
	int NumberofForkedProcesses=0;
	//end of abd elrahman ahmed variables


public:
	int getForkProbability()
	{
		return forkprob;
	}
	int gettime()
	{
	
	return timestep;
	}

	int getblk()
	{
	
	return BLKcount;
	
	}
	int gettrm()
	{
	
	return TRMcount;
	
	}
	
	int getslice()
	{
	
	return timeslice;
	}

	int getSTL()
	{
		return stl;
	}

	int getprocessnum()
	{
	
	return processnum;
	}
	void counterup()
	{
	
	timestep++;
	}

	int checkAvailability(ProcessorType type);
	void Assign();
	void Assign(Process*);
	bool migrate(Process*, ProcessorType T);
	void workSteal();
	void shedule();
	void printpros();
	void addtoBLK(Process*);
	void addtoTRM(Process*);
	bool removeBLK(Process*&);
	void Load();
	void simulate();
	Scheduler();
	//abd elrahman ahmed functions
	// Start of Forking Functions:
	bool TestingProbability(double Probability);
	//bool CanForkChild(Process* Process);
	void forkChild(Process* process);
	//Processor* findShortestRdyList();
	// end of Forking Functions
	// Start of Kill signal and kill orphans Functions
	void killSignal();
	void RemovekillSignal();
	bool killProcess(int id);
	void killOrphans(Process* child);
	//void printall();
	// end of Kill signal and kill orphans Functions
	//end of abd elrahman ahmed functions
	void IOHandling(Process* &run, int neededio);
	void CheckBlock();
	void Completed(Process*&run);
	void OutputFile();
};

