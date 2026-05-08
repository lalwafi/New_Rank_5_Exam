#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{

    private:
        int x;
        int y;
    public:
        vect2();
        vect2(int _x, int _y);
        vect2(const vect2& copy);
        vect2& operator=(const vect2& assign);
        ~vect2();

        int  operator[](int index) const;
        int&  operator[](int index);

        
        vect2 operator+(int i) const;
        vect2 operator-(int i) const;
        vect2 operator*(int i) const;

        vect2& operator+=(int i);
        vect2& operator-=(int i);
        vect2& operator*=(int i);

        vect2 operator+(const vect2& num) const;
        vect2 operator-(const vect2& num) const;
        vect2 operator*(const vect2& num) const;

        vect2& operator+=(const vect2& num);
        vect2& operator-=(const vect2& num);
        vect2& operator*=(const vect2& num);


        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);

        vect2 operator-() const;
        vect2 operator+() const;

        bool operator==(const vect2& num) const;
        bool operator!=(const vect2& num) const;

};

vect2  operator+(int i, const vect2& n);
vect2  operator*(int i, const vect2& n);


std::ostream& operator<<(std::ostream &os, const vect2& n);


#endif