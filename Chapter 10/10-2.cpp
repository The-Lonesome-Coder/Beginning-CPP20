#include <format>
#include <iostream>
#include <string_view>


template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}


template <typename T>
const T* larger(const T *a, const T *b)
{
    return std::string_view{a} > std::string_view{b}? a : b;
}


int main(void)
{
    int big_int = 17011983, small_int = 10;

    std::cout << std::format("Larger of {} and {} is {}\n",
                             big_int, small_int, larger(big_int, small_int));

    const auto a_string = "A", z_string = "Z";

    std::cout << "Larger of " << a_string << " and " << z_string << " is "
              << larger(a_string, z_string)
              << std::endl;
}