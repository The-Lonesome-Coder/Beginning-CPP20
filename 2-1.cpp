#include <iostream>
#include <format>


int main(void)
{
    unsigned int inches = 0, feet = 0;

    std::cout << "Please enter inches: " << std::endl;
    std::cin >> inches;

    // Convert
    feet = inches / 12;
    inches %= 12;

    std::cout << std::format("The result is {} feet and {} inches.", feet, inches) << std::endl;


    return 0;
}