#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

class bigint
{
	private:
		std::string	_num;
	public:
		bigint();
		bigint(unsigned int i);
		bigint(const bigint &copy);
		bigint	&operator=(const bigint &copy);
		~bigint();

		std::string getstr() const;

		// addition 
		bigint	operator+(const bigint &other) const;
		bigint	&operator+=(const bigint &other);

		// increment
		bigint &operator++();
		bigint operator++(int);

		// bit shift with int
		bigint	operator<<(unsigned int i) const;
		bigint	operator>>(unsigned int i) const;
		bigint	&operator<<=(unsigned int i);
		bigint	&operator>>=(unsigned int i);

		// bit shift with bigint
		bigint	operator<<(const bigint &other) const;
		bigint	operator>>(const bigint &other) const;
		bigint	&operator<<=(const bigint &other);
		bigint	&operator>>=(const bigint &other);

		// comparative operators
		bool	operator<(const bigint &other) const;
		bool	operator<=(const bigint &other) const;
		bool	operator>(const bigint &other) const;
		bool	operator>=(const bigint &other) const;
		bool	operator==(const bigint &other) const;
		bool	operator!=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &other);