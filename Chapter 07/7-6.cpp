#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <vector>


std::string lowercase(const std::string &str)
{
    std::string result {};

    for (auto i : str)
    {
        result += tolower(i);
    }

    return result;
}


std::vector<std::string> match(std::string &str, std::string &letters)
{
    std::vector<std::string> result {};

    std::string delimiter = " \",.?!";

    std::transform(letters.begin(), letters.end(), letters.begin(), ::tolower);

    size_t start = 0, end = str.find_first_of(delimiter, start);

    while (end != std::string::npos)
    {
        // If two delimiters are consecutive
        if (start == (end - 1))
        {
            start += 1;
            end = str.find_first_of(delimiter, start);
        }

        std::string sub = str.substr(start, end - start);
        std::string l_sub = lowercase(sub);

        for (auto i : letters)
        {
            if (l_sub.starts_with(i))
            {
                result.push_back(sub);
            }
        }

        start = end + 1;
        end = str.find_first_of(delimiter, start);
    }

    return result;
}


inline void print_result(std::vector<std::string> &list)
{
    for (int i = 0, size = list.size(); i < size; ++i)
    {
        std::cout << std::format("{:^10} |", list[i]);

        if (i % 10 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
    }
}


int main(void)
{
    std::string input {};
    std::cout << "Please enter a text string: ";
    std::getline(std::cin, input);

    std::string letter {};
    std::cout << "Please enter a series of characters: ";
    std::getline(std::cin, letter);

    if (input.empty() || letter.empty())
    {
        std::cout << "The input must not be empty."
                  << std::endl;

        return 1;
    }

    std::vector<std::string> result = match(input, letter);

    print_result(result);

    return 0;
}