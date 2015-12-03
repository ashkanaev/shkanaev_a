#include <initializer_list>
#include "RnVector.h"

using namespace std;

void rnVectorTestConstructor(IndexType dim)
{
	cout << "Test  constructor RnVector(IndexType dim)" << endl;
	RnVector tmp(dim);
	cout << "Result " << tmp << endl;
}

void rnVectorTestConstructor(const RnVector& arg)
{
	cout << "Test  constructor RnVector(const RnVector& arg)" << endl;
	RnVector tmp(arg);
	cout << "Result " << tmp << endl;
}

void rnVectorTestQuality(const RnVector& rg, const RnVector& lg)
{
	cout << " Test operator== " << endl;
	cout << rg << " == " << lg << " = " << (lg == rg) << endl << endl;
	cout << rg << " != " << lg << " = " << (lg != rg) << endl << endl;

}

void rnVectorTestDivision(const RnVector& rg, const RnVector& lg)
{
	RnVector tmp(rg);
	cout << "Test Operator / & /= " << endl;
	cout << rg << " / " << lg << " = " << rg / lg << endl;
	cout << tmp << " /= " << lg;
	cout << " = " << (tmp /= lg) << endl << endl;
}

void rnVectorTestSubtraction(const RnVector& rg, const RnVector& lg)
{
	RnVector tmp(rg);
	cout << "Test Operator - & -= " << endl;
	cout << rg << " - " << lg << " = " << rg - lg << endl;
	cout << tmp << " -= " << lg;
	cout << " = " << (tmp -= lg) << endl << endl;
}

void rnVectorTestAddition(const RnVector& rg, const RnVector& lg)
{
	RnVector tmp(rg);
	cout << "Test Operator + & += " << endl;
	cout << rg << " + " << lg;
	cout << " = " << rg + lg << endl;
	cout << tmp << " += " << lg;
	cout << " = " << (tmp += lg) << endl << endl;
}

void rnVectorTestMultiplication(const RnVector& rg, const RnVector& lg)
{
	RnVector tmp(rg);
	cout << "Test Operator * & *= " << endl;
	cout << rg << " * " << lg << " = " << rg * lg << endl;
	cout << tmp << " *= " << lg;
	cout << " = " << (tmp *= lg) << endl << endl;
}

void rnVectorTestPreIncrement(RnVector& rg)
{
	cout << "Test operator++(int) & operator--(int)" << endl;
	cout << "++ " << rg;
	++rg;
	cout << " = " << rg << endl;
	cout << "-- " << rg;
	--rg;
	cout << " = " << rg << endl << endl;
}

void rnVectorTestIncrement(RnVector& rg)
{
	cout << "Test operator++() & operator--()" << endl;
	cout << "++ " << rg;
	rg++;
	cout << " = " << rg << endl;
	cout << "-- " << rg;
	rg++;
	cout << " = " << rg << endl << endl;
}

RnVector::~RnVector()
{
	delete[] _data;
}

ValueType& RnVector::operator[](const IndexType i)
{
	if (0 > i || i >= capacity)
	{
		throw out_of_range("Index out of range");
	}
	return _data[i];
}

const ValueType& RnVector::operator[](const IndexType i) const
{
	if (0 > i || i >= capacity)
	{
		throw out_of_range("Index out of range");
	}
	return _data[i];
}

int main()
{
	std::initializer_list<double> tmp{1, 3, 5, 6};
	std::initializer_list<double> tmp2{ 1, 3, 5, 6 };

	RnVector a(tmp);
	RnVector b(tmp2);

	rnVectorTestConstructor(tmp);
	rnVectorTestSubtraction(a, b);
	rnVectorTestAddition(a, b);
	rnVectorTestDivision(a, b);
	rnVectorTestMultiplication(a, b);
	rnVectorTestIncrement(a);
	rnVectorTestPreIncrement(b);
	rnVectorTestQuality(a, b);
	
	return 1;
}