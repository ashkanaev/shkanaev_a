#include "MatrixArrT.h"
#include  <iostream>

using namespace std;
template<typename T>
void matrixArrTestSubtraction(const MatrixArr<typename T>& rg, const MatrixArr<typename T>& lg)
{
	MatrixArr<double> tmp(rg);
	std::cout << "Test Operator - & -= " << std::endl;
	std::cout << rg << " - \n" << lg << " = \n" << rg - lg << std::endl;
	std::cout << tmp << " -= \n" << lg;
	cout << " = \n" << (tmp -= lg) << std::endl << std::endl;
}
template<typename T>
void matrixArrTestAddition(const MatrixArr<typename T>& rg, const MatrixArr<typename T>& lg)
{
	MatrixArr<double> tmp(rg);
	std::cout << "Test Operator + & += " << std::endl;
	std::cout << rg << " + \n" << lg << " = \n" << rg + lg << std::endl;
	std::cout << tmp << " += \n" << lg;
	cout << " = \n" << (tmp += lg) << std::endl << std::endl;
}
template<typename T>
void matrixArrTestMultiplication(const MatrixArr<typename T>& rg, const MatrixArr<typename T>& lg)
{
	MatrixArr<double> tmp(rg);
	std::cout << "Test Operator * & *= " << std::endl;
	std::cout << rg << " * \n" << lg << " = \n" << rg * lg << std::endl;
	std::cout << tmp << " *= \n" << lg;
	cout << " = \n" << (tmp *= lg) << std::endl << std::endl;
}
template<typename T>
void matrixArrTestConstructor(int h, int w)
{
	std::cout << "Test  constructor MatrixArr(const IndexType& h, const IndexType& w)" << std::endl;
	MatrixArr tmp<double>(h, w);
	std::cout << "Result " << tmp << std::endl;
}
template<typename T>
void matrixArrTestConstructor(const MatrixArr<typename T>& arg)
{
	std::cout << "Test  constructor MatrixArr(const MatrixArr& arg)" << std::endl;
	MatrixArr<double> tmp(arg);
	std::cout << "Result " << tmp << std::endl;
}
template<typename T>
void matrixArrTestQuality(const MatrixArr<typename T>& rg, const MatrixArr<typename T>& lg)
{
	std::cout << " Test operator== " << std::endl;
	std::cout << rg << " == \n" << lg << " = " << (lg == rg) << std::endl << std::endl;
	std::cout << rg << " != \n" << lg << " = " << (lg != rg) << std::endl << std::endl;

}
template<typename T>
void initObj(MatrixArr<typename T>& arg)
{
	for (IndexType i = 0; i != arg.getHeight(); i++)
		for (IndexType j = 0; j != arg.getWidth(); j++)
		{
			arg.elementSet(i, j, rand() % 10 + 0);
		}
}

void main()
{
	MatrixArr<double> a(5, 5), b(4, 5), c(5, 2), d(5, 4);
	initObj(a);
	initObj(c);
	initObj(b);
	initObj(d);
	//matrixArrTestConstructor(5, 4);
	matrixArrTestAddition(a, a);
	matrixArrTestMultiplication(a, a);
	matrixArrTestQuality(a, b);
	matrixArrTestSubtraction(c, c);
	return;
}