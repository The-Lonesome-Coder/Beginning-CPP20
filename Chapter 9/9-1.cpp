#include <iostream>
#include <optional>
#include <string>
#include <string_view>


std::optional<size_t> find_last(std::string_view str, char to_find, std::optional<size_t> start = std::nullopt)
{
    if (str.empty())
    {
        return std::nullopt;
    }

    size_t index = start.value_or(str.size() - 1);

    while (true)
    {
        if (str[index] == to_find)
        {
            return index;
        }

        if (index == 0)
        {
            return std::nullopt;
        }

        --index;
    }
}


int main(void)
{
    const auto string = "Growing old is mandatory; growing up is optional.";

    const std::optional<size_t> found_a = find_last(string, 'a');

    if (found_a)
    {
        std::cout << "Found the last a at index " << *found_a << std::endl;
    }

    const auto found_b = find_last(string, 'b');

    if (found_b.has_value())
    {
        std::cout << "Found the last b at index " << found_b.value() << std::endl;
    }

    const auto found_early_i = find_last(string, 'i', 10);

    if (found_early_i != std::nullopt)
    {
        std::cout << "Found an early i at index " << found_early_i.value() << std::endl;
    }

    return 0;
}