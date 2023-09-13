#include <compare>
#include <exception>
#include <iostream>


int main(void)
{
    int num1 = 0, comparison = 50;

    std::cout << "Please enter an integer within 1 and 100: \n";
    std::cin >> num1;

    if (num1 <= 0 || num1 > 100)
    {
        throw std::out_of_range("Input integer should be within 1 and 100.");
    }

    // Trying the three-way operator
    std::strong_ordering result = num1 <=> comparison;

    if (result < 0)
    {
        std::cout << "The input is lower than 50."
                  << std::endl;
    }
    else if (result == 0)
    {
        std::cout << "The input is 50."
                  << std::endl;
    }
    else if (result > 0)
    {
        std::cout << "The input is greater 50."
                  << std::endl;
    }

    /*
    if (num1 < 50)
    {
        std::cout << "The input is lower than 50."
                  << std::endl;
    }
    else if (num1 == 50)
    {
        std::cout << "The input is 50."
                  << std::endl;
    }
    else
    {
        std::cout << "The input is greater 50."
                  << std::endl;
    }
    */
}