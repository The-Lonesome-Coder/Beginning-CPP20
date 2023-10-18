#include <array>
#include <format>
#include <iostream>
#include <memory>


int main(void)
{
    const int size = 50;

    std::array<int, size> odd {};

    for (int i = 0; i < size; ++i)
    {
        odd[i] = i * 2 + 1;
    }

    int* pointer = &odd.front();

    for (int i = 0; i < size; ++i)
    {
        std::cout << std::format("{:^2} | ", *(pointer + i));

        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    std::cout << "-------------------------------------------------"
              << std::endl;

    pointer = &odd.back();

    for (int i = 0; i < size; ++i)
    {
        std::cout << std::format("{:^2} | ", *(pointer - i));

        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}