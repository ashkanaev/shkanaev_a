#include "R3Vector.h"

using namespace std;

R3Vector::R3Vector(const double & x, const double & y, const double & z)
	:_data{ x, y, z }
{
}

R3Vector & R3Vector::operator+=(const R3Vector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] += rhs._data[i];
	}
	return *this;
}

R3Vector & R3Vector::operator-=(const R3Vector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] -= rhs._data[i];
	}
	return *this;
}

bool R3Vector::operator!=(const R3Vector& rhs) const
{
	return !operator==(rhs);
}

bool R3Vector::operator==(const R3Vector& rhs) const
{
	return (rX() == rhs.rX()) && (rY() == rhs.rY()) && (rZ() == rhs.rZ());
}

std::ostream& R3Vector::print(std::ostream& arg) const
{
	arg << "(" << rX() << ", " << rY() << ", " << rZ() << ")";
	return arg;
}

std::ostream& operator<<(std::ostream& arg, const R3Vector& r)
{
	return r.print(arg);
}

R3Vector operator+(const R3Vector& rhs, const R3Vector& lhs)
{
	return R3Vector(lhs) += rhs;
}
R3Vector operator-(const R3Vector& rhs, const R3Vector& lhs)
{
	return R3Vector(lhs) -= rhs;
}
R3Vector operator*(const R3Vector& rhs, const R3Vector& lhs)
{
	return R3Vector(lhs) *= rhs;
}

R3Vector operator/(const R3Vector& rhs, const R3Vector& lhs)
{
	return R3Vector(lhs) /= rhs;
}

R3Vector & R3Vector::operator*=(const R3Vector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] *= rhs._data[i];
	}
	return *this;
}

R3Vector & R3Vector::operator/=(const R3Vector & rhs)
{
	for (ptrdiff_t i = 0; i < capacity; i++)
	{
		_data[i] /= rhs._data[i];
	}
	return *this;
}

R3Vector& R3Vector::operator++()
{
	for (ptrdiff_t i = 0; i != capacity; i++)
	{
		_data[i]++;
	}
	return *this;
}

R3Vector& R3Vector::operator--()
{
	for (ptrdiff_t i = 0; i != capacity; i++)
	{
		_data[i]--;
	}
	return *this;
}

R3Vector R3Vector::operator++(int)
{
	R3Vector tmp(*this);
	operator++();
	return tmp;
}

R3Vector R3Vector::operator--(int)
{
	R3Vector tmp(*this);
	operator--();
	return tmp;
}