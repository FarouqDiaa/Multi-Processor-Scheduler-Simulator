#include "Pairs.h"
#include <iostream>
using namespace std;


Pairs::Pairs(int f, int s)
{
	first = f;
	second = s;
}

int Pairs::getfirst()
{
	return first;
}

int Pairs::getsecond()
{
	return second;
}
