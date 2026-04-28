#include "bigint.hpp"

// ---------------- constructors, destructor, and getter ----------------

bigint::bigint() : _num("0") {}

bigint::bigint(unsigned int n) 
{
	std::stringstream ss;
	ss << n;
	this->_num = ss.str();
}

bigint::bigint(const bigint &copy)
{
	this->_num = copy._num;
}

bigint &bigint::operator=(const bigint &copy)
{
	if (this != &copy)
	{
		this->_num = copy._num;
	}
	return (*this);
}

bigint::~bigint() {}

std::string	bigint::getnum() const
{
	return (this->_num);
}

// ---------------- constructors, destructor, and getter ----------------

// ------------------------------ addition ------------------------------

bigint bigint::operator+(const bigint &other) const
{
    std::string a = this->_num;
    std::string b = other._num;
    std::string r;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int x = (i >= 0 ? a[i--] - '0' : 0); // if i>=0 then x = a[i--] - '0' , else x = 0
        int y = (j >= 0 ? b[j--] - '0' : 0); // if j>=0 then y = a[j--] - '0' , else y = 0
        int s = x + y + carry;

        r.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }

    std::reverse(r.begin(), r.end());

    bigint result;
    result._num = r;
    return result;
}

bigint &bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return (*this);
}

// ------------------------------ addition ------------------------------

// ----------------------------- increments -----------------------------

bigint	&bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint temp(*this);
	*this = *this + bigint(1);
	return temp;
}

// ----------------------------- increments -----------------------------

// --------------------------- shift with num ---------------------------


bigint bigint::operator<<(unsigned int n) const
{
	if (this->_num == "0")
		return *this;
	bigint r(*this);
	r._num += std::string(n, '0'); // adds n number of '0' to the end of r._num
	return r; 
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint r = *this;

    if (n >= r._num.size())
        r._num = "0";
    else
        r._num.erase(r._num.size() - n);   // erase last n digits

    return r;
}

// --------------------------- shift with num ---------------------------
