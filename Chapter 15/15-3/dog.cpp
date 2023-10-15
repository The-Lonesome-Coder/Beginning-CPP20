module animal.dog;

import <format>;


// Return a string representing the sound the animal make - override
std::string_view Dog::sound() const
{
    return "Woof~~~";
}