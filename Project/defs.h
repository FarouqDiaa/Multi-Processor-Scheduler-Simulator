#pragma once 

enum ProcessState
{
	NEW,
	RDY,
	RUN,
	BLK,
	TRM,
	ORPH,
	statescount
};


enum ProcessorType
{
	FCFS,
	SJF,
	RR,
	ALL
};


enum ProcessorState{

	BUSY,
	IDLE

};
enum UI_MODE	// user interface mode
{
	INTERACTIVE_MODE,
	STEPBYSTEP_MODE,
	SILENT_MODE
};
