module animal.cow;

import <format>;


// Return a string containing name - override
std::string Cow::who() const
{
    return std::format("My name is: {}", getName());
}


// Return a string representing the sound the animal make - override
std::string_view Cow::sound() const
{
    return "Moo~~~";
}