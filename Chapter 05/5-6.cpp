#include <format>
#include <iostream>
#include <vector>


int main(void)
{
    int size = 0;

    std::cout << "Please enter the size of vector: ";
    std::cin >> size;

    std::vector<int> vec(size, 0);

    // Fill vector with integers
    for (int i = 0, j = 1; i <= size; ++i, ++j)
    {
        vec[i] = j;
    }

    for (int i = 0; i < size; ++i)
    {
        if (i % 10 == 0 && i != 0)
        {
            std::cout << std::endl;
        }

        if (vec[i] % 7 == 0 || vec[i] % 13 == 0)
        {
            std::cout << std::format("{:^5} | ", "");
            continue;
        }

        std::cout << std::format("{:^5} | ", vec[i]);
    }

    return 0;
}