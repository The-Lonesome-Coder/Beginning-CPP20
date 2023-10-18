#include <format>
#include <iostream>


int main(void)
{
    int mice =0, brown = 0, white = 0;

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;

    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;

    std::cout << std::format("You have {} {} in total.\n", mice, (mice == 1 ? "mouse" : "mice"));

    if (mice == 1)
    {
        if (brown == 1)
        {
            std::cout << "It's a brown mouse."
                      << std::endl;
        }
        else if (white == 1)
        {
            std::cout << "It's a white mouse."
                      << std::endl;
        }
    }
    else if (mice > 1)
    {
        std::cout << std::format("Of all these mice, {} are brown {}.", brown, (brown == 1 ? "mouse" : "mice"))
                  << std::endl;
    }

    return 0;
}