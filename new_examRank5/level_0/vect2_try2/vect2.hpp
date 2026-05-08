#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class vect2
{
	private:
		int	_x;
		int	_y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &copy);
		vect2	&operator=(const vect2 &copy);
		~vect2();

		// []
		int	&operator[](int i);
		int	operator[](int i) const;

		// addition
		vect2	operator+(const vect2 &other) const;
		vect2	&operator+=(const vect2 &other);

		// subtraction
		vect2	operator-() const;
		vect2	operator-(const vect2 &other) const;
		vect2	&operator-=(const vect2 &other);

		// multiplication
		vect2	operator*(int i) const;
		vect2	&operator*=(int i);

		// increment decrement
		vect2	&operator++();
		vect2	operator++(int);
		vect2	&operator--();
		vect2	operator--(int);

		// comparative operators
		bool	operator==(const vect2 &other) const;
		bool	operator!=(const vect2 &other) const;

};

vect2	operator*(int i, const vect2 &other);
std::ostream	&operator<<(std::ostream &os, const vect2 &other);