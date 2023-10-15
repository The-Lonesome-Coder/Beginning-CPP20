module animal.dog;

import <format>;


std::string Dog::who() const
{
    return std::format("My name is: {}.\nI weight: {}", getName(), getWeight());
}


std::string_view Dog::sound() const
{
    return "Woof~~~";
}