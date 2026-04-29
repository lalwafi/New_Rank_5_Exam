#include "bigint.hpp"
#include <iostream>

int main()
{
    // constructors
    const bigint a(42);      // bigint(unsigned int)
    bigint b(21);            // bigint(unsigned int)
    bigint c;                // bigint()
    bigint d(1337);          // bigint(unsigned int)
    bigint e(d);             // bigint(const bigint&)

    // printing (operator<<)
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    // addition
    std::cout << "a + b = " << a + b << std::endl;     // operator+
    std::cout << "(c += a) = " << (c += a) << std::endl; // operator+=

    // increments
    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;         // prefix ++
    std::cout << "b++ = " << b++ << std::endl;         // postfix ++

    // shift with unsigned int
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl; // operator<< (uint)
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;             // operator<<= (uint)
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl; // operator>>= (bigint)

    // printing again
    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    // comparisons
    std::cout << std::boolalpha;
    std::cout << "(d < a) = " << (d < a) << std::endl;   // operator<
    std::cout << "(d <= a) = " << (d <= a) << std::endl; // operator<=
    std::cout << "(d > a) = " << (d > a) << std::endl;   // operator>
    std::cout << "(d >= a) = " << (d >= a) << std::endl; // operator>=
    std::cout << "(d == a) = " << (d == a) << std::endl; // operator==
    std::cout << "(d != a) = " << (d != a) << std::endl; // operator!=
}
