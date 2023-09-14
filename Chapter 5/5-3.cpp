#include <format>
#include <iostream>
#include <string>


int main(void)
{
    std::string input {};

    std::cout << "Please enter a string: ";
    std::getline(std::cin, input);

    int iteration = 0, character = 0;

    do
    {
        if (!std::isspace(input[iteration]))
        {
            ++character;
        }

        ++iteration;
    }
    while (input[iteration] != '#');

    std::cout << std::format("There {} {} {} in the input.",
                             (character > 1 ? "are" : "is"),
                             character,
                             (character > 1 ? "characters" : "character"))
              << std::endl;

    return 0;
}