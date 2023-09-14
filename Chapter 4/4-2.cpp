#include <algorithm>   // std::swap()
#include <format>
#include <iostream>


int main(void)
{
    int num1 = 0, num2 = 0;

    std::cout << "Please enter two integers: \n";
    std::cin >> num1 >> num2;

    // Check validity
    if (num1 <= 0 || num2 <= 0)
    {
        std::cout << "The input number should be a non-zero positive integer."
                  << std::endl;

        return 1;
    }

    // Set num1 to be smaller than num2
    if (num1 > num2)
    {
        std::swap(num1, num2);
    }

    // Exact multiple
    if (num2 % num1 == 0)
    {
        std::cout << std::format("{} is the exact multiple of {}.", num2, num1)
                  << std::endl;
    }
    else
    {
        std::cout << std::format("{} is not the exact multiple of {}.", num2, num1)
                  << std::endl;
    }
}