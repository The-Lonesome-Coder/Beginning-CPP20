#include <format>
#include <iostream>
#include <string>


std::string reverse(std::string &str)
{
    std::string r_str {};

    for (int i = str.length(); i >= 0; --i)
    {
        r_str += str[i];
    }

    return r_str;
}



int main(void)
{
    std::string input {};

    std::cout << "Please enter a string: ";
    std::getline(std::cin, input);

    if (input.empty())
    {
        std::cout << "The input should not be empty."
                  << std::endl;

        return 1;
    }

    input = reverse(input);

    std::cout << input <<std::endl;

    return 0;
}