#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

class   bigint
{
    private:
        std::string str;

    public:
    //Othodox Canonical
    bigint();
    bigint(unsigned int num);
    bigint(const bigint& other);
    bigint& operator=(const bigint& other);
    ~bigint();
    //Addition
    bigint  operator+(const bigint& other)const;
    bigint& operator+=(const bigint& other);
    //Increment
    bigint& operator++();
    bigint  operator++(int);
    //Shift with number
    bigint  operator<<(unsigned int num)const;
    bigint& operator<<=(unsigned int num);
    bigint  operator>>(unsigned int num)const;
    bigint& operator>>=(unsigned int num);
    //Shift with object
    bigint  operator<<(const bigint& other)const;
    bigint& operator<<=(const bigint& other);
    bigint  operator>>(const bigint& other)const;
    bigint& operator>>=(const bigint& other);
    //Comparison
    bool    operator==(const bigint& other)const;
    bool    operator!=(const bigint& other)const;
    bool    operator<(const bigint& other)const;
    bool    operator<=(const bigint& other)const;
    bool    operator>(const bigint& other)const;
    bool    operator>=(const bigint& other)const;
    //Getter
    const std::string&   getStr()const;
};
//Output
std::ostream&    operator<<(std::ostream &os, const bigint& big);

#endif