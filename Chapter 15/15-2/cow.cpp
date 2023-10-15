module animal.cow;

import <format>;


// Return a string containing name and weight
std::string Cow::who() const
{
    return std::format("My name is: {}", getName());
}


std::string_view Cow::sound() const
{
    return "Moo~~~";
}