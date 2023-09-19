#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


std::vector<std::string> ss_split(std::string &str, const char delimiter = ' ')
{
    std::vector<std::string> result {};
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}


// Convert whole string to lowercase and return the string
std::string lowercase(const std::string &str)
{
    std::string result {};

    for (auto i : str)
    {
        result += tolower(i);
    }

    return result;
}


std::string replace_all(std::string &str, const std::string &word)
{
    std::vector<std::string> vec = ss_split(str);

    std::string result {};
    std::string rep(word.size(), '*');

    const std::string punctuation = ",;:.\"!?";

    for (auto i : vec)
    {
        if (std::any_of(i.cbegin(), i.cend(), ::ispunct))
        {
            size_t pos = i.find_first_of(punctuation);

            if (lowercase(i.substr(0, pos)) == word)
            {
                result += rep + i.substr(pos);
            }
            else
            {
                result += i;
            }
        }
        else if (lowercase(i) == word)
        {
            result += rep;
        }
        else
        {
            result += i;
        }

        result += ' ';
    }

    return result;
}


int main(void)
{
    std::string input {};

    std::cout << "Please enter a text string: ";
    std::getline(std::cin, input);

    std::string word {};

    std::cout << "Please enter a word: ";
    std::getline(std::cin, word);

    if (input.empty() || word.empty())
    {
        std::cout << "The input must not be empty."
                  << std::endl;

        return 1;
    }

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    std::string result = replace_all(input, word);

    std::cout << result << std::endl;

    return 0;
}