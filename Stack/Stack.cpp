#include "Stack.h"
#include <memory>
#include <iostream>

using namespace std;

Stack::Stack()
	:_data{ new ValueType[size] }
{
}

Stack::~Stack()
{
	delete[] _data;
}

bool Stack::isEmpty() const
{
	return iTop == 0;
}

void Stack::push(const ValueType& arg)
{
	if (iTop == size)
	{
		resize();
	}
	_data[iTop++] = arg;
}

void Stack::pop()
{
	if (!isEmpty())
	{
		iTop--;
	}
}

void Stack::resize()
{
	ValueType* tmp = new ValueType[size * 2];
	uninitialized_copy(_data, _data + size, tmp);
	size *= 2;
	delete[] _data;
	_data = tmp;
}

ValueType Stack::top() const
{
	if (isEmpty())
	{
		throw std::domain_error("Stack is empty");
	}
	return _data[iTop - 1];
}

