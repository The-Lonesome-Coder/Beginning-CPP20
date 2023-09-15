#include <cctype>
#include <format>
#include <iostream>


int main(void)
{
    int max_char = 1000;

    char string[max_char] {};

    std::cout << "Please enter a string (up to 1000 character): ";
    std::cin.getline(string, max_char);

    int i = 0, character = 0, size = 0;

    while (string[i] != '\0')
    {
        if (std::isalpha(string[i]))
        {
            ++character;
        }
        // Calculate size, strlen() is not safe
        ++size;
        ++i;
    }

    std::cout << std::format("You have entered {} {}.",
                             character,
                             (character > 1 ? "characters" : "character"))
              << std::endl;

    // Reverse the array
    char r_string[size] {};

    for (int i = size - 1, j = 0; i >= 0; --i, ++j)
    {
        r_string[j] = string[i];
    }

    // Append a null character at the end of the string
    r_string[size + 1] = '\0';

    // Print reverse string
    for (int i = 0; i < size; ++i)
    {
        std::cout << r_string[i];
    }

    std::cout << std::endl;

    return 0;
}