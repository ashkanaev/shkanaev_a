#include "Queue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Queue::~Queue()
{
	while (0 == isEmpty())
		topFront();
}


bool Queue::isEmpty() const
{
	return nullptr == head_;
}

void Queue::pushFront(const ValueType& arg)
{
		Node* tmp = new Node(arg, head_, nullptr);
		if (isEmpty()) tail_ = tmp;
		else head_->last_ = tmp;
		head_ = tmp;
}

void Queue::pushEnd(const ValueType& arg)
{
	Node* tmp = new Node(arg, nullptr, tail_);
	if (isEmpty()) head_ = tmp;
	else tail_->next_ = tmp;
	tail_ = tmp;
}


void Queue::popFront()
{
	if (!isEmpty())
	{
		Node* deleted{ head_ };
		if (head_ == tail_) tail_ = head_->next_;
		head_ = head_->next_;
		delete deleted;
	}
}

void Queue::popEnd()
{
	if (!isEmpty())
	{
		Node* deleted{ tail_ };
		if (head_ == tail_) head_ = tail_->last_;
		tail_ = tail_->last_;
		delete deleted;
	}
}

ValueType Queue::topFront() const
{
	if (isEmpty())
	{
		throw std::domain_error("error stack is empty");
	}
	return head_->data_;
}

ValueType Queue::topEnd() const
{
	if (isEmpty())
	{
		throw std::domain_error("error stack is empty");
	}
	return tail_->data_;
}



Node::Node(const ValueType v, Node * next, Node * last)
	:data_{ v }
	, next_{ next }
	,last_{last}
{
}
