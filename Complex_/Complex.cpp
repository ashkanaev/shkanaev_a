#include "Complex.h"

Complex::Complex()
	:Real(0)
	, Im(0)
{
}

Complex::Complex(double arg, double arg2)
	: Real(arg)
	, Im(arg2)
{
}

Complex& Complex::operator+=(Complex const & arg2)
{
	Real += arg2.Real;
	Im += arg2.Im;
	return *this;
}

Complex& Complex::operator-=(Complex const & arg2)
{
	Real -= arg2.Real;
	Im - +arg2.Im;
	return *this;
}

Complex & Complex::operator*=(Complex const & arg)
{
	double tmp(Real);
	this->Real = Real*arg.Real - Im*arg.Im;
	this->Im = Im*arg.Real + tmp*arg.Im;
	return *this;
}
Complex & Complex::operator/=(Complex const & arg)
{
	double tmp(Real);
	this->Real = (Real*arg.Real + Im*arg.Im) / (arg.Real*arg.Real + arg.Im * arg.Im);
	this->Im = (Im*arg.Real - tmp*arg.Im) / (arg.Real*arg.Real + arg.Im*arg.Im);
	return *this;
}

Complex Complex::operator+(const Complex &arg) const
{
	return Complex(Real + arg.Real, Im + arg.Im);
}

Complex Complex::operator-(const Complex &arg) const
{
	return Complex(Real - arg.Real, Im - arg.Im);
}

Complex Complex::operator*(const Complex &arg) const
{
	return Complex(Real*arg.Real - Im*arg.Im, Im*arg.Real + Real*arg.Im);
}

Complex Complex::operator/(const Complex &arg) const
{
	return Complex((Real*arg.Real + Im*arg.Im) / (arg.Real*arg.Real + arg.Im * arg.Im), (Im*arg.Real - Real*arg.Im) / (arg.Real*arg.Real + arg.Im*arg.Im));
}


std::ostream & Complex::Myprint(std::ostream & arg) const
{
	arg << Real << "+" << Im << "i";
	return  arg;
}

Complex  Complex::operator++()
{
	this->Real++;
	return *this;
}


Complex  Complex::operator--()
{
	this->Real--;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex tmp(*this);
	operator++();
	return tmp;
}

Complex Complex::operator--(int)
{
	Complex tmp(*this);
	operator--();
	return tmp;
}


std::ostream & operator << (std::ostream & is, Complex & arg)
{
	return arg.Myprint(is);
}

double Complex::getIm() const { return Im; }

double Complex::getReal()  const { return Real; }

bool operator==(Complex const & a, Complex const & b)
{
	return (a.getIm() == b.getIm() && b.getReal() == a.getReal());
}

bool operator!=(Complex const & a, Complex const & b) { return !(a == b); }