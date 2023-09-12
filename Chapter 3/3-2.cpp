#include <iostream>
#include <format>


int main(void)
{
    int foot_to_inch = 12;

    double s_len = 0, s_dep = 0;
    int b_len = 0;

    std::cout << "Please enter the length of the shelf (in feet): \n";
    std::cin >> s_len;
    std::cout << "Please enter the depth of the shelf (in feet): \n";
    std::cin >> s_dep;

    std::cout << "Please enter the length of the box (in inch): \n";
    std::cin >> b_len;

    int result = static_cast<long>(((s_len * foot_to_inch) / b_len)) * static_cast<long>(((s_dep * foot_to_inch)/ b_len));

    std::cout << std::format("The shelf can fit {} boxes in a single layer.", result)
              << std::endl;

    return 0;
}