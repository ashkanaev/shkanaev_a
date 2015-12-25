#include <cstddef>

using IndexType = ptrdiff_t;
using ValueType = double;


class Stack
{

public:
	Stack();
	Stack(const Stack& arg) noexcept = default;
	Stack& operator=(const Stack& arg) = default;
	~Stack();
	bool isEmpty() const;
	void push(const ValueType& arg);
	void pop();
	void resize();
	ValueType top() const;

private:
	IndexType size{ 2 };
	IndexType iTop{ 0 };
	ValueType* _data{ nullptr };
};
