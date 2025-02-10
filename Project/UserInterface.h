#pragma once
#include <iostream>
#include"defs.h"

using namespace std;

class UserInterface
{
	UI_MODE currentMode;
public:
	UserInterface()
	{
		int x = -1;
		do {
			cout << "Choose the mode of the program:" << endl
				<< " 1 for (Interactive mode), 2 for (Step - By - Step mode), and 3 for (Silent mode)" << endl;
			cin >> x;
		} while (x < 1 && x > 3);
		cin.ignore();
		if (x == 1)
			currentMode = INTERACTIVE_MODE;
		else if (x == 2)
			currentMode = STEPBYSTEP_MODE;
		else if (x == 3)
			currentMode = SILENT_MODE;
	};
	template<class T>
	void print(const T msg)
	{
		cout << msg;
	}

	UI_MODE getMode()
	{
		return currentMode;
	}

	void printMode()
	{
		if (currentMode == INTERACTIVE_MODE)
		{
			cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !";
			cin.ignore();
		}
		else if (currentMode == STEPBYSTEP_MODE)
		{
			_sleep(1000);
		}
		else if (currentMode == SILENT_MODE)
		{
			cout << "Silent Mode......			Simulation starts...\n Simulation ends, Output file created"<<endl;
		}
	}
};