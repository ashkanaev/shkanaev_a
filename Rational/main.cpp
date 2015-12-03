#include "Rational.h"

using namespace std;

void rationalTestConstructor(int num, int den)
{
	cout << "Test constructor num = " << num << " den = " << den << endl;
	Rational tmp(num, den);
	cout << "Result = " << tmp << endl << endl;
}

void rationalTestQuality(const Rational& rg, const Rational& lg)
{
	cout << "Quality Test" << endl;
	cout << rg << " == " << lg << " " << (rg == lg) << endl;
	cout << rg << " != " << lg << " " << (rg != lg) << endl;
	cout << rg << " >= " << lg << " " << (rg >= lg) << endl;
	cout << rg << " <= " << lg << " " << (rg <= lg) << endl << endl;
}

void rationalTestConstructor()
{
	cout << "Test default constructor " << endl;
	Rational tmp;
	cout << "Result " << tmp << endl << endl;
}

void rationalTestDivision(const Rational& rg, const Rational& lg)
{
	Rational tmp(rg);
	cout << "Test Division " << endl;
	cout << "(" << rg << ")/(" << lg << ") = " << rg / lg << endl;
	cout << "(" << rg << ")/=(" << lg << ") = " << (tmp /= lg) << endl << endl;
}

void rationalTestSubtraction(const Rational& rg, const Rational& lg)
{
	Rational tmp(rg);
	cout << "Test Subtraction " << endl;
	cout << "(" << rg << ")-(" << lg << ") = " << rg - lg << endl;
	cout << "(" << rg << ")-=(" << lg << ") = " << (tmp -= lg) << endl << endl;
}

void rationalTestAddition(const Rational& rg, const Rational& lg)
{
	Rational tmp(rg);
	cout << "Test Addition " << endl;
	cout << "(" << rg << ")+(" << lg << ") = " << rg + lg << endl;
	cout << "(" << rg << ")+=(" << lg << ") = " << (tmp += lg) << endl << endl;
}

void rationalTestMultiplication(const Rational& rg, const Rational& lg)
{
	Rational tmp(rg);
	cout << "Test Multiplication " << endl;
	cout << "(" << rg << ")*(" << lg << ") = " << rg * lg << endl;
	cout << "(" << rg << ")*=(" << lg << ") = " << (tmp *= lg) << endl << endl;
}

void rationalTestPreIncrement(Rational& rg)
{
	Rational tmp(rg);
	cout << "Test PreIncrement val = " << rg << " ++val = ";
	cout << ++rg << endl;
	cout << " val = " << rg << " --val = ";
	cout << --rg << endl << endl;

}

void rationalTestIncrement(Rational& rg)
{
	cout << "Test Increment val = " << rg << " val++ = ";
	rg++;
	cout << rg << endl;
	cout << "val = " << rg << "val-- = ";
	rg--;
	cout << rg << endl << endl;
}

void main()
{
	Rational a(1, 2), b (4, 6);
	rationalTestConstructor();
	rationalTestConstructor(12, 24);
	rationalTestDivision(a, b);
	rationalTestMultiplication(a, b);
	rationalTestQuality(a, b);
	rationalTestSubtraction(a, b);
	rationalTestIncrement(a);
	rationalTestPreIncrement(b);
	return;

}
