#include "MatrixArr.h"
#include <stdexcept>
#include <iostream>
#include <memory>


MatrixArr::MatrixArr()
	:_h{ 0 }
	, _w{ 0 }
	, _data{ nullptr }
{
}

MatrixArr::MatrixArr(const IndexType& h, const IndexType& w)
	:_h{ h }
	, _w{ w }
{
	_data = new ValueType*[_h] {nullptr};

	for (IndexType i = 0; i != _h; i++)
	{
		_data[i] = new ValueType[_w]{ 0 };
	}
}

MatrixArr::MatrixArr(const MatrixArr& arg)
	:_h{ arg._h }
	, _w{ arg._w }
{
	_data = new ValueType*[_h];

	for (ptrdiff_t i = 0; i != _h; i++)
	{
		_data[i] = new ValueType[_w]{ 0 };
		std::uninitialized_copy(arg._data[i], arg._data[i] + arg._w, _data[i]);
	}
}

MatrixArr::~MatrixArr()
{
	for (IndexType i = 0; i != _h; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}

MatrixArr& MatrixArr::operator+=(const MatrixArr& rhs)
{
	for (IndexType i = 0; i != _h; i++)
	{
		for (IndexType j = 0; j != _w; j++)
		{
			_data[i][j] += rhs._data[i][j];
		}
	}
	return *this;
}

MatrixArr& MatrixArr::operator-=(const MatrixArr& rhs)
{
	for (IndexType i = 0; i != _h; i++)
	{
		for (IndexType j = 0; j != _w; j++)
		{
			this->_data[i][j] -= rhs._data[i][j];
		}
	}
	return *this;
}

MatrixArr& MatrixArr::operator*=(const MatrixArr& rhs)
{
	ValueType tmp{ 0 };
	if (_h != rhs._h || _w != rhs._w)
	{
		throw std::domain_error("Multiplication is unacceptable!");
	}
	for (IndexType i = 0; i < _h; i++)
	{
		for (IndexType j = 0; j < _w; j++)
		{
			for (IndexType n = 0; n < _w; n++)
			{
				tmp += _data[i][n] * rhs._data[n][j];
			}
			_data[i][j] = tmp;
			tmp = 0;
		}
	}
	return *this;
}

MatrixArr& MatrixArr::operator*=(const ValueType& arg)
{
	for (IndexType i = 0; i != _h; i++)
	{
		for (IndexType j = 0; j != _w; j++)
		{
			this->_data[i][j] *= arg;
		}
	}
	return *this;
}

MatrixArr& MatrixArr::operator/=(const ValueType& rhs)
{
	for (IndexType i = 0; i != _h; i++)
	{
		for (IndexType j = 0; j != _w; j++)
		{
			this->_data[i][j] /= rhs;
		}
	}
	return *this;
}

MatrixArr& MatrixArr::operator~()
{
	MatrixArr tmp(*this);
	for (IndexType i = 0; i < _h; i++)
	{
		for (IndexType j = 0; i < _w; j++)
		{
			_data[i][j] = tmp.elementAt(j, i);
		}
	}
	return *this;
}

IndexType MatrixArr::getHeight() const
{
	return _h;
}

IndexType MatrixArr::getWidth() const
{
	return _w;
}

std::ostream& MatrixArr::print(std::ostream& arg) const
{
	for (IndexType i = 0; i < _h; i++)
	{
		for (IndexType j = 0; j < _w; j++)
		{
			std::cout << _data[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return arg;
}

bool MatrixArr::operator==(const MatrixArr& rhs) const
{
	if (_w != rhs._w || _h != rhs._h)
	{
		return 0;
	}

	for (IndexType i = 0; i < _h; i++)
	{
		for (IndexType j = 0; i < _w; j++)
		{
			if (_data[i][j] != rhs._data[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

bool MatrixArr::operator!=(const MatrixArr& rhs) const
{
	return !operator==(rhs);
}

ValueType& MatrixArr::elementAt(const IndexType& i, const IndexType& j) const
{
	if ((i < 0) || (i >= _h) || (j < 0) || (j >= _w))
	{
		throw std::out_of_range("Index out of range");

	}
	return  _data[i][j];
}

void MatrixArr::elementSet(const IndexType& i, const IndexType& j, const ValueType& val)
{
	if ((i < 0) || (i >= _h) || (j < 0) || (j >= _w))
	{
		throw std::out_of_range("Index out of range");

	}
	_data[i][j] = val;
}

std::ostream& operator<<(std::ostream& arg, const MatrixArr& r)
{
	return r.print(arg);
}

MatrixArr operator+(const MatrixArr& rhs, const MatrixArr& lhs)
{
	return MatrixArr(lhs) += rhs;
}

MatrixArr operator-(const MatrixArr& rhs, const MatrixArr& lhs)
{
	return MatrixArr(lhs) -= rhs;
}

MatrixArr operator*(const MatrixArr& lhs, const MatrixArr& rhs)
{
	if(rhs.getWidth()!= lhs.getHeight())
	{
		std::domain_error(" multiplication is unacceptadle!");
	}

	MatrixArr tmp2(lhs.getHeight(), rhs.getWidth());
	ValueType tmp{ 0 };
	for (IndexType i = 0; i < tmp2.getHeight(); i++)
	{
		for (IndexType j = 0; j < tmp2.getWidth(); j++)
		{
			for (IndexType n = 0; n < rhs.getWidth(); n++)
			{
				tmp += rhs.elementAt(i, n) * lhs.elementAt(n, j);
			}
			tmp2.elementSet(i, j, tmp);
			tmp = 0;
		}
	}
	return tmp2;
}

MatrixArr operator/(const MatrixArr& lhs, const ValueType& rhs)
{
	return MatrixArr(lhs) /= rhs;
}


