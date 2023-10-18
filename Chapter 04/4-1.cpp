#include <iostream>


int main(void)
{
    int num1 = 0, num2 = 0;

    std::cout << "Please enter two integers: \n";
    std::cin >> num1 >> num2;

    // if-else method
    /*
    if (num1 == num2)
    {
        std::cout << "Two numbers are the same." << std::endl;
    }
    else
    {
        std::cout << "Two numbers are not the same." << std::endl;
    }
    */

    // Conditional operator
    std::cout << ((num1 == num2) ? "Two numbers are the same." : "Two numbers are not the same.")
              << std::endl;

    return 0;
}