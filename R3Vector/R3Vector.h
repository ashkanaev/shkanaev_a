#include<iostream>

class R3Vector
{

public:
	R3Vector()noexcept = default;
	R3Vector(const double& x, const double& y, const double& z);
	R3Vector(const R3Vector&) noexcept = default;

	double rX() const { return _data[0]; }
	double rY() const { return _data[1]; }
	double rZ() const { return _data[2]; }

	double& X() { return _data[0]; }
	double& Y() { return _data[1]; }
	double& Z() { return _data[2]; }

	R3Vector& operator++();
	R3Vector& operator--();
	R3Vector operator++(int);
	R3Vector operator--(int);

	~R3Vector()noexcept = default;

	R3Vector& operator=(const R3Vector&) noexcept = default;
	R3Vector& operator+=(const R3Vector& rhs);
	R3Vector& operator/=(const R3Vector& rhs);
	R3Vector& operator*=(const R3Vector& rhs);
	R3Vector& operator-=(const R3Vector& rhs);

	bool operator!=(const R3Vector& rhs) const;
	bool operator==(const R3Vector& rhs) const;

	std::ostream& print(std::ostream& arg) const;

private:
	static const ptrdiff_t capacity{ 3 };
	double _data[capacity] = { 0 };

};

std::ostream& operator<<(std::ostream& arg, const R3Vector& r);
R3Vector operator+(const R3Vector& rhs, const R3Vector& lhs);
R3Vector operator-(const R3Vector& rhs, const R3Vector& lhs);
R3Vector operator*(const R3Vector& rhs, const R3Vector& lhs);
R3Vector operator/(const R3Vector& rhs, const R3Vector& lhs);