#include "Queue.h"	
#include <iostream>

using namespace std;

void TestQueue(Queue & arg)
{
	cout << "Pull Queue with(pushFront) [ 0 1 .. 9] " << endl;
	for (int i = 0; i != 10; i++)
	{
		arg.pushFront(i);
		cout << arg.topFront() << " ";
	}
	cout << "\nMake Queue empty(popEnd) " << endl;
	for (int i = 0; i != 10; i++)
	{
		arg.popEnd();
	}

	cout << "\n\nPull Queue with(pushEnd) [ 0 1 .. 9] " << endl;
	for (int i = 0; i != 10; i++)
	{
		arg.pushEnd(i);
		cout << arg.topEnd() << " ";
	}

	cout << "\nMake Queue empty(popFront) " << endl;
	for (int i = 0; i != 10; i++)
	{
		arg.popFront();
	}

	cout << "\n\nQueue is empty? " << arg.isEmpty() << endl;


}

void main()
{
	Queue a;
	TestQueue(a);
}