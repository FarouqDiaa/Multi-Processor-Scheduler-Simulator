#include<iostream>
#include"Process.h"

#include"Processor.h"
#include"Scheduler.h"
#include<time.h>


using namespace std;

//test

int main()
{
	
	Scheduler sh;
	sh.Load();
	srand(time(0));
	while(sh.gettrm()<sh.getprocessnum())
	{
		sh.simulate();
	//	sh.Assign();
	//	sh.CheckBlock();
	//	sh.shedule();
	//	sh.printpros();
	//	sh.counterup();
	//	if (sh.gettime() % sh.getSTL() == 0)
	//		sh.workSteal();
	//	sh.RemovekillSignal();
	////getchar();
	}
	sh.OutputFile();
	
	
	

	system("pause");
	return 0;
}