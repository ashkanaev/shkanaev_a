#include  "R3Vector.h"

using namespace std;

void r3VectorTestConstructor()
{
	cout << "Test  constructor R3Vector()" << endl;
	R3Vector tmp;
	cout << "Result " << tmp << endl;
}

void r3VectorTestConstructor(const R3Vector& arg)
{
	cout << "Test  constructor R3Vector(const R3Vector& arg)" << endl;
	R3Vector tmp(arg);
	cout << "Result " << tmp << endl;
}

void r3VectorTestQuality(const R3Vector& rg, const R3Vector& lg)
{
	cout << " Test operator== " << endl;
	cout << rg << " == " << lg << " = " << (lg == rg) << endl << endl;
	cout << rg << " != " << lg << " = " << (lg != rg) << endl << endl;

}

void r3VectorTestDivision(const R3Vector& rg, const R3Vector& lg)
{
	R3Vector tmp(rg);
	cout << "Test Operator / & /= " << endl;
	cout << rg << " / " << lg << " = " << rg / lg << endl;
	cout << rg << " /= " << lg << " = " << (tmp /= lg) << endl << endl;
}

void r3VectorTestSubtraction(const R3Vector& rg, const R3Vector& lg)
{
	R3Vector tmp(rg);
	cout << "Test Operator - & -= " << endl;
	cout << rg << " - " << lg << " = " << rg - lg << endl;
	cout << tmp << " -= " << lg << " = " << (tmp -= lg) << endl << endl;
}

void r3VectorTestAddition(const R3Vector& rg, const R3Vector& lg)
{
	R3Vector tmp(rg);
	cout << "Test Operator + & += " << endl;
	cout << rg << " + " << lg << " = " << rg + lg << endl;
	cout << tmp << " += " << lg << " = " << (tmp += lg) << endl << endl;
}

void r3VectorTestMultiplication(const R3Vector& rg, const R3Vector& lg)
{
	R3Vector tmp(rg);
	cout << "Test Operator * & *= " << endl;
	cout << rg << " * " << lg << " = " << rg * lg << endl;
	cout << tmp << " *= " << lg << " = " << (tmp *= lg) << endl << endl;
}

void r3VectorTestPreIncrement(R3Vector& rg)
{
	cout << "Test operator++(int) & operator--(int)" << endl;
	cout << "++ " << rg;
	++rg;
	cout << " = " << rg << endl;
	cout << "-- " << rg;
	--rg;
	cout << " = " << rg << endl;
}

void r3VectorTestIncrement(R3Vector& rg)
{
	cout << "Test operator++() & operator--()" << endl;
	cout << "++ " << rg;
	rg++;
	cout << " = " << rg << endl;
	cout << "-- " << rg;
	rg++;
	cout << " = " << rg << endl;
}


int main()
{
	R3Vector a(3, 4, 5);
	R3Vector b(3, 4, 6);

	r3VectorTestConstructor();
	r3VectorTestSubtraction(a, b);
	r3VectorTestAddition(a, b);
	r3VectorTestDivision(a, b);
	r3VectorTestMultiplication(a, b);
	r3VectorTestIncrement(a);
	r3VectorTestPreIncrement(b);
	r3VectorTestQuality(a, b);

	return 0;
}