#pragma once
#include <iostream>

class vect2
{
	private:
		int _x;
		int _y;
	public:
		// constructors, destructors
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &copy);
		vect2 &operator=(const vect2 &copy);
		~vect2();
		
		// []
		int	&operator[](int i);    // can we only have const ??
		const int	&operator[](int i) const;

		// addition
		vect2	operator+(const vect2 &other) const;
		vect2	&operator+=(const vect2 &other);

		// subtraction
		vect2	operator-() const;
		vect2	operator-(const vect2 &other) const;
		vect2	&operator-=(const vect2 &other);

		// multiplication
		vect2	operator*(int n) const;
		vect2	operator*(const vect2 &other) const;
		vect2	&operator*=(int n);
		vect2	&operator*=(const vect2 &other);

		// increment , decrement
		vect2	&operator++();    // ++x
		vect2	operator++(int);  // x++
		vect2	&operator--();    // --x
		vect2	operator--(int);  // x--
	
		// comparison
		bool	operator==(const vect2 &other) const;
		bool	operator!=(const vect2 &other) const;
};

// printing and (3 * vect2)
std::ostream& operator<<(std::ostream& os,const vect2 &other);
vect2	operator*(int num, const vect2 &other);

