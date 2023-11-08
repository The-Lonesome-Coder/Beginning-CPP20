#include <algorithm>
#include <iostream>
#include <ranges>


void printVector(std::string_view message, auto& numbers)
{
    std::cout << message << ": ";
    for (int number : numbers)
    {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
}


int main()
{
    const size_t num_numbers { 20 };

    auto numbers { std::ranges::views::iota(1, 20) };

    printVector("The original set of numbers", numbers);

    auto odd_numbers{ numbers | std::ranges::views::filter([](int i) { return i % 2 != 0; }) };

    printVector("The numbers that were kept", odd_numbers);

}