#include <cmath>
#include <format>
#include <iostream>
#include <vector>


int main(void)
{
    int size = 0;

    std::cout << "Please enter the size of the vector: ";
    std::cin >> size;

    auto vec = new std::vector<double>(size);

    for(int i = 0; i < size; ++i)
    {
        (*vec)[i] = 1.0 / ((i + 1) * (i + 1));
    }

    double sum = 0;

    for (auto i : *vec)
    {
        sum += i;
    }

    std::cout << std::format("The result is {}", std::sqrt(sum * 6.0))
              << std::endl;

    delete[] vec;
}