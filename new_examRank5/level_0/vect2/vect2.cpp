#include "vect2.hpp"

// ---------------- constructors, destructor, and getter ----------------

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y) : _x(x), _y(y) {}

vect2::vect2(const vect2 &copy)
{
	this->_x = copy._x;
	this->_y = copy._y;
}

vect2	&vect2::operator=(const vect2 &copy)
{
	if (this != &copy)
	{
		this->_x = copy._x;
		this->_y = copy._y;
	}
	return *this;
}
vect2::~vect2() {}

// ---------------- constructors, destructor, and getter ----------------

// --------------------------------- [] ---------------------------------

int	&vect2::operator[](int i)
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

const int &vect2::operator[](int i) const
{
	if (i == 0)
		return this->_x;
	return this->_y;
}

// --------------------------------- [] ---------------------------------

// ------------------------------ addition ------------------------------

vect2	vect2::operator+(const vect2 &other) const
{
	vect2 result(*this);
	result._x += other._x;
	result._y += other._y;
	return result;
}

vect2	&vect2::operator+=(const vect2 &other)
{
	*this = *this + other;
	return *this;
}

// ------------------------------ addition ------------------------------

// ----------------------------- subtraction -----------------------------

vect2	vect2::operator-() const
{
	vect2 result(*this);
	result._x = -this->_x;
	result._y = -this->_y;
	return result;
}

vect2	vect2::operator-(const vect2 &other) const
{
	vect2 result(*this);
	result._x -= other._x;
	result._y -= other._y;
	return result;
}

vect2	&vect2::operator-=(const vect2 &other)
{
	*this = *this - other;
	return *this;
}

// ----------------------------- subtraction -----------------------------

// --------------------------- multiplication ---------------------------

vect2	vect2::operator*(int n) const
{
	vect2 result(*this);
	result._x = this->_x * n;
	result._y = this->_y * n;
	return result;
}

vect2	vect2::operator*(const vect2 &other) const
{
	vect2 result(*this);
	result._x = this->_x * other._x;
	result._y = this->_y * other._y;
	return result;
}

vect2	&vect2::operator*=(int n)
{
	*this = *this * n;
	return *this;
}

vect2	&vect2::operator*=(const vect2 &other)
{
	*this = *this * other;
	return *this;
}

// --------------------------- multiplication ---------------------------

// ------------------------ increment, decrement ------------------------

vect2	&vect2::operator++()    // ++x
{
	*this += vect2(1, 1);
	return *this;
}

vect2	vect2::operator++(int)  // x++
{
	vect2	temp(*this);
	*this += vect2(1, 1);
	return temp;
}

vect2	&vect2::operator--()    // --x
{
	*this -= vect2(1, 1);
	return *this;
}

vect2	vect2::operator--(int)  // x--
{
	vect2	temp(*this);
	*this -= vect2(1, 1);
	return temp;
}


// ------------------------ increment, decrement ------------------------

// ----------------------------- comparison -----------------------------

bool	vect2::operator==(const vect2 &other) const
{
	if (_x == other._x && _y == other._y)
		return true;
	return false;
}

bool	vect2::operator!=(const vect2 &other) const
{
	return (!(*this == other));
}

// ----------------------------- comparison -----------------------------

// ---------------------- printing and (3 * vect2) ----------------------

std::ostream &operator<<(std::ostream& os,const vect2 &other)
{
	os << "{" << other[0] << ", " << other[1] << "}" << std::endl;
	return (os);
}

vect2	operator*(int num, const vect2 &other)
{
	vect2 temp(other);
	return (other * num);
}

// ---------------------- printing and (3 * vect2) ----------------------
