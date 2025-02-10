#include<iostream>
#include"Node.h"
#include"ProcessQueue.h"
#include"ProcessLinkedlist.h"
#include"SJQueue.h"
using namespace std;




int main()
{
	Process*a=new Process(1,3,2);
	Process*b=new Process(2,2,2);
	Process*c=new Process(3,3,5);
	Process*d=new Process(4,1,1);
	Process*e=new Process(5,3,5);
	Process*f=new Process(6,3,5);
	Process*g=new Process(7,3,5);

	Process*h=new Process(8,3,5);

	Process*k;
	Process*s;

	ProcessLinkedlist u;
	ProcessQueue z;
		ProcessQueue x;
		SJQueue r;

		r.enqueue(a);
		
		r.enqueue(b);

		r.enqueue(c);
		r.enqueue(d);
		r.dequeue(k);
		cout<<k->getID()<<endl;
		r.print();

		/*u.insertlast(a);
		u.insertlast(b);
		u.insertlast(c);
		u.insertlast(d);
		/*u.removefirst(k);
		u.removefirst(s);
		cout<<k->getID()<<endl;
		u.removeid(3,k);
		cout<<k->getID()<<endl;
		u.print();*/
	/*z.enqueue(a);
	z.enqueue(b);
	z.enqueue(c);
	z.enqueue(d);
	z.enqueue(e);
	z.enqueue(f);
	z.enqueue(g);
	z.enqueue(h);
	z.dequeue(k);

	x.enqueue(k);

	z.dequeue(k);
	x.enqueue(k);
	x.dequeue(s);



	z.print();
	cout<<endl;

	x.print();*/







	system("pause");
	return 0;
}