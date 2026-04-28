#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>

class vect2
{
	private:
		int	x;
		int	y;
	public:
		vect2();
		vect2(int a, int b);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		int&	operator[](int num);
		const int&	operator[](int num)const;
		vect2	operator-()const;
		vect2	operator*(int n)const;
		vect2&	operator*=(int n);
		vect2	operator+(const vect2& other)const;
		vect2	operator-(const vect2& other)const;
		vect2&	operator+=(const vect2& other);
		vect2&	operator-=(const vect2& other);
		vect2	operator*(const vect2& other)const;
		vect2&	operator*=(const vect2& other);
		vect2&	operator++();
		vect2	operator++(int);
		vect2&	operator--();
		vect2	operator--(int);
		bool	operator==(const vect2& other)const;
		bool	operator!=(const vect2& other)const;
};

vect2	operator*(int n, const vect2& other);
std::ostream&	operator<<(std::ostream& os, const vect2& obj);

#endif