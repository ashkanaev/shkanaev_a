#include "Rational.h"
#include<iostream>

using namespace std;

bool Rational::operator>(const Rational& rhs) const
{
	return (num_ * rhs.den_) > (rhs.num_ * den_);
}

bool Rational::operator<(const Rational& rhs) const
{
	return (num_ * rhs.den_) < (rhs.num_ * den_);
}

std::ostream& Rational::print(std::ostream& str) const
{
	str << num_ << "/" << den_;
	return str;
}

Rational& Rational::operator++()
{
	this->num_ += den_;
	Normalize();
	return *this;
}

Rational& Rational::operator++(int)
{
	Rational tmp(*this);
	operator++();
	return tmp;
}

Rational& Rational::operator--()
{
	this->num_ -= den_;
	Normalize();
	return *this;
}

Rational& Rational::operator--(int)
{
	Rational tmp(*this);
	operator--();
	return tmp;
}

int Rational::gcd(int a, int b)
{
	while (b ^= a ^= b ^= a %= b);
	return a;
}

Rational::Rational(int num, int den)
	:num_(num)
	, den_(den)
{
	if (den == 0)
	{
		throw domain_error("Denominator = 0!");
	}
	Normalize();
}

Rational::Rational(const int& arg)
	:Rational(arg, 1)
{
}


Rational & Rational::operator*=(const Rational & arg)
{
	num_ *= arg.num_;
	den_ *= arg.den_;
	Normalize();
	return *this;
}

Rational & Rational::operator+=(const Rational & arg)
{
	num_ = num_* arg.den_ + arg.num_*den_;
	den_ = den_ * arg.den_;
	Normalize();
	return *this;
}

Rational & Rational::operator-=(const Rational & arg)
{
	num_ = num_* arg.den_ - arg.num_*den_;
	den_ = den_ * arg.den_;
	Normalize();
	return *this;
}

Rational & Rational::operator/=(const Rational & arg)
{
	num_ *= arg.den_;
	den_ *= arg.num_;
	Normalize();
	return *this;
}

bool Rational::operator!=(const Rational& rhs) const
{
	return (num_*rhs.den_ != rhs.num_*den_);
}

bool Rational::operator==(const Rational& rhs) const
{
	return !operator!=(rhs);
}

bool Rational::operator>=(const Rational& rhs) const
{
	return (num_ * rhs.den_) >= (rhs.num_ * den_);
}

bool Rational::operator<=(const Rational& rhs) const
{
	return (num_ * rhs.den_) <= (rhs.num_ * den_);
}

void Rational::Normalize()
{
	int tmp = gcd(num_, den_);
	num_ /= tmp;
	den_ /= tmp;
}

std::ostream& operator<<(std::ostream& str, Rational& arg)
{
	arg.print(str);
	return str;
}

std::ostream& operator<<(std::ostream& str, const Rational& arg)
{
	return arg.print(str);
}

Rational operator/(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs) /= lhs;
}

Rational operator-(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs) -= lhs;
}

Rational operator*(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs) *= lhs;
}

Rational operator+(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs) += lhs;
}

