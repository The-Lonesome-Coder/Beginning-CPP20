#include <format>
#include <iostream>
#include <string>
#include <vector>


std::vector<int> extract_int(const std::string &numbers)
{
    std::vector<int> result {};

    const char delimiter = ' ';

    size_t start = 0, end = numbers.find_first_of(delimiter);

    while (end != std::string::npos)
    {
        int num = std::stoi(numbers.substr(start, end - start));

        result.push_back(num);

        start = end + 1;
        end = numbers.find_first_of(delimiter, start);
    }

    return result;
}


inline void print_result(std::vector<int> &list)
{
    for (int i = 0, size = list.size(); i < size; ++i)
    {
        std::cout << std::format("{:^10}|", list[i]);

        if (i % 10 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
    }
}


int main(void)
{
    std::string numbers {};

    std::cout << "Please enter any amount of numbers, separated by spaces, terminated by '#': ";
    std:getline(std::cin, numbers, '#');

    std::vector<int> result = extract_int(numbers);

    print_result(result);

    return 0;
}