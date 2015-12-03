#include "Complex.h"

using namespace std;

void complexTestIncrement(Complex& a, Complex& b)
{
	std::cout << "complexTestIncrement" << std::endl;
	std::cout << a << " = a, a++ = " << a++ << std::endl;
	std::cout << a << " = a, a-- = " << a-- << std::endl << std::endl;
}

void complexTestConstructor()
{
	Complex Tmp = Complex();
	std::cout << "complexTestConstructor" << std::endl;

	std::cout << "Real = " << Tmp.getReal() << " Im = " << Tmp.getReal() << std::endl << std::endl;
}

void complexTestConstructor(double  arg1, double  arg2)
{
	Complex Tmp(arg1, arg2);
	std::cout << "complexTestConstructor" << std::endl;
	std::cout << "Real = " << Tmp.getReal() << " Im = " << Tmp.getReal() << std::endl << std::endl;
}

void complexTestConstructor(int  arg1, int arg2)
{
	Complex Tmp(arg1, arg2);
	std::cout << "complexTestConstructor" << std::endl;
	std::cout << "Real = " << Tmp.getReal() << " Im = " << Tmp.getReal() << std::endl << std::endl;
}

void complexTestSum(Complex & a, Complex & b)
{
	Complex tmp(a);
	std::cout << "complexTestSum" << std::endl;
	std::cout << a << " + " << b << " = " << tmp + b << std::endl;
	std::cout << a << " += " << b << " a = " << (a += b) << std::endl << std::endl;
}

void complexTestSubtraction(Complex & a, Complex & b)
{
	Complex tmp(a);
	std::cout << "complexTestSubtraction" << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << tmp << " - " << b << " a = " << (a -= b) << std::endl << std::endl;
}

void complexTestMultiplication(Complex & a, Complex & b)
{
	Complex tmp(a);
	std::cout << "complexTestMultiplication" << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << tmp << " *= " << b << " = " << (a *= b) << std::endl << std::endl;
}
void complexTestDivision(Complex & a, Complex & b)
{
	Complex tmp(a);
	std::cout << "complexTestDivision" << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
	std::cout << tmp << " /= " << b << "a = " << (a /= b) << std::endl << std::endl;
}

void complexTestQuality(Complex & a, Complex & b)
{
	std::cout << "complexTestQuality" << std::endl;

	std::cout << a << " == " << b << " = " << (a == b) << std::endl;
	std::cout << a << " != " << b << " = " << (a != b) << std::endl << std::endl;
}
void complexTestPreIncrement(Complex & a, Complex & b)
{
	std::cout << "complexTestPreIncrement" << std::endl;
	std::cout << a << " = a, ++a =";
	++a;
	std::cout << a << std::endl;
	std::cout << a << " = a, --a =";
	--a;
	std::cout << a << std::endl << std::endl;
}

void main()
{
	Complex a(3, 4), b(3, 5);

	complexTestConstructor();
	complexTestQuality(a, b);
	complexTestConstructor(3, 4);
	complexTestDivision(a, b);
	complexTestSubtraction(a, b);
	complexTestMultiplication(a, b);
	complexTestPreIncrement(a, b);
	complexTestIncrement(a, b);
}