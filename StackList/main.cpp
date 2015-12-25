#include"StackLst.h"
#include<iostream>

using namespace std;

void testStack(Stacklst & arg)
{
	std::cout << "Pull stack with [ 0 1 .. 9] " << endl;
	for (int i = 0; i != 10; i++)
	{
		arg.push(i);
		cout << arg.top() << " ";
	}
	cout << "\nMake stack empty " << endl;
	for (int i = 0; i != 10; i++)
	{
		cout << arg.pop() << " ";
		arg.push(i);
	}
	cout << "\nStack is empty? " << arg.isEmpty() << endl << endl;
}

void main()
{
	Stacklst aa;
	testStack(aa);
	Stacklst bb(aa);
}