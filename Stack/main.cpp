#include "Stack.h"
#include <iostream>

void TestStack(Stack & arg)
{
	std::cout << "Pull stack with [ 0 1 .. 9]\n " << std::endl;
	for (int i = 0; i != 10; i++)
	{
		arg.push(i);
		std::cout << arg.top() << " ";
	}
	std::cout << "\nMake stack empty " << std::endl << std::endl;
	for (int i = 0; i != 10; i++)
	{
		std::cout << arg.top() << " ";
		arg.pop();
	}
	std::cout << "\nStack is empty? " << arg.isEmpty() << std::endl << std::endl;
}
void main()
{
	Stack aa;
	TestStack(aa);

	return;
}