#include <iostream>

class Rational
{

public:
	Rational() noexcept = default;
	Rational(int num, int den);
	Rational(const int & arg);
	Rational(const Rational& arg) noexcept = default;
	~Rational()noexcept = default;

	Rational& operator=(const Rational& arg) = default;
	Rational& operator*=(const Rational & arg);
	Rational& operator+=(const Rational & rg);
	Rational& operator-=(const Rational & arg);
	Rational& operator/=(const Rational & arg);

	bool operator!=(const Rational& rhs) const;
	bool operator==(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;

	std::ostream& print(std::ostream& str) const;

	Rational& operator++();
	Rational& operator++(int);
	Rational& operator--();
	Rational& operator--(int);

	int gcd(int a, int b);

private:
	void Normalize();

private:
	int num_{ 0 };
	int den_{ 1 };
};

std::ostream& operator<<(std::ostream& str, Rational& arg);
std::ostream& operator<<(std::ostream& str, const Rational& arg);

Rational operator/(const Rational& rhs, const Rational& lhs);
Rational operator-(const Rational& rhs, const Rational& lhs);
Rational operator*(const Rational& rhs, const Rational& lhs);
Rational operator+(const Rational& rhs, const Rational& lhs);
