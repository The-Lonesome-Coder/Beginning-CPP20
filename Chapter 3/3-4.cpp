#include <iostream>
#include <format>


int main(void)
{
    unsigned char ch = 0;
    unsigned int packed = 0;

    std::cout << std::format("{:26}", "Enter a character: ");
    std::cin >> ch;
    packed |= ch;

    std::cout << std::format("{:26}", "Enter a second character: ");
    std::cin >> ch;
    packed <<= 8;
    packed |= ch;

    std::cout << std::format("{:26}", "Enter a third character: ");
    std::cin >> ch;
    packed <<= 8;
    packed |= ch;

    std::cout << std::format("{:26}", "Enter a fourth character: ");
    std::cin >> ch;
    packed <<= 8;
    packed |= ch;

    std::cout << std::format("The word containing 4 packed characters is {:#0x}", packed) << std::endl;

    std::cout << "Unpacking the characters again gives (low-order byte first): ";

    // Unpacking
    unsigned int mask {0x00000FF};

    ch = packed & mask;
    std::cout << std::format("{:4}", static_cast<char>(ch));
    ch = (packed >> 8) & mask;
    std::cout << std::format("{:4}", static_cast<char>(ch));
    ch = (packed >> 16) & mask;
    std::cout << std::format("{:4}", static_cast<char>(ch));
    ch = (packed >> 24) & mask;
    std::cout << std::format("{:4}", static_cast<char>(ch))
              << std::endl;
}