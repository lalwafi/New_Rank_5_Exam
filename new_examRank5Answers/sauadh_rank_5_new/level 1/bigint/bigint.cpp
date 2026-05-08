 #include "bigint.hpp"

 bigint::bigint():str("0")
 {}
 bigint::~bigint()
 {}
 bigint::bigint (const bigint &copy)
 {
    *this = copy;
 }

 bigint& bigint::operator=(const bigint &assign)
 {
    if (this != &assign)
    {
        str = assign.str;
    }
    return (*this);
 }

 bigint::bigint(int num)
 {
    std::stringstream ss;
    ss << num;
    str = ss.str();
 }

 std::string normalize(std::string st)
 {
    while(st[0] == '0' && st.length() > 1)
        st.erase(0, 1);
    return (st);
 }
        
 bigint::bigint(std::string _str)
 {
    if (_str.length() == 0)
        str = "0";
    else
        str = normalize(_str);
 }
        
 std::string bigint::getstr() const
 {
    return (str);
 }

 std::string reverse(std::string s)
 {
    std::string rev;
    for (int i = (int)s.length(); i > 0; i--)
    {
        rev.push_back(s[i - 1]);
    }
    return (rev);
 }

  std::string add(const bigint &num1, const bigint &num2)
  {
    std::string   n1 = reverse(num1.getstr());
    std::string   n2 = reverse(num2.getstr());
    int len1 = (int) n1.length();
    int len2 =(int) n2.length();

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while(diff > 0)
           { n2.push_back('0');
            diff--;
    }}
    if (len2 > len1)
    {
        int diff = len2 - len1;
        while(diff > 0)
           { n1.push_back('0');
            diff--;
    }}
    std::string res;
    int carry = 0;
    int   resu;

    for (int i = 0; i < (int)n1.length(); i++)
    {
        int a = n1[i] - '0';
        int b = n2[i] - '0';
        resu = a + b + carry;
        if (resu > 9)
        {
            carry = resu / 10;
            res.push_back((resu % 10 ) + '0');
        }
        else
            res.push_back(resu + '0');
    }
    if (carry != 0)
    {
        res.push_back(carry + '0');
    }
    return (reverse(res));
  }

 bigint bigint::operator+(const bigint& num) const
 {
    std::string result = add(*this, num);
    bigint temp(result);
    return (temp);
 }

 bigint& bigint::operator+=(const bigint& num)
 {
    *this = *this + num;
    return (*this);
 }

 bigint bigint::operator++(int)
 {
    bigint temp(*this);
    *this = *this + bigint(1);
    return (temp);

 }

 bigint& bigint::operator++()
 {
    *this = *this + bigint(1);
    return (*this);
 }

 bigint bigint::operator<<(int num)
 {
    bigint temp(*this);
    temp.str.append(num, '0');
    return (temp);

 }

bigint bigint::operator>>(int num)
{
    bigint temp(*this);
    int len = str.length();
    if (len <= num)
        temp.str = "0";
    else
        temp.str.erase(len-num, num);
    return (temp);
}

 bigint& bigint::operator<<=(int num)
 {
    *this = *this << num;
    return (*this);
 }

 bigint& bigint::operator>>=(int num)
 {
    *this = *this >> num;
    return (*this);
 }

  unsigned int    strtouint(std::string  str)
  {
    std::stringstream  ss(str);
    unsigned int num;
    ss >> num;
    return (num);
  }

bigint bigint::operator<<(const bigint& num)
{
    bigint n = *this << strtouint(num.str);
    return (n);

}

 bigint bigint::operator>>(const bigint& num)
 {
    bigint n = *this >> strtouint(num.str);
    return (n);
 }

 bigint& bigint::operator<<=(const bigint& num)
 {
   *this = *this << strtouint(num.str);
    return (*this);
 }

 bigint& bigint::operator>>=(const bigint& num)
 {
    *this = *this >> strtouint(num.str);
    return (*this);
 }



 bool bigint::operator==(const bigint& num)
 {
    if (this->str == num.str)
        return (true);
    return (false);
 }

 bool bigint::operator>=(const bigint& num)
 {
    return (*this > num || *this == num);
 }

 bool bigint::operator!=(const bigint& num)
 {
    return (!(*this == num));

 }
 bool bigint::operator<=(const bigint& num)
 {
    return (*this < num || *this == num);
 }
 bool bigint::operator>(const bigint& num)
 {
    if (str.length() != num.str.length())
        return (str.length() > num.str.length());
    return (str > num.str);
 }

 bool bigint::operator<(const bigint& num)
 {
    return (!(*this > num));
 }

 std::ostream& operator<<(std::ostream &os, const bigint& num)
 {
    os << num.getstr();
    return (os);
 }
