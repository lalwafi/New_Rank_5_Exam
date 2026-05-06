#include "bigint.hpp"

bigint::bigint() : _num("0") {}

bigint::bigint(unsigned int i)
{
	std::stringstream ss;
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
	return (this->_num);
}

// ------------------------- addition -------------------------

std::string	reverse(const std::string str)
{
	std::string revstr;
	// std::cout << "str = " << str << std::endl;
	for (size_t i = str.length(); i > 0; i--)
		revstr.push_back(str[i - 1]);
	// std::cout << "revstr = " << revstr << std::endl;
	return (revstr);
}

std::string addition(const bigint &obj1, const bigint &obj2)
{
	std::string str1 = reverse(obj1.getstr());
	std::string str2 = reverse(obj2.getstr());
	std::string res;
	size_t len1 = str1.length();
	size_t len2 = str2.length();


	// std::cout << "len1 = " << len1 << std::endl;
	// std::cout << "len2 = " << len2 << std::endl;


	if (len1 > len2)
	{
		size_t dif = len1 - len2;
		while (dif-- > 0)
			str2.push_back('0');
	}
	if (len1 < len2)
	{
		size_t dif = len2 - len1;
		while (dif-- > 0)
			str1.push_back('0');
	}
	// std::cout << "str1 = " << str1 << std::endl;
	// std::cout << "str2 = " << str2 << std::endl;


	size_t len = str1.length();
	int x = 0;
	int y = 0;
	int carry = 0;
	int r = 0;
	for (size_t i = 0; i < len; i++)
	{
		x = str1[i] - '0';
		y = str2[i] - '0';
		r = x + y + carry;
		carry = r / 10;
		res.push_back((r % 10) + '0');
	}
	if (carry != 0)
		res.push_back((r % 10) + '0');
	res = reverse(res);
	return res;
}

bigint	bigint::operator+(const bigint &other) const
{
	bigint res;
	res._num = addition(*this, other);
	return res;
}

bigint	&bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return *this;
}


// ------------------------- addition -------------------------

// ------------------------- increment -------------------------

bigint &bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp(*this);
	*this += bigint(1);
	return temp;
}

// ------------------------- increment -------------------------

// --------------------- bit shift with int ---------------------

bigint	bigint::operator<<(unsigned int i) const
{
	bigint temp(*this);

	temp._num.insert(temp._num.length(), i, '0');
	return temp;
}

bigint	bigint::operator>>(unsigned int i) const
{
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

// --------------------- bit shift with int ---------------------

// -------------------- bit shift with bigint --------------------

unsigned int	strtouint(std::string str)
{
	std::stringstream ss(str);
	unsigned int i;
	ss >> i;
	return i;
}

bigint	bigint::operator<<(const bigint &other) const
{
	return (*this << strtouint(other._num));
}

bigint	bigint::operator>>(const bigint &other) const
{
	return (*this >> strtouint(other._num));
}

bigint	&bigint::operator<<=(const bigint &other)
{
	return (*this <<= strtouint(other._num));
}

bigint	&bigint::operator>>=(const bigint &other)
{
	return (*this >>= strtouint(other._num));
}

// -------------------- bit shift with bigint --------------------

// -------------------- comparative operators --------------------

bool	bigint::operator<(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num < other._num)
		return true;
	return false;
}

bool	bigint::operator<=(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num <= other._num)
		return true;
	return false;
}

bool	bigint::operator>(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num > other._num)
		return true;
	return false;
}

bool	bigint::operator>=(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num >= other._num)
		return true;
	return false;
}

bool	bigint::operator==(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num == other._num)
		return true;
	return false;
}

bool	bigint::operator!=(const bigint &other) const
{
	std::cout << "d = " << this->_num << " , a = " << other._num << std::endl;
	if (this->_num != other._num)
		return true;
	return false;
}

// -------------------- comparative operators --------------------

std::ostream	&operator<<(std::ostream &os, const bigint &other)
{
	os << other.getstr();
	return os;
}