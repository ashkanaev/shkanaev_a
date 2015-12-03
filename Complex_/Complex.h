#include <iostream>

class Complex
{

public:
	Complex();
	Complex(double arg, double arg2);
	Complex(const Complex& arg) noexcept = default;
	~Complex() noexcept = default;

	Complex& operator+=(Complex const & arg);
	Complex& operator-=(Complex const & arg);
	Complex& operator*=(Complex const & arg);
	Complex& operator/=(Complex const & arg);

	Complex operator+(const Complex &operand2) const;
	Complex operator-(const Complex &operand2) const;
	Complex operator*(const Complex &operand2) const;
	Complex operator/(const Complex &operand2) const;
	Complex& operator=(const Complex& arg) = default;

	std::ostream & Myprint(std::ostream & arg) const;

	double getIm() const;
	double getReal() const;

	Complex  operator++();
	Complex  operator--();
	Complex  operator--(int);
	Complex  operator++(int);

private:
	double Real;
	double Im;
};

std::ostream & operator<<(std::ostream & is, Complex & arg);

bool operator==(Complex const & a, Complex const & b);
bool operator!=(Complex const & a, Complex const & b);

