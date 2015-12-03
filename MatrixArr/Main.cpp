#include "MatrixArr.h"
#include  <iostream>

using namespace std;

void matrixArrTestSubtraction(const MatrixArr& rg, const MatrixArr& lg)
{
	MatrixArr tmp(rg);
	std::cout << "Test Operator - & -= " << std::endl;
	std::cout << rg << " - \n" << lg << " = \n" << rg - lg << std::endl;
	std::cout << tmp << " -= \n" << lg;
	cout << " = \n" << (tmp -= lg) << std::endl << std::endl;
}
void matrixArrTestAddition(const MatrixArr& rg, const MatrixArr& lg)
{
	MatrixArr tmp(rg);
	std::cout << "Test Operator + & += " << std::endl;
	std::cout << rg << " + \n" << lg << " = \n" << rg + lg << std::endl;
	std::cout << tmp << " += \n" << lg;
	cout << " = \n" << (tmp += lg) << std::endl << std::endl;
}
void matrixArrTestMultiplication(const MatrixArr& rg, const MatrixArr& lg)
{
	MatrixArr tmp(rg);
	std::cout << "Test Operator * & *= " << std::endl;
	std::cout << rg << " * \n" << lg << " = \n" << rg * lg << std::endl;
	std::cout << tmp << " *= \n" << lg;
	cout << " = \n" << (tmp *= lg) << std::endl << std::endl;
}
void matrixArrTestConstructor(const IndexType& h, const IndexType& w)
{
	std::cout << "Test  constructor MatrixArr(const IndexType& h, const IndexType& w)" << std::endl;
	MatrixArr tmp(h, w);
	std::cout << "Result " << tmp << std::endl;
}

void matrixArrTestConstructor(const MatrixArr& arg)
{
	std::cout << "Test  constructor MatrixArr(const MatrixArr& arg)" << std::endl;
	MatrixArr tmp(arg);
	std::cout << "Result " << tmp << std::endl;
}

void matrixArrTestQuality(const MatrixArr& rg, const MatrixArr& lg)
{
	std::cout << " Test operator== " << std::endl;
	std::cout << rg << " == " << lg << " = " << (lg == rg) << std::endl << std::endl;
	std::cout << rg << " != " << lg << " = " << (lg != rg) << std::endl << std::endl;

}

void initObj(MatrixArr& arg)
{
	for (IndexType i = 0; i != arg.getHeight(); i++)
		for (IndexType j = 0; j != arg.getWidth(); j++)
		{
			arg.elementSet(i, j, rand() % 10 + 0);
		}
}

void main()
{
	MatrixArr a(5, 5), b(4, 5), c(5, 2),  d(5, 4);
	initObj(a);
	initObj(c);
	initObj(b);
	initObj(d);
	matrixArrTestConstructor(5, 2);
	matrixArrTestAddition(a, a);
	matrixArrTestMultiplication(a, a);
	matrixArrTestQuality(a, b);
	matrixArrTestSubtraction(c, c);
	return;
}