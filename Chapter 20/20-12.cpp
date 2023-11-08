#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>


bool isPrime(unsigned number)
{
    return number >= 2 && std::ranges::none_of(std::ranges::views::iota(2u, static_cast<unsigned>(std::sqrt(number) + 1)),
                                               [number](unsigned divisor) { return number % divisor == 0; });
}


int main()
{
    const unsigned limit { 1'000 };
    const unsigned perLine { 20 };

    unsigned count { 1 };

    for (auto i : std::ranges::views::iota(1) | std::ranges::views::filter(isPrime)
                                              | std::ranges::views::take_while([&limit](unsigned num) { return num < limit; })
                                              | std::ranges::views::reverse)
    {
        std::cout << i << ' ';

        if (count % perLine == 0)
        {
            std::cout << std::endl;
        }

        ++count;
    }

    return 0;
}