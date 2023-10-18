#include <cctype>
#include <format>
#include <iostream>


// Check is vowel of not
bool is_vowel(char letter)
{
    switch (letter)
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
    }

    return false;
}


int main(void)
{
    char letter {};

    std::cout << "Please enter a character: ";
    std::cin >> letter;

    if (std::isalpha(letter))
    {
        std::cout << std::format("The input character is {} vowel. It's {} lowercase. Binary: {:#b}",
                                (is_vowel(letter) ? "a" : "not a"),
                                (islower(letter) ? "a" : "not a"),
                                 letter)
                  << std::endl;
    }
    else
    {
        throw std::out_of_range("The input is not a character.");
    }
}