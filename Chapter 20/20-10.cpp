#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> names {
                                        "Frodo Baggins", "Gandalf the Gray", "Aragon", "Samwise Gamgee", "Peregrin Took",
                                        "Meriadoc Brandybuck", "Gimli", "Legolas Greenleaf", "Boromir"
                                    };

    // Sort the names lexicographically
    std::ranges::sort(names);

    std::cout << "Names sorted lexicographically:" << std::endl;
    for (const auto& name : names)
    {
        std::cout << name << ", ";
    }
    std::cout << std::endl << std::endl;

    // Sort the names by length
    std::ranges::sort(names, std::less<>{}, &std::string::length);

    for (const auto& name : names)
    {
        std::cout << name << ", ";
    }
    std::cout << std::endl << std::endl;


    // Option 2: projection using lambda expression
    std::ranges::sort(names, std::less<>{}, [](const auto& name) { return name.length(); });
    for (const auto& name : names)
    {
        std::cout << name << ", ";
    }
    std::cout << std::endl << std::endl;
}