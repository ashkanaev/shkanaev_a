#include "stacklst.h"
#include <stdexcept>
#include <iostream>
#include <list>

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

Stacklst::Stacklst(const Stacklst& arg)
{
	list<ValueType> tmp2;
	Node* tmp = arg.head_;
	while(tmp != nullptr)
	{
		tmp2.push_back(tmp->data_);
		tmp = tmp->next_;
	}
	while(!tmp2.empty())
	{
		push(tmp2.back());
		tmp2.pop_back();
	}
}