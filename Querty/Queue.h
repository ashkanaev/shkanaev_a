
using ValueType = double;
struct Node;
struct Node
{
	ValueType data_{ 0 };
	Node* next_{ nullptr };
	Node* last_{ nullptr };
	Node(const ValueType v, Node* next, Node* last);
};

class Queue
{
public:
	Queue() = default;
	Queue(const Queue& arg);
	Queue& operator=(const Queue& arg) = default;
	~Queue();
	bool isEmpty() const;
	void pushFront(const ValueType& arg);
	void pushEnd(const ValueType& arg);
	void popFront();
	void popEnd();
	ValueType topFront() const;
	ValueType topEnd() const;

private:
	Node* head_{ nullptr };
	Node* tail_{ nullptr };
};

void TestStack(Queue & arg);