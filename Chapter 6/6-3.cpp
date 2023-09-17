#include <array>
#include <cmath>
#include <format>
#include <iostream>


int main(void)
{
    int size = 0;

    std::cout << "Please enter the size of the array: ";
    std::cin >> size;

    auto arr = new double[size];

    for (int i = 0; i < size; ++i)
    {
        *(arr + i) = 1.0 / ((i + 1) * (i + 1));
    }

    double sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    std::cout << std::format("The result is {}", std::sqrt(sum * 6.0))
              << std::endl;

    delete[] arr;
}