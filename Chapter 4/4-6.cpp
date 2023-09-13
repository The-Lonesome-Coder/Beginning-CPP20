#include <format>
#include <iostream>



int main(void)
{
    int number = 0;

    constexpr auto response = "The number is greater than {} but less than or equal to {}.";

    std::cout << "Please enter an integer: ";
    std::cin >> number;

    if (number <= 20)
    {
        std::cout << "The number is less than or equal to 20."
                  << std::endl;
    }
    else if (number > 20 && number <= 30)
    {
        std::cout << std::format(response, 20, 30)
                  << std::endl;
    }
    else if (number > 30 && number <= 100)
    {
        std::cout << std::format(response, 30, 100)
                  << std::endl;
    }
    else
    {
        std::cout << "The number is greater than 100."
                  << std::endl;
    }

    return 0;
}