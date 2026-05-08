#include "vect2.hpp"

vect2::vect2():x(0), y(0)
{}

vect2::vect2(const vect2& copy)
{
    *this = copy;
}
vect2::vect2(int _x, int _y):x(_x), y(_y)
{}

vect2& vect2::operator=(const vect2& assign)
{
    if (this != &assign)
    {
        x = assign.x;
        y = assign.y;
    }
    return (*this);
}

vect2::~vect2()
{}

int  vect2::operator[](int index) const
{
    if (index == 0)
        return (x);
    return (y);
}

int&  vect2::operator[](int index)
{
    if (index == 0)
        return (x);
    return (y);
}

vect2 vect2::operator+(int i) const
{
    return(vect2(x + i, y + i));
}

vect2 vect2::operator-(int i) const
{
    return(vect2(x - i, y - i));
}

vect2 vect2::operator*(int i) const
{
    return(vect2(x * i, y * i));
}

vect2& vect2::operator+=(int i)
{
    x = x + i;
    y = y + i;
    return (*this);
}

vect2& vect2::operator-=(int i)
{
    x = x - i;
    y = y - i;
    return (*this);
}

vect2& vect2::operator*=(int i)
{
    x = x * i;
    y = y * i;
    return (*this);
}

vect2 vect2::operator+(const vect2& num) const
{
    return(vect2(x + num.x, y + num.y));
}

vect2 vect2::operator-(const vect2& num) const
{
    return(vect2(x - num.x, y - num.y));
}

vect2 vect2::operator*(const vect2& num) const
{
    return(vect2(x * num.x, y * num.y));
}

vect2& vect2::operator+=(const vect2& num)
{
    x = x + num.x;
    y = y + num.y;
    return (*this);
}

vect2& vect2::operator-=(const vect2& num)
{
    x = x - num.x;
    y = y - num.y;
    return (*this);
}

vect2& vect2::operator*=(const vect2& num)
{
    x = x * num.x;
    y = y * num.y;
    return (*this);
}


vect2& vect2::operator++()
{
    *this = *this + 1;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 temp(*this);
    x = x + 1;
    y = y + 1;
    return (temp);

}

vect2& vect2::operator--()
{
    *this = *this - 1;
    return (*this);
}

vect2 vect2::operator--(int)
{
    vect2 temp(*this);
    x = x - 1;
    y = y - 1;
    return (temp);
}

vect2 vect2::operator-() const
{
    return (vect2(-x, -y));
}

vect2 vect2::operator+() const
{
    return (vect2(x, y));
}

bool vect2::operator==(const vect2& num) const
{
    if (x == num.x && y == num.y)
        return (true);
    return (false);
}

bool vect2::operator!=(const vect2& num) const
{
    return(!(*this == num));
}


vect2  operator+(int i, const vect2& n)
{
   
    return (n + i);
}

vect2  operator*(int i, const vect2& n)
{
    return (n * i);
}


std::ostream& operator<<(std::ostream &os, const vect2& n)
{
    std::cout <<  "{" << n[0] << ", " << n[1] << "}";
    return (os);
}