#include <iostream>
#include <fstream>
using namespace std;
void main() {
	int fcfscount, sjfcount, rrcount, Processorsnum;
	int timeslice, rtf, maxW, stl, forkprob , processnum;

	ifstream fileinput("bigtest.txt");

	if (fileinput.is_open())
	{
		fileinput >> fcfscount;
		fileinput >> sjfcount;
		fileinput >> rrcount;
		fileinput >> timeslice >> rtf >> maxW >> stl;
		fileinput >> forkprob ;
		fileinput >> processnum;

		cout << fcfscount << "\t" << sjfcount << "\t" << rrcount << endl;
		cout << timeslice << endl;
		cout << rtf << "\t" << maxW << "\t" << stl << "\t" << forkprob << endl;

		for (int i = 1; i <= processnum; i++)
		{
			int AT, ID, CT, N, first, second;
			fileinput >> AT >> ID >> CT >> N;

			cout << AT << "\t" << ID << "\t" << CT << "\t" << N << "\t";
			for (int i = 0; i < N; i++)
			{
				if (i == 0)
				{
					fileinput.ignore();
				}
				fileinput.ignore();
				fileinput >> first;
				fileinput.ignore();
				fileinput >> second;
				fileinput.ignore();

				cout << "(" << first << "," << second << ")";
			}
			cout << endl;
			
		}
		
		int killpaira, killpairb;

		while (fileinput >> killpaira)
		{
			fileinput.ignore();
			fileinput >> killpairb;
			cout << killpaira << "\t" << killpairb << endl;

		}

		fileinput.close();

	}

	else
	{
		cout << "error could not open the file";
	}
}