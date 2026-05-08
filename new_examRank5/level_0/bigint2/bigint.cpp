#include "bigint.hpp"

bigint::bigint() : _num("0") {}

bigint::bigint(unsigned int i) 
{
	std::stringstream	ss;
	ss << i;
	this->_num = ss.str();
}

bigint::bigint(const bigint &copy) : _num(copy._num) {}

bigint	&bigint::operator=(const bigint &copy)
{
	if (this != &copy)
		this->_num = copy._num;
	return *this;
}

bigint::~bigint() {}

std::string	bigint::getstr() const
{
	return this->_num;
}

// ------------------- addition -------------------

std::string	reverse(std::string str)
{
	std::string revstr;
	for (size_t i = str.length(); i > 0; i--)
		revstr.push_back(str[i - 1]);
	return revstr;
}

std::string	addition(const bigint &obj1, const bigint &obj2)
{
	std::string str1 = reverse(obj1.getstr());
	std::string str2 = reverse(obj2.getstr());
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	
	if (len1 > len2)
	{
		size_t diff = len1 - len2;
		while (diff > 0)
		{
			str2.push_back('0');
			diff--;
		}
	}
	if (len1 < len2)
	{
		size_t diff = len2 - len1;;
		while (diff > 0)
		{
			str1.push_back('0');
			diff--;
		}
	}

	size_t len = str1.length();
	std::string	newstr;
	unsigned int	x, y, r;
	unsigned int	carry = 0;
	for (size_t	i = 0; i < len; i++)
	{
		x = str1[i] - '0';
		y = str2[i] - '0';
		r = x + y + carry;
		newstr.push_back((r % 10) + '0');
		carry = r / 10;
	}
	if (carry != 0)
		newstr.push_back(carry + '0');
	
	return (reverse(newstr));
}

bigint	bigint::operator+(const bigint &other) const
{
	bigint temp(*this);
	temp._num = addition(*this, other);
	return temp;
}

bigint	&bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return *this;
}

// ------------------- addition -------------------

// ------------------- increment -------------------

bigint	&bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint temp(*this);
	*this += bigint(1);
	return temp;
}

// ------------------- increment -------------------

// ------------------- bit shift with int -------------------

bigint	bigint::operator<<(unsigned int i) const
{
	bigint	temp(*this);
	temp._num.insert(temp._num.end(), i, '0');
	return temp;
}

bigint	bigint::operator>>(unsigned int i) const
{
	if (this->_num.length() < i)
		return (bigint(0));
	bigint temp(*this);
	temp._num.erase(temp._num.length() - i, i);
	return temp;
}

bigint	&bigint::operator<<=(unsigned int i)
{
	*this = *this << i;
	return *this;
}

bigint	&bigint::operator>>=(unsigned int i)
{
	*this = *this >> i;
	return *this;
}

// ------------------- bit shift with int -------------------

// ------------------- bit shift with obj -------------------

unsigned int	strToUInt(std::string str)
{
	std::stringstream ss(str);
	unsigned int i;
	ss >> i;
	return i;
}

bigint	bigint::operator<<(const bigint &other) const
{
	bigint temp(*this);
	temp <<= strToUInt(other._num);
	return temp;
}

bigint	bigint::operator>>(const bigint &other) const
{
	bigint temp(*this);
	temp >>= strToUInt(other._num);
	return temp;
}

bigint	&bigint::operator<<=(const bigint &other)
{
	*this <<= strToUInt(other._num);
	return *this;
}

bigint	&bigint::operator>>=(const bigint &other)
{
	*this >>= strToUInt(other._num);
	return *this;
}

// ------------------- bit shift with obj -------------------

// ------------------- comparative operators -------------------

bool	bigint::operator<(const bigint &other) const
{
	size_t	len1 = this->_num.length();
	size_t	len2 = other._num.length();
	if (len1 != len2)
		return (len1 < len2);
	return (this->_num < other._num);
}

bool	bigint::operator<=(const bigint &other) const
{
	return (this->_num == other._num || *this < other);
}

bool	bigint::operator>(const bigint &other) const
{
	size_t	len1 = this->_num.length();
	size_t	len2 = other._num.length();
	if (len1 != len2)
		return (len1 > len2);
	return (this->_num > other._num);
}

bool	bigint::operator>=(const bigint &other) const
{
	return (this->_num == other._num || *this > other);
}

bool	bigint::operator==(const bigint &other) const
{
	return (this->_num == other._num);
}

bool	bigint::operator!=(const bigint &other) const
{
	return (this->_num != other._num);
}

// ------------------- comparative operators -------------------

std::ostream	&operator<<(std::ostream &os, const bigint &other)
{
	os << other.getstr();
	return os;
}