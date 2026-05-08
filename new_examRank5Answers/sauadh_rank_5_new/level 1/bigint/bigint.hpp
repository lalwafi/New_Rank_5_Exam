#ifndef  BIGINT_HPP
#define  BIGINT_HPP

#include <iostream>
#include <sstream>

class bigint{

    private:
        std::string   str;
    public:
        bigint();
        ~bigint();
        bigint (const bigint &copy);
        bigint& operator=(const bigint &assign);
        bigint(int num);
        bigint(std::string _str);

        std::string getstr() const;


        bigint operator+(const bigint& num) const;
        bigint& operator+=(const bigint& num);

        bigint operator++(int);
        bigint& operator++();

        bigint operator<<(int num);
        bigint operator>>(int num);
        bigint& operator<<=(int num);
        bigint& operator>>=(int num);

        bigint operator<<(const bigint& num);
        bigint operator>>(const bigint& num);
        bigint& operator<<=(const bigint& num);
        bigint& operator>>=(const bigint& num);


        bool operator==(const bigint& num);
        bool operator>=(const bigint& num);
        bool operator!=(const bigint& num);
        bool operator<=(const bigint& num);
        bool operator>(const bigint& num);
        bool operator<(const bigint& num);
};

std::ostream& operator<<(std::ostream &os, const bigint& num);


#endif