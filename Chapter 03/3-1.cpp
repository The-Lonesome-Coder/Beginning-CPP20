#include <iostream>
#include <format>


int main(void)
{
    int value = 50;

    std::cout << "Please enter an integer: ";
    std::cin >> value;

    const auto inverted{ static_cast<unsigned>(~value) };

    std::cout << std::format(" {:^34} {:^34} {:^34}\n", "value", "~value", "~value + 1");
    std::cout << std::format(" {:#034b} {:#034b} {:#034b}\n", value, inverted, inverted + 1);
    std::cout << std::format(" {:^34} {:^34} {:^34}\n", value, ~value, ~value + 1)
              << std::endl;
}