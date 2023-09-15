#include <cctype>
#include <format>
#include <iostream>


int main(void)
{
    int max_char = 1000;

    char string[max_char] {};

    std::cout << "Please enter a string (up to 1000 character): ";
    std::cin.getline(string, max_char);

    int character = 0, size = 0;

    for (int i = 0; string[i] != '\0'; ++i)
    {
        if (std::isalpha(string[i]))
        {
            ++character;
        }
        // Calculate size, strlen() is not safe
        ++size;
    }

    std::cout << std::format("You have entered {} {}.",
                             character,
                             (character > 1 ? "characters" : "character"))
              << std::endl;

    // Print in reverse
    for (int i = size - 1; i >= 0; --i)
    {
        std::cout << string[i];
    }

    std::cout << std::endl;

    return 0;
}