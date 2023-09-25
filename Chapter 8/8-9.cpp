#include <iostream>


inline auto mult(long double l, long double r)
{
    static size_t count = 0;

    std::cout << ++count << " multiplications" << std::endl;

    return l * r;
}


long double power(double num, const int &pow)
{
    if (pow == 0)
    {
        return 1.0;
    }
    else if (pow < 0)
    {
        return 1.0 / power(num, -pow);
    }
    else if (pow % 2)
    {
        return num * power(num, pow - 1);
    }

    const auto y = power(num, pow / 2);

    return mult(y , y);
}


int main()
{
  std::cout << power(1.5, 1000) << std::endl;
}