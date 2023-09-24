#include <string>


const int plus(const int &num1, const int &num2)
{
    return num1 + num2;
}


const double plus(const double &num1, const double &num2)
{
    return num1 + num2;
}


const std::string plus(const std::string &str1, const std::string &str2)
{
    return str1 + str2;
}


/**
 * The code - const auto d = plus(3, 4.2); would not work, because the compiler
 * could not determine which overloaded function to call.
*/