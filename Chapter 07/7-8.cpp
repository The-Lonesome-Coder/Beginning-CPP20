#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


// Convert all words to lowercase, then split the string into a vector, neglect punctuations
std::vector<std::string> ss_split(std::string &str, const char delimiter = ' ')
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    std::vector<std::string> result {};
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter))
    {
        if (std::any_of(token.cbegin(), token.cend(), ::ispunct))
        {
            std::string token2 = "";

            for (auto character : token)
            {
                if (!ispunct(character))
                {
                    token2 += character;
                }
            }

            result.push_back(token2);
        }
        else
        {
            result.push_back(token);
        }
    }

    return result;
}


// Allow word for tautogram
bool allow(std::string &str)
{
    std::vector<std::string> allow_list = {"a", "an", "the", "to", "is", "am", "are"};

    for (auto i : allow_list)
    {
        if (str == i)
        {
            return true;
        }
    }

    return false;
}

// Check whether the string is a tautogram
bool tautogram(std::string &str)
{
    std::vector<std::string> words = ss_split(str);

    std::string start {};

    for (int i = 0; start.empty(); ++i)
    {
        if (!allow(words[i]))
        {
            start += words[i][0];
            break;
        }
    }

    for (auto i : words)
    {
        if (!allow(i))
        {
            if (!i.starts_with(start))
            {
                return false;
            }
        }
    }

    return true;
}


int main(void)
{
    std::string input {};

    std::cout << "Please enter a tautogram: ";
    std::getline(std::cin, input);

    if (input.empty())
    {
        std::cout << "The input must not be empty."
                  << std::endl;

        return 1;
    }

    std::cout << std::format("{}", tautogram(input) ? "The input is a tautogram." : "The input is a not tautogram.")
              << std::endl;

    return 0;
}