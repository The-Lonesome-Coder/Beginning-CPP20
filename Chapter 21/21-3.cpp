#include <array>
#include <concepts>
#include <iostream>
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


// Odd number of elements
template <typename T, size_t N>
auto& medianOfSorted(std::span<T, N> span)
{
    static_assert(N != 0, "The median of an empty span is not defined.")

    return span[N / 2];
}


// Even number of elements
template <Averagable T, size_t N> requires (N % 2 == 0)
auto medianOfSorted(std::span<T, N> span)
{
    static_assert(N != 0, "The median of an empty span is not defined");

    return (span[N / 2 - 1] + span[N / 2]) / 2;
}