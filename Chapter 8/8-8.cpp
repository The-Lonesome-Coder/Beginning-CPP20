#include <iostream>


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

    return y * y;
}


int main(void)
{
    for (int i = -3; i <= 3; ++i)
    {
        std::cout << power(8.0, i) << ' ';
    }

    std::cout << std::endl;

    return 0;
}