#include <cctype>
#include <format>
#include <iostream>
#include <string>


// Check for input validity
bool check_integer(std::string input)
{
    bool negative = false;

    if (input.size() == 0 || (input[0] == '-' && input.size() == 1))
    {
        return false;
    }

    int iteration = 0;

    // Negative number
    if (input[0] == '-')
    {
        negative = true;
        iteration = 1;
    }

    for (int i = iteration; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
        {
            return false;
        }
    }

    return true;
}


int main(void)
{
    int total = 0;
    bool stop_flag = false;

    while (stop_flag == false)
    {
        std::string number {};

        std::cout << "Please enter an integer for accumulation: ";
        std::cin >> number;

        if (check_integer(number))
        {
            total += std::stoi(number);
        }
        else
        {
            std::cout << "The input is not an integer." << std::endl;
        }

        char reply {};

        std::cout << "Would you like to enter another integer (y for \"yes\", n for \"no\"): ";
        std::cin >> reply;

        if (std::tolower(reply) == 'n')
        {
            stop_flag = true;
        }
    }

    std::cout << std::format("The total is {}.", total)
              << std::endl;

    return 0;
}