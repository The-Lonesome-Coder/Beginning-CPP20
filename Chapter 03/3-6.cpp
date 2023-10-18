#include <iostream>
#include <format>

int main()
{
    int first = 0, second = 0;
    std::cout << "Enter two integers: ";
    std::cin >> first >> second;

    first ^= second;
    second ^= first;
    first ^= second;

    std::cout << std::format("In reverse order they are {} and {}.", first, second) << std::endl;
}