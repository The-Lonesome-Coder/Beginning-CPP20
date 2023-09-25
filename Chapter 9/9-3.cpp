#include <format>
#include <iostream>
#include <optional>
#include <span>
#include <string>
#include <string_view>


void show_data(std::span<const double> data, std::string_view title, size_t width = 10, size_t line = 5)
{
    std::cout << title << std::endl;

    for (size_t i = 0, size = data.size(); i < size; ++i)
    {
        std::cout << std::format("{:{}.6g}", data[i], width);

        if ((i + 1) % line == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << std::endl;
}


std::optional<double> smallest(std::span<const double> data)
{
    if (data.empty())
    {
        return std::nullopt;
    }

    size_t index = 0;

    for (size_t i = 1, size = data.size(); i < size; ++i)
    {
        if (data[index] > data[i])
        {
            index = i;
        }
    }

    return data[index];
}


std::span<double> shift_range(std::span<double> data, double delta)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] += delta;
    }

    return data;
}


std::optional<double> largest(std::span<const double> data)
{
    if (data.empty())
    {
        return std::nullopt;
    }

    size_t index = 0;

    for (size_t i = 1, size = data.size(); i < size; ++i)
    {
        if (data[index] < data[i])
        {
            index = i;
        }
    }

    return data[index];
}


std::span<double> scale_range(std::span<double> data, double divisor)
{
    if (!divisor)
    {
        return data;
    }

    for (size_t i = 0, size = data.size(); i < size; ++i)
    {
        data[i] /= divisor;
    }

    return data;
}


std::span<double> normalize_range(std::span<double> data)
{
    shift_range(data, -(smallest(data).value()));

    return scale_range(data, largest(data).value());
}


int main()
{
    double samples[] = {
                            11.0,  23.0,  13.0,  4.0,
                            57.0,  36.0, 317.0, 88.0,
                            9.0, 100.0, 121.0, 12.0
                       };

    show_data(samples, "Original Values");
    normalize_range(samples);
    show_data(samples, "Normalized Values", 12);
}