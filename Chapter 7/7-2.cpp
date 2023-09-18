#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>


// Split the input string into a vector, each word is an element
std::vector<std::string> split(std::string &str, const std::string &pattern = " ")
{
    std::vector<std::string> result {};
    std::string::size_type begin = 0, end = str.find(pattern);

    while (end != std::string::npos)
    {
        if (end - begin != 0)
        {
            std::string word = str.substr(begin, end - begin);

            for (int i = 0, size = word.size(); i < size; ++i)
            {
                if (std::ispunct(word[i]))
                {
                    word.erase(i);
                }
            }

            result.push_back(word);
        }

        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length())
    {
        result.push_back(str.substr(begin));
    }

    return result;
}


// Practicing using stringstream to split
std::vector<std::string> ss_split(std::string &str, const char delimiter = ' ')
{
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


// Using map to create a dictionary-like object
std::map<std::string, int> dic(std::vector<std::string> &vec)
{
    std::map<std::string, int> dictionary {};

    for (int i = 0, size = vec.size(); i < size; ++i)
    {
        if (dictionary.contains(vec[i]))
        {
            ++dictionary[vec[i]];
        }
        else
        {
            dictionary.insert({vec[i], 1});
        }
    }

    return dictionary;
}


void print_result(std::map<std::string, int> &mp)
{
    for (auto itr = mp.cbegin(), end = mp.cend(); itr != end; ++itr)
    {
        std::cout << std::format("{:<10} : {:>5}", itr->first, itr->second)
                  << std::endl;

        std::cout << "-----------------------\n";
    }
}


int main(void)
{
    std::string input {};

    std::cout << "Please enter a string: ";
    std::getline(std::cin, input);

    // Check for empty input
    if (input.size() == 0)
    {
        std::cout << "No input received. Program terminated."
                  << std::endl;

        return 1;
    }

    std::vector<std::string> splitString = ss_split(input);

    std::map<std::string, int> mp = dic(splitString);

    print_result(mp);

    return 0;
}