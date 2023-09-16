#include <array>
#include <iostream>


int main(void)
{
    std::array<unsigned long long, 93> fibonacci = {1, 1};

    for (int i = 2; i < 93 ; ++i)
    {
        fibonacci[i] = fibonacci[i - 2] + fibonacci [i - 1];
    }

    for (int i = 0, size = fibonacci.size(); i < size; ++i)
    {
        std::cout << fibonacci[i] << '\n';
    }

    std::cout << std::endl;

    return 0;
}