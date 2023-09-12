#include <iostream>
#include <format>

int main()
{
    enum class Color : unsigned int
    {
        Red    = 0xFF0000u,
        Green  = 0x00FF00u,
        Blue   = 0x0000FFu,
        Yellow = 0xFFFF00u,
        Purple = 0xFF00FFu,
        Black  = 0x000000u,
        White  = 0xFFFFFFu
    };

    constexpr auto format_string
        { "The components of {:^6} are: red: {:3}, green: {:3}, blue: {:3}\n" };

    const Color yellow{ Color::Yellow };
    const Color purple{ Color::Purple };
    const Color green { Color::Green };

    std::cout << std::format(format_string, "yellow",
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Red)) >> 16,
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Green)) >> 8,
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::Blue))
    );

    std::cout << std::format(format_string, "purple",
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Red)) >> 16,
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Green)) >> 8,
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::Blue))
    );

    std::cout << std::format(format_string, "green",
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Red)) >> 16,
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Green)) >> 8,
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::Blue))
    );
}