#include "vect2.hpp"
#include <iostream>

int main()
{
    vect2 v1;                 // vect2() default constructor
    vect2 v2(1, 2);           // vect2(int,int)
    const vect2 v3(v2);       // copy constructor
    vect2 v4 = v2;            // operator= or copy constructor

    std::cout << "v1: " << v1 << std::endl;                 // operator<<
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl; // operator[]
    std::cout << "v2: " << v2 << std::endl;                 // operator<<
    std::cout << "v3: " << v3 << std::endl;                 // operator<<
    std::cout << "v4: " << v4 << std::endl;                 // operator<<

    std::cout << v4++ << std::endl; // operator++(int) postfix
    std::cout << ++v4 << std::endl; // operator++() prefix
    std::cout << v4-- << std::endl; // operator--(int) postfix
    std::cout << --v4 << std::endl; // operator--() prefix

    v2 += v3;                // operator+=(vect2)
    v1 -= v2;                // operator-=(vect2)

    v2 = v3 + v3 * 2;        // operator*(int), operator+(vect2), operator=
    v2 = 3 * v2;             // global operator*(int, vect2)

    v2 += v2 += v3;          // chained operator+=

    v1 *= 42;                // operator*=(int)

    v1 = v1 - v1 + v1;       // operator-(vect2), operator+(vect2), operator=

    std::cout << "v1: " << v1 << std::endl;   // operator<<
    std::cout << "v2: " << v2 << std::endl;   // operator<<
    std::cout << "-v2: " << -v2 << std::endl; // unary operator-()

    std::cout << "v1[1]: " << v1[1] << std::endl; // operator[]
    v1[1] = 12;                                   // operator[] non-const
    std::cout << "v1[1]: " << v1[1] << std::endl; // operator[]

    std::cout << "v3[1]: " << v3[1] << std::endl; // operator[] const

    std::cout << "v1 == v3: " << (v1 == v3) << std::endl; // operator==
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl; // operator==
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl; // operator!=
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl; // operator!=
}
