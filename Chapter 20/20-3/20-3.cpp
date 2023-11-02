#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string_view>


std::vector<int> fillVector_1toN(size_t N)
{
    std::vector<int> numbers;
    for (int i { 1 }; i <= N; ++i)
        numbers.push_back(i);
    return numbers;
}


void printVector(std::string_view message, const std::vector<int>& numbers)
{
    std::cout << message << ": ";
    for (int number : numbers) std::cout << number << ' ';
    std::cout << std::endl;
}


void removeEvenNumbers(std::vector<int>& numbers)
{
    auto even = [](auto num) { return num % 2 == 1; };

    const auto first { std::stable_partition(numbers.begin(), numbers.end(), even) };

    numbers.erase(first, numbers.end());
}


int main()
{
    const size_t num_numbers { 20 };

    auto numbers { fillVector_1toN(num_numbers) };

    printVector("The original set of numbers", numbers);

    removeEvenNumbers(numbers);

    printVector("The numbers that were kept", numbers);
}