#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <span>


void show_data(std::span<int> data, std::string_view title = "Data Values", size_t width = 10, size_t line = 5)
{
    std::cout << title << std::endl;

    for (size_t i = 0, size = data.size(); i < size; ++i)
    {
        std::cout << std::format("{:{}}", data[i], width);

        if ((i + 1) % line == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << std::endl;
}


int main()
{
    int samples[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    show_data(samples);
    show_data(samples, "Samples");
    show_data(samples, "Samples", 6);
    show_data(samples, "Samples", 8, 4);
}