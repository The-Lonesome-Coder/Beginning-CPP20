#include <format>
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>


template <typename T, typename ForwardIt>
std::optional<T> average(ForwardIt begin, ForwardIt end)
{
    const auto count { std::distance(begin, end) };

    const auto sum { std::accumulate(begin, end, T {})};

    return count ? std::optional<T> { sum / count } : std::nullopt;
}




int main()
{
    std::vector<int> vec(20);
    std::iota(vec.begin(), vec.end(), 1);

    std::cout << *average<double>(vec.begin(), vec.end()) << std::endl;
}