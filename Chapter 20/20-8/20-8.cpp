#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>


// Random number generator
auto generator()
{
    std::random_device rndDevice;
    std::mt19937 engine {rndDevice()};
    std::uniform_int_distribution<int> dist {1, 100};

    auto gen = [&dist, &engine]() { return dist(engine); };

    return gen;
}


// Fill vector with random numbers
std::vector<int> fillVector(size_t size)
{
    std::vector<int> numbers(size);

    std::ranges::generate(numbers, generator());

    return numbers;
}


void print(std::vector<int> nums)
{
    for (size_t i { 0 }, size { nums.size() }; i < size; ++i)
    {
        if (i != 0 && i % 10 == 0)
        {
            std::cout << std::endl;
        }

        std::cout << nums[i] << ' ';
    }

    std::cout << "\n================================";
    std::cout << std::endl;
}


int main()
{
    size_t size { 1000 };

    std::vector<int> num { fillVector(size) };

    print(num);

    std::ranges::sort(num);
    const auto [first, last] = std::ranges::unique(num.begin(), num.end());
    num.erase(first, last);

    print(num);
}