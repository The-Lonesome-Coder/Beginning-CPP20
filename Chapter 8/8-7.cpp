#include <iostream>


int fibonacci(const unsigned long long &num)
{
    if (num <= 1)
    {
        return num;
    }

    return fibonacci(num - 1) + fibonacci (num - 2);

}


int main(void)
{
    unsigned long long input = 0;

    std::cout << "Please enter an integer: ";
    std::cin >> input;

    for (int i = 1; i <= input; ++i)
    {
        std::cout << fibonacci(i) << ' ';

        if (i % 11 == 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}