#include "RnVector.h"
#include <memory>
#include <stdexcept>
#include <initializer_list>

using namespace std;


RnVector::RnVector(const IndexType size)
	:capacity{ size }
{
	_data = new ValueType[capacity]{ 0 };
}

RnVector::RnVector(const RnVector& arg)
	: capacity{ arg.capacity }
	, _data{ new ValueType[capacity] }
{
	uninitialized_copy(arg._data, arg._data + arg.capacity, _data);
}

RnVector::RnVector(RnVector&& arg)
	:capacity{ arg.capacity }
	, _data{ arg._data }
{
	arg.capacity = 0;
	arg._data = nullptr;
}

RnVector::RnVector(std::initializer_list<double> arg)
	:capacity{ static_cast<IndexType>(arg.size()) }
	, _data{ new ValueType[capacity] }
{
	uninitialized_copy(arg.begin(), arg.end(), _data);
}

RnVector & RnVector::operator+=(const RnVector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] += rhs._data[i];
	}
	return *this;
}

RnVector & RnVector::operator-=(const RnVector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] -= rhs._data[i];
	}
	return *this;
}

bool RnVector::operator!=(const RnVector& rhs) const
{
	return !operator==(rhs);
}

bool RnVector::operator==(const RnVector& rhs) const
{
	if (capacity != rhs.capacity) return 0;
	for (IndexType i = 0; i != capacity; i++)
	{
		if (_data[i] != rhs._data[i])
		{
			return 0;
		}
	}
	return 1;
}

std::ostream& RnVector::print(std::ostream& arg) const
{
	for (IndexType i = 0; i < capacity; i++)
	{
		arg << _data[i] << " ";
	}
	return arg;
}

RnVector& RnVector::operator++()
{
	for (IndexType i = 0; i != capacity; i++)
	{
		_data[i]++;
	}
	return *this;
}

RnVector& RnVector::operator--()
{
	for (IndexType i = 0; i != capacity; i++)
	{
		_data[i]--;
	}
	return *this;
}

RnVector RnVector::operator++(int)
{
	RnVector tmp(*this);
	operator++();
	return tmp;
}

RnVector RnVector::operator--(int)
{
	RnVector tmp(*this);
	operator--();
	return tmp;
}

std::ostream& operator<<(std::ostream& arg, const RnVector& r)
{
	return r.print(arg);
}
RnVector & RnVector::operator*=(const RnVector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] *= rhs._data[i];
	}
	return *this;
}

RnVector & RnVector::operator/=(const RnVector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] /= rhs._data[i];
	}
	return *this;
}

RnVector operator+(const RnVector& rhs, const RnVector& lhs)
{
	return RnVector(lhs) += rhs;
}
RnVector operator-(const RnVector& rhs, const RnVector& lhs)
{
	return RnVector(lhs) -= rhs;
}
RnVector operator*(const RnVector& rhs, const RnVector& lhs)
{
	return RnVector(lhs) *= rhs;
}

RnVector operator/(const RnVector& rhs, const RnVector& lhs)
{
	return RnVector(lhs) /= rhs;
}

