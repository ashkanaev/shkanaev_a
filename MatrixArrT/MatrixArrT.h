#pragma once
#include <cstddef>
#include <iostream>
#include <memory>
using IndexType = ptrdiff_t; //Если внести в класс - ошибка видимости 

template<typename T>
class MatrixArr
{
public:
	MatrixArr();
	MatrixArr(const IndexType& _h, const IndexType& _w);
	MatrixArr(const MatrixArr<typename T>& arg);
	~MatrixArr();

	MatrixArr<typename T>& operator= (const MatrixArr& rhs) = default;
	MatrixArr<typename T>& operator+=(const MatrixArr& rhs);
	MatrixArr<typename T>& operator-=(const MatrixArr& rhs);
	MatrixArr<typename T>& operator*=(const MatrixArr& rhs);
	MatrixArr<typename T>& operator*=(const T& arg);
	MatrixArr<typename T>& operator/=(const T& rhs);
	MatrixArr<typename T>& operator~();

	IndexType getHeight() const;
	IndexType getWidth() const;

	std::ostream& print(std::ostream& arg) const;

	bool operator==(const MatrixArr<typename T>& rhs) const;
	bool operator!=(const MatrixArr<typename T>& rhs) const;

	T& elementAt(const IndexType& i, const IndexType& j) const;
	void elementSet(const IndexType& i, const IndexType& j, const T& val);

private:
	IndexType _h{ 0 };
	IndexType _w{ 0 };
	T** _data{ nullptr };
};
template<typename T>
std::ostream& operator<<(std::ostream& arg, const MatrixArr<typename T>& r);
template<typename T>
MatrixArr<typename T> operator+(const MatrixArr<typename T>& rhs, const MatrixArr<typename T>& lhs);
template<typename T>
MatrixArr<typename T> operator-(const MatrixArr<typename T>& rhs, const MatrixArr<typename T>& lhs);
template<typename T>
MatrixArr<typename T> operator*(const MatrixArr<typename T>& rhs, const MatrixArr<typename T>& lhs);


template<typename T>
MatrixArr<typename T>::MatrixArr()
	:_h{ 0 }
	, _w{ 0 }
	, _data{ nullptr }
{
}

template<typename T>
MatrixArr<typename T>::MatrixArr(const IndexType& h, const IndexType& w)
	:_h{ h }
	, _w{ w }
{
	_data = new T*[_h] {nullptr};

	for (IndexType i = 0; i != _h; i++)
	{
		_data[i] = new T[_w]{ 0 };
	}
}

template<typename T>
MatrixArr<typename T>::MatrixArr(const MatrixArr<typename T>& arg)
	:_h{ arg._h }
	, _w{ arg._w }
{
	_data = new T*[_h];

	for (ptrdiff_t i = 0; i != _h; i++)
	{
		_data[i] = new T[_w]{ 0 };
		std::uninitialized_copy(arg._data[i], arg._data[i] + arg._w, _data[i]);
	}
}

template<typename T>
MatrixArr<typename T>::~MatrixArr()
{
	for (IndexType i = 0; i != _h; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator+=(const MatrixArr<typename T>& rhs)
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

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator-=(const MatrixArr<typename T>& rhs)
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

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator*=(const MatrixArr<typename T>& rhs)
{
	T tmp{ 0 };
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

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator*=(const T& arg)
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

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator/=(const T& rhs)
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

template<typename T>
MatrixArr<typename T>& MatrixArr<typename T>::operator~()
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

template<typename T>
IndexType MatrixArr<typename T>::getHeight() const
{
	return _h;
}

template<typename T>
IndexType MatrixArr<typename T>::getWidth() const
{
	return _w;
}

template<typename T>
std::ostream& MatrixArr<typename T>::print(std::ostream& arg) const
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

template<typename T>
bool MatrixArr<typename T>::operator==(const MatrixArr<typename T>& rhs) const
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

template<typename T>
bool MatrixArr<typename T>::operator!=(const MatrixArr<typename T>& rhs) const
{
	return !operator==(rhs);
}

template<typename T>
T& MatrixArr<typename T>::elementAt(const IndexType& i, const IndexType& j) const
{
	if ((i < 0) || (i >= _h) || (j < 0) || (j >= _w))
	{
		throw std::out_of_range("Index out of range");

	}
	return  _data[i][j];
}

template<typename T>
void MatrixArr<typename T>::elementSet(const IndexType& i, const IndexType& j, const T& val)
{
	if ((i < 0) || (i >= _h) || (j < 0) || (j >= _w))
	{
		throw std::out_of_range("Index out of range");

	}
	_data[i][j] = val;
}

template<typename T>
std::ostream& operator<<(std::ostream& arg, const MatrixArr<typename T>& r)
{
	return r.print(arg);
}

template<typename T>
MatrixArr<typename T> operator+(const MatrixArr<typename T>& rhs, const MatrixArr<typename T>& lhs)
{
	return MatrixArr<typename T>(lhs) += rhs;
}

template<typename T>
MatrixArr<typename T> operator-(const MatrixArr<typename T>& rhs, const MatrixArr<typename T>& lhs)
{
	return MatrixArr<typename T>(lhs) -= rhs;
}

template<typename T>
MatrixArr<typename T> operator*(const MatrixArr<typename T>& lhs, const MatrixArr<typename T>& rhs)
{
	if (rhs.getWidth() != lhs.getHeight())
	{
		std::domain_error(" multiplication is unacceptadle!");
	}

	MatrixArr<typename T> tmp2(lhs.getHeight(), rhs.getWidth());
	T tmp{ 0 };
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

template<typename T>
MatrixArr<typename T> operator/(const MatrixArr<typename T>& lhs, const T& rhs)
{
	return MatrixArr<typename T>(lhs) /= rhs;
}





