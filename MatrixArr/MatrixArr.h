#pragma once
#include <cstddef>
#include <iostream>

using IndexType = ptrdiff_t; //Если внести в класс - ошибка видимости 
using ValueType = double;

class MatrixArr
{
public:
	MatrixArr();
	MatrixArr(const IndexType& _h, const IndexType& _w);
	MatrixArr(const MatrixArr& arg);
	~MatrixArr();

	MatrixArr& operator= (const MatrixArr& rhs) = default;
	MatrixArr& operator+=(const MatrixArr& rhs);
	MatrixArr& operator-=(const MatrixArr& rhs);
	MatrixArr& operator*=(const MatrixArr& rhs);
	MatrixArr& operator*=(const ValueType& arg);
	MatrixArr& operator/=(const ValueType& rhs);
	MatrixArr& operator~();

	IndexType getHeight() const;
	IndexType getWidth() const;

	std::ostream& print(std::ostream& arg) const;

	bool operator==(const MatrixArr& rhs) const;
	bool operator!=(const MatrixArr& rhs) const;

	ValueType& elementAt(const IndexType& i, const IndexType& j) const;
	void elementSet(const IndexType& i, const IndexType& j, const ValueType& val);

private:
	IndexType _h{ 0 };
	IndexType _w{ 0 };
	ValueType** _data{ nullptr };
};

std::ostream& operator<<(std::ostream& arg, const MatrixArr& r);

MatrixArr operator+(const MatrixArr& rhs, const MatrixArr& lhs);
MatrixArr operator-(const MatrixArr& rhs, const MatrixArr& lhs);
MatrixArr operator*(const MatrixArr& rhs, const MatrixArr& lhs);


