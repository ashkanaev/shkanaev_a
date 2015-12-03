#include "stacklst.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Stacklst::~Stacklst()
{
	while (0 == isEmpty())
		pop();
}


bool Stacklst::isEmpty() const
{
	return nullptr == head_;
}

void Stacklst::push(const ValueType& arg)
{
	Node* tmp = new Node(arg, head_);
	head_ = tmp;
}

ValueType Stacklst::pop()
{
	ValueType tmp{ head_->data_ };
	if (isEmpty())
	{
		throw std::domain_error("Stack is empty");
	}
	Node* deleted{ head_ };
	head_ = head_->next_;
	delete deleted;
	return tmp;
}

ValueType Stacklst::top() const
{
	if (isEmpty())
	{
		throw std::domain_error("error stack is empty");
	}
	return head_->data_;
}

Node::Node(const ValueType v, Node * next)
	:data_{ v }
	, next_{ next }
{
}
