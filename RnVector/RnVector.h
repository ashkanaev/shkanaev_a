#include<iostream>
#include <initializer_list>

using ValueType = double;
using IndexType = ptrdiff_t;

class RnVector
{

public:
	RnVector() = default;
	RnVector(const IndexType size);
	RnVector(const RnVector& arg);
	RnVector(RnVector&& arg);
	RnVector(std::initializer_list<double> arg);
	~RnVector();

	ValueType& operator[](const IndexType i);
	const ValueType& operator[](const IndexType i) const;

	RnVector& operator=(const RnVector&) noexcept = default;
	RnVector& operator+=(const RnVector& rhs);
	RnVector& operator/=(const RnVector& rhs);
	RnVector& operator*=(const RnVector& rhs);
	RnVector& operator-=(const RnVector& rhs);

	bool operator!=(const RnVector& rhs) const;
	bool operator==(const RnVector& rhs) const;

	std::ostream& print(std::ostream& arg) const;

	RnVector& operator++();
	RnVector& operator--();
	RnVector operator++(int);
	RnVector operator--(int);

private:
	IndexType capacity{ 0 };
	double* _data{ nullptr };

};

std::ostream& operator<<(std::ostream& arg, const RnVector& r);

RnVector operator+(const RnVector& rhs, const RnVector& lhs);
RnVector operator-(const RnVector& rhs, const RnVector& lhs);
RnVector operator*(const RnVector& rhs, const RnVector& lhs);
RnVector operator/(const RnVector& rhs, const RnVector& lhs);
