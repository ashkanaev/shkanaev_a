#include <iostream>

using ValueType = double;
struct Node;
struct Node
{
	ValueType data_{ 0 };
	Node* next_{ nullptr };
	Node(const ValueType v, Node* next);
};

class Stacklst
{
public:
	Stacklst() = default;
	Stacklst(const Stacklst& arg);
	Stacklst& operator=(const Stacklst& arg) = default;
	~Stacklst();
	bool isEmpty() const;
	void push(const ValueType& arg);
	ValueType pop();
	ValueType top() const;
private:
	Node* head_{ nullptr };
};

