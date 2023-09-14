#include <cmath>
#include <iostream>


int main(void)
{
    int limit = 0;

    std::cout << "Please enter a limit: ";
    std::cin >> limit;

    for (int i = 1; i <= limit; ++i)
    {
        std::cout << std::pow(i, 2) << '\n';
    }

    std::cout << std::endl;

    return 0;
}