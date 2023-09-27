#include <iostream>
#include <string_view>


template <typename T>
constexpr decltype(auto) my_clamp(const T &value, const T &low, const T &high)
{
    return (value < low) ? low : (value > high) ? high : value;
}


int main(void)
{
    constexpr int num = 10;

    std::string_view test = "Hello", word1 = "A", word2 = "L";

    std::cout << my_clamp(num, 0, 9) << std::endl;

    std::cout << my_clamp(test, word1, word2) << std::endl;

    return 0;
}