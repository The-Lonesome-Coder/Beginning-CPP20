#include <format>
#include <iostream>
#include <numbers>


int main(void)
{
    const auto head = "{:20} {:35} {}\n";
    const auto p_5 = "{:20} {:35} {:.5f}...\n";
    const auto p_3 = "{:20} {:35} {:.3f}...\n";

    std::cout << std::format(head, "Constant", "Description", "Approximation");
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << std::format(p_5, "std::numbers::e", "The base of the natural logarithm", std::numbers::e);
    std::cout << std::format(p_5, "std::numbers::pi", "pi", std::numbers::pi);
    std::cout << std::format(p_5, "std::numbers::sqrt2", "Square root of 2", std::numbers::sqrt2);
    std::cout << std::format(p_3, "std::numbers::phi", "The golden ration constant", std::numbers::phi);
}