module animal.sheep;

import <format>;


// Constructor
Sheep::Sheep(std::string_view name, const unsigned int& weight)
    : Animal { name, weight }, m_woolWeight { static_cast<unsigned int>(weight * 0.1) } {};


Sheep::Sheep(std::string_view name, const unsigned int& weight, const unsigned int& woolWeight)
    : Animal { name, weight }, m_woolWeight { woolWeight } {};


// Getter
unsigned int Sheep::getWoolWeight() const
{
    return m_woolWeight;
}


// Return a string containing name and weight - override
std::string Sheep::who() const
{
    return std::format("My name is: Woolly {}.\nI weight: {}", getName(), getWeight() - getWoolWeight());
}


// Return a string representing the sound the animal make - override
std::string_view Sheep::sound() const
{
    return "Baa~~~";
}