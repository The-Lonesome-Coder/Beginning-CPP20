#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>


std::vector<char> char_split(std::string &str)
{
    std::vector<char> result {};

    for (auto i : str)
    {
        if (i == ' ')
        {
            continue;
        }

        result.push_back(i);
    }

    return result;
}


int main(void)
{
    std::string str1 {};
    std::string str2 {};

    std::cout << "Please enter the first string: ";
    std::getline(std::cin, str1);

    std::cout << "Please enter the second string: ";
    std::getline(std::cin, str2);

    if (str1.empty() || str2.empty())
    {
        std::cout << "The input must not be empty"
                  << std::endl;

        return 1;
    }

    std::vector<char> vec1 = char_split(str1);
    std::vector<char> vec2 = char_split(str2);

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    bool result = std::equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());

    if (result)
    {
        std::cout << "The two strings are anagram."
                  << std::endl;
    }
    else if (!result)
    {
        std::cout << "The two strings are not anagram."
                  << std::endl;
    }

    return 0;
}