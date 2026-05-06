#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

class bigint
{
	private:
		std::string _num;
	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint &copy);
		bigint &operator=(const bigint &copy);
		~bigint();

		// getter
		std::string getStr() const;
		
		// addition
		bigint operator+(const bigint &other) const; 
		bigint &operator+=(const bigint &other);

		// increments
		bigint &operator++(); // ++x
		bigint operator++(int); // x++

		// shift with num
		bigint operator<<(unsigned int n) const;
		bigint operator>>(unsigned int n) const;
		bigint operator<<=(unsigned int n);
		bigint operator>>=(unsigned int n);

		// shift with object
		unsigned int stringToUInt(const bigint &other) const;

		bigint operator<<(const bigint &other) const;
		bigint operator>>(const bigint &other) const;
		bigint operator<<=(const bigint &other);
		bigint operator>>=(const bigint &other);

		// == != < > <= >=
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &other);