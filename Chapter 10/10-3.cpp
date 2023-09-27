#include <iostream>
#include <string>


template <typename T>
T plus(const T &v1, const T &v2)
{
    return v1 + v2;
}


template<typename T>
T plus(const T *v1, const T *v2)
{
    return *v1 + *v2;
}


std::string plus(const char* a, const char* b)
{
  return std::string{a} + b;
}


int main()
{
    int n = plus(3, 4);
    std::cout << "plus(3, 4) returns " << n << std::endl;

    double d = plus(3.2, 4.2);
    std::cout << "plus(3.2, 4.2) returns " << d << std::endl;

    std::string s1 = "aaa";
    std::string s2 = "bbb";

    auto s3 = plus(s1, s2);

    std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
    std::cout << "plus(s1, s2) returns " << s3 << std::endl;

    std::string s =  plus("he", "llo");
    std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
}