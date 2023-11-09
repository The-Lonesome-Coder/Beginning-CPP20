#include <array>
#include <concepts>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <span>


template <typename T>
    concept Averagable = requires (const T x, const T y, T z, const int i)
    {
        { x + y }  -> std::same_as<T>;
        { x - y }  -> std::same_as<T>;
        { z += y } -> std::same_as<T&>;
        { z -= y } -> std::same_as<T&>;
        { x / i }  -> std::same_as<T>;
        { x * i }  -> std::same_as<T>;
        { z /= i } -> std::same_as<T&>;
        { z *= i } -> std::same_as<T&>;
    };


template <std::ranges::sized_range Range>
    requires std::ranges::input_range<Range>
auto& medianOfSorted(Range&& range)
{
    auto iter { std::ranges::begin(range) };

    std::ranges::advance(iter, std::ranges::size(range) / 2);

    return *iter;
}


template <std::ranges::sized_range Range>
    requires std::ranges::forward_range<Range>
             && Averagable<std::ranges::range_value_t<Range>>
auto medianOfSorted(Range&& range)
{
    const auto N { std::ranges::size(range) };

    auto iter { std::ranges::begin(range) };

    if (N % 2 == 0)
    {
        std::ranges::advance(iter, N / 2 - 1);
        const auto& value { *iter };
        std::ranges::advance(iter, 1);

        return (value + *iter) / 2;
    }
    else
    {
        std::ranges::advance(iter, N / 2);

        return *iter;
    }
}